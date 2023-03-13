/// @file
/// @brief Contains cron class.
#pragma once
#include <vector>
#include <xtd/xtd>
#include "task.h"

/// @brief Represents the namespace that contains application objects.
namespace cron_gui {
  /// @brief Represents the cron object.
  class cron static_ {
  public:
    using task_collection = std::vector<task>;

    static const task_collection& tasks();
    static void tasks(const task_collection& value);

  private:
    static void load();
    static void save();
    static task_collection tasks_;
  };
}
