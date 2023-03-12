/// @file
/// @brief Contains cron_api class.
#pragma once
#include <tuple>
#include <vector>
#include <xtd/xtd>

/// @brief Represents the namespace that contains application objects.
namespace cron_gui {
  /// @cond
  class cron;
  /// @endcond
  
  namespace api {
    /// @brief Represents the cron api.
    class cron static_ {
      friend cron_gui::cron;
    private:
      struct task {
        bool reboot = false;
        std::optional<xtd::uint32> minute;
        std::optional<xtd::uint32> hour;
        std::optional<xtd::uint32> day;
        std::optional<xtd::uint32> month;
        std::optional<xtd::day_of_week> day_of_week;
        xtd::ustring command;
        xtd::ustring name;
      };
      static std::vector<task> load();
    };
  }
}
