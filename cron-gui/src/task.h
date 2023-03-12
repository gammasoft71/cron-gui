/// @file
/// @brief Contains cron class.
#pragma once
#include <optional>
#include <xtd/xtd>

/// @brief Represents the namespace that contains application objects.
namespace cron_gui {
  /// @brief Represents the task object.
  class task  : public xtd::object {
  public:
    /// @name Constructors

    /// @{
    task(bool reboot, std::optional<xtd::uint32> hour, std::optional<xtd::uint32> minute, std::optional<xtd::uint32> day, std::optional<xtd::uint32> month, std::optional<xtd::day_of_week> day_of_week, const xtd::ustring& command, const xtd::ustring& name);
    /// @}

    /// @cond
    task() = default;
    task(task&&) = default;
    task(const task&) = default;
    task& operator =(const task&) = default;
    /// @endcond

    /// @name Properties
    
    /// @{
    const xtd::ustring& command() const noexcept;
    task& command(const xtd::ustring& value) noexcept;

    std::optional<xtd::uint32> day() const noexcept;
    task& day(xtd::uint32 value) noexcept;
    task& day(std::nullptr_t) noexcept;

    std::optional<xtd::day_of_week> day_of_week() const noexcept;
    task& day_of_week(xtd::day_of_week value) noexcept;
    task& day_of_week(std::nullptr_t) noexcept;

    std::optional<xtd::uint32> hour() const noexcept;
    task& hour(xtd::uint32 value) noexcept;
    task& hour(std::nullptr_t) noexcept;

    std::optional<xtd::uint32> minute() const noexcept;
    task& minute(xtd::uint32 value) noexcept;
    task& minute(std::nullptr_t) noexcept;

    std::optional<xtd::uint32> month() const noexcept;
    task& month(xtd::uint32 value) noexcept;
    task& month(std::nullptr_t) noexcept;

    const xtd::ustring& name() const noexcept;
    task& name(const xtd::ustring& value) noexcept;

    bool reboot() const noexcept;
    task& reboot(bool value) noexcept;
    /// @}
    
    /// @name Methods

    xtd::ustring to_cron_raw_string() const noexcept;
    xtd::ustring to_string() const noexcept override;
    /// @}

  private:
    static xtd::ustring to_cron_time_string(bool reboot, std::optional<xtd::uint32> minute, std::optional<xtd::uint32> hour, std::optional<xtd::uint32> day, std::optional<xtd::uint32> month, std::optional<xtd::day_of_week> day_of_week) noexcept;
    bool reboot_;
    std::optional<xtd::uint32> minute_;
    std::optional<xtd::uint32> hour_;
    std::optional<xtd::uint32> day_;
    std::optional<xtd::uint32> month_;
    std::optional<xtd::day_of_week> day_of_week_;
    xtd::ustring command_;
    xtd::ustring name_;
  };
}
