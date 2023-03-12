#include "cron.h"
#include "cron_api.h"

using namespace cron_gui;

cron::task_collection cron::tasks_;

cron::task_collection& cron::tasks() {
  static bool initialized = false;
  if (!initialized) load();
  initialized = true;
  return tasks_;
}

void cron::load() {
  tasks_.clear();
  for (auto task_api : api::cron::load())
    tasks_.emplace_back(task_api.reboot, task_api.minute, task_api.hour, task_api.day, task_api.month, task_api.day_of_week, task_api.command, task_api.name);
}
