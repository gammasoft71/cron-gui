#include "task.h"

using namespace std;
using namespace xtd;
using namespace cron_gui;

task::task(bool reboot,optional<uint32> minute, optional<uint32> hour, optional<uint32> day, optional<uint32> month, optional<xtd::day_of_week> day_of_week,  const ustring& command, const ustring& name) : reboot_(reboot), minute_(minute), hour_(hour), day_(day), month_(month), day_of_week_(day_of_week), command_(command), name_(name) {
}

const xtd::ustring& task::command() const noexcept {
  return command_;
}

task& task::command(const xtd::ustring& value) noexcept {
  command_ = value;
  return *this;
}

std::optional<xtd::uint32> task::day() const noexcept {
  return day_;
}

task& task::day(xtd::uint32 value) noexcept {
  day_ = value;
  return *this;
}

task& task::day(nullptr_t) noexcept {
  day_ = std::nullopt;
  return *this;
}

std::optional<xtd::day_of_week> task::day_of_week() const noexcept {
  return day_of_week_;
}

task& task::day_of_week(xtd::day_of_week value) noexcept {
  day_of_week_ = value;
  return *this;
}

task& task::day_of_week(nullptr_t) noexcept {
  day_of_week_ = std::nullopt;
  return *this;
}

std::optional<xtd::uint32> task::hour() const noexcept {
  return hour_;
}

task& task::hour(xtd::uint32 value) noexcept {
  hour_ = value;
  return *this;
}

task& task::hour(nullptr_t) noexcept {
  hour_ = std::nullopt;
  return *this;
}

std::optional<xtd::uint32> task::minute() const noexcept {
  return minute_;
}

task& task::minute(xtd::uint32 value) noexcept {
  minute_ = value;
  return *this;
}

task& task::minute(nullptr_t) noexcept {
  minute_ = std::nullopt;
  return *this;
}

std::optional<xtd::uint32> task::month() const noexcept {
  return month_;
}

task& task::month(xtd::uint32 value) noexcept {
  month_ = value;
  return *this;
}

task& task::month(nullptr_t) noexcept {
  month_ = std::nullopt;
  return *this;
}

const xtd::ustring& task::name() const noexcept {
  return name_;
}

task& task::name(const xtd::ustring& value) noexcept {
  name_ = value;
  return *this;
}

bool task::reboot() const noexcept {
  return reboot_;
}

task& task::reboot(bool value) noexcept {
  reboot_ = value;
  return *this;
}

ustring task::to_cron_raw_string() const noexcept {
  return ustring::format("{} {} #{}", to_cron_time_string(reboot_, minute_, hour_, day_, month_, day_of_week_), command_, name_);
}

ustring task::to_string() const noexcept {
  return ustring::format("task[name={}, command={}, minute={}, hour={}, day={}, month={}, day_of_week={}, reboot={}]", name_, command_, minute_, hour_, day_, month_, day_of_week_.has_value() ? ustring::format("{}", day_of_week_.value()) : "(null)", reboot_);
}

ustring task::to_cron_time_string(bool reboot, optional<uint32> minute, optional<uint32> hour, optional<uint32> day, optional<uint32> month, optional<xtd::day_of_week> day_of_week) noexcept {
  if (reboot) return "@reboot";
  if (minute == 0 && hour == 0 && day == 1 && month == 1 && !day_of_week) return "@yearly";
  if (minute == 0 && hour == 0 && day == 1 && !month && !day_of_week) return "@monthly";
  if (minute == 0 && hour == 0 && !day && !month && day_of_week == xtd::day_of_week::sunday) return "@weekly";
  if (minute == 0 && hour == 0 && !day && !month && !day_of_week) return "@daily";
  if (minute == 0 && !hour && !day && !month && !day_of_week) return "@hourly";
  return ustring::format("{} {} {} {} {}", minute ? std::to_string(minute.value()) : "*", hour ? std::to_string(hour.value()) : "*", day ? std::to_string(day.value()) : "*", month ? std::to_string(month.value()) : "*", day_of_week ? std::to_string(static_cast<uint32>(day_of_week.value())) : "*");
}
