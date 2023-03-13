#include "cron.h"
#include "cron_api.h"

using namespace std;
using namespace cron_gui;

cron::task_collection cron::tasks_;

const cron::task_collection& cron::tasks() {
  load();
  return tasks_;
}

void cron::tasks(const cron::task_collection& value) {
  tasks_ = value;
  save();
}

void cron::load() {
  tasks_.clear();
  for (auto task_api : api::cron::load())
    tasks_.emplace_back(task_api.reboot, task_api.minute, task_api.hour, task_api.day, task_api.month, task_api.day_of_week, task_api.command, task_api.name);
}

void cron::save() {
  auto tasks = vector<api::cron::task> {};
  for (auto task : tasks_)
    tasks.push_back({task.reboot(), task.minute(), task.hour(), task.day(), task.month(), task.day_of_week(), task.command(), task.name()});
  api::cron::save(tasks);
}
