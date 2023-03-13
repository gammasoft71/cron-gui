#if !defined(WIN32)

/*
 line format example = "* * * * * echo "hello world" #hello world"
 line format example = "@daily echo "hello world" #hello world"
 
 * * * * * command # name
 │ │ │ │ │ |         |
 │ │ │ │ │ |         \- The name of the command to run
 │ │ │ │ │ \----------- The command to run on specified time and specified date
 │ │ │ │ \------------- day of the week (0 - 6)
 │ │ │ \--------------- month (1 - 12)
 │ │ \----------------- day of the month (1 - 31)
 │ \------------------- hour (0 - 23)
 \--------------------- minute (0 - 59)
 
 Special time specification "nicknames" supported :
 @reboot command # name   : Run once after reboot.
 @yearly command # name   : Run once a year, ie.  "0 0 1 1 *".
 @annually command # name : Run once a year, ie.  "0 0 1 1 *".
 @monthly command # name  : Run once a month, ie. "0 0 1 * *".
 @weekly command # name   : Run once a week, ie.  "0 0 * * 0".
 @daily command # name    : Run once a day, ie.   "0 0 * * *".
 @hourly command # name   : Run once an hour, ie. "0 * * * *".
 
 See :
 * https://linux.die.net/man/5/crontab
 * https://www.geekbitzone.com/posts/macos/crontab/macos-schedule-tasks-with-crontab/
 * https://stackoverflow.com/questions/7195503/setting-up-a-cron-job-in-windows
 */

#include <algorithm>
#include "cron_api.h"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;
using namespace cron_gui::api;

vector<cron::task> cron::load() {
  auto result = vector<task> {};
  using_(auto sr = stream_reader {process::start(process_start_info {"crontab", "-l"}.use_shell_execute(false).redirect_standard_output(true)).standard_output()}) {
    auto lines = sr.read_to_end().split({'\n'});
    for (auto line : lines) {
      auto index = line.find_last_of("#");
      if (index == ustring::npos) continue;
      auto items = line.remove(index - 1).split({' '});
      static auto time_keys = vector<ustring> {"@reboot", "@hourly", "@daily", "@weekly", "@monthly", "@yearly", "@annually"};
      auto time_index = find(time_keys.begin(), time_keys.end(), items[0]) != time_keys.end() ? 1U : 5U;
      if (items.size() < time_index) continue;
      cron::task task;
      task.command = ustring::join(" ", items, time_index);
      task.name = line.substring(index + 1);
      if (items[0] == "@reboot") task.reboot = true;
      else if (items[0] == "@hourly") task.minute = 0;
      else if (items[0] == "@daily") task.minute = task.hour = 0;
      else if (items[0] == "@weekly") {
        task.minute = task.hour = 0;
        task.day_of_week = xtd::day_of_week::sunday;
      } else if (items[0] == "@monthly") {
        task.minute = task.hour = 0;
        task.day = 1;
      } else if (items[0] == "@yearly" || items[0] == "@annually") {
        task.minute = task.hour = 0;
        task.day = task.month = 1;
      } else {
        if (items[0] != "*") task.minute = xtd::parse<uint32>(items[0]);
        if (items[1] != "*") task.hour = xtd::parse<uint32>(items[1]);
        if (items[2] != "*") task.day = xtd::parse<uint32>(items[2]);
        if (items[3] != "*") task.month = xtd::parse<uint32>(items[3]);
        if (items[4] != "*") task.day_of_week = static_cast<xtd::day_of_week>(xtd::parse<uint32>(items[4]));
      }
      result.push_back(task);
    }
  }
  return result;
}

void cron::save(const std::vector<task>& tasks) {
  /// @todo save tasks on Linux and macOS...
}

#endif
