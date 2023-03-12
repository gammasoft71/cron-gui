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
    using task_collection = std::vector<task>;
  public:
    static task_collection& tasks();
    
  private:
    static void load();
    static task_collection tasks_;
  };
}
