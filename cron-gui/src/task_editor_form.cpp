#include "task_editor_form.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace cron_gui;

task_editor_form::task_editor_form() {
  accept_button(save_button_);
  cancel_button(cancel_button_);
  client_size({565, 410});
  controls().push_back_range({main_panel_, buttons_panel_});
  form_border_style(forms::form_border_style::fixed_dialog);
  maximize_box(false);
  minimize_box(false);
  start_position(form_start_position::center_parent);
  text("Task editor");
  
  buttons_panel_.controls().push_back_range({cancel_button_, save_button_});
  buttons_panel_.border_sides(forms::border_sides::top);
  buttons_panel_.border_style(forms::border_style::inset);
  buttons_panel_.dock(dock_style::bottom);
  buttons_panel_.padding(10);
  buttons_panel_.height(50);
  
  cancel_button_.dialog_result(forms::dialog_result::cancel);
  cancel_button_.dock(dock_style::right);
  cancel_button_.text("&Cancel");
  cancel_button_.width(90);
  
  save_button_.dialog_result(forms::dialog_result::ok);
  save_button_.dock(dock_style::right);
  save_button_.text("&Save");
  save_button_.width(90);
  save_button_.click += {*this, &task_editor_form::on_save_button_click};

  main_panel_.controls().push_back_range({name_label_, name_text_box_, command_label_, command_text_box_, command_open_file_dialog_button_, special_label_, reboot_radio_button_, hourly_radio_button_, dayly_radio_button_, weekly_radio_button_, monthly_radio_button_, yearly_radio_button_, custom_radio_button_, time_label_, minute_label_, hour_label_, day_label_, month_label_, day_of_week_label_, minute_choice_, hour_choice_, day_choice_, month_choice_, day_of_week_choice_});
  main_panel_.dock(dock_style::fill);
  
  name_label_.auto_size(true);
  name_label_.location({20, 20});
  name_label_.text("Name");
  
  name_text_box_.location({20, 50});
  name_text_box_.width(525);
  name_text_box_.text_changed += {*this, &task_editor_form::on_name_text_box_text_changed};
  
  command_label_.auto_size(true);
  command_label_.location({20, 100});
  command_label_.text("Command");
  
  command_text_box_.location({20, 130});
  command_text_box_.width(440);
  command_text_box_.text_changed += {*this, &task_editor_form::on_command_text_box_text_changed};

  command_open_file_dialog_button_.location({470, 130});
  command_open_file_dialog_button_.text("...");
  command_open_file_dialog_button_.click += {*this, &task_editor_form::on_command_open_file_dialog_button_click};

  special_label_.auto_size(true);
  special_label_.location({20, 180});
  special_label_.text("Special");

  reboot_radio_button_.appearance(forms::appearance::button);
  reboot_radio_button_.checked(true);
  reboot_radio_button_.flat_appearance(flat_button_appearance().border_color(application::style_sheet().system_colors().control_text()).border_size(1).mouse_down_back_color(application::style_sheet().system_colors().accent()));
  reboot_radio_button_.flat_style(xtd::forms::flat_style::flat);
  reboot_radio_button_.location({20, 210});
  reboot_radio_button_.text("Reboot");
  reboot_radio_button_.text_align(content_alignment::middle_center);
  reboot_radio_button_.width(75);
  reboot_radio_button_.checked_changed += {*this, &task_editor_form::on_reboot_radio_button_checked_changed};

  hourly_radio_button_.appearance(forms::appearance::button);
  hourly_radio_button_.flat_appearance(flat_button_appearance().border_color(application::style_sheet().system_colors().control_text()).border_size(1).mouse_down_back_color(application::style_sheet().system_colors().accent()));
  hourly_radio_button_.flat_style(xtd::forms::flat_style::flat);
  hourly_radio_button_.location({95, 210});
  hourly_radio_button_.text("Hourly");
  hourly_radio_button_.text_align(content_alignment::middle_center);
  hourly_radio_button_.width(75);
  hourly_radio_button_.checked_changed += {*this, &task_editor_form::on_hourly_radio_button_checked_changed};

  dayly_radio_button_.appearance(forms::appearance::button);
  dayly_radio_button_.flat_appearance(flat_button_appearance().border_color(application::style_sheet().system_colors().control_text()).border_size(1).mouse_down_back_color(application::style_sheet().system_colors().accent()));
  dayly_radio_button_.flat_style(xtd::forms::flat_style::flat);
  dayly_radio_button_.location({170, 210});
  dayly_radio_button_.text("Dayly");
  dayly_radio_button_.text_align(content_alignment::middle_center);
  dayly_radio_button_.width(75);
  dayly_radio_button_.checked_changed += {*this, &task_editor_form::on_dayly_radio_button_checked_changed};

  weekly_radio_button_.appearance(forms::appearance::button);
  weekly_radio_button_.flat_appearance(flat_button_appearance().border_color(application::style_sheet().system_colors().control_text()).border_size(1).mouse_down_back_color(application::style_sheet().system_colors().accent()));
  weekly_radio_button_.flat_style(xtd::forms::flat_style::flat);
  weekly_radio_button_.location({245, 210});
  weekly_radio_button_.text("Weekly");
  weekly_radio_button_.text_align(content_alignment::middle_center);
  weekly_radio_button_.width(75);
  weekly_radio_button_.checked_changed += {*this, &task_editor_form::on_weekly_radio_button_checked_changed};

  monthly_radio_button_.appearance(forms::appearance::button);
  monthly_radio_button_.flat_appearance(flat_button_appearance().border_color(application::style_sheet().system_colors().control_text()).border_size(1).mouse_down_back_color(application::style_sheet().system_colors().accent()));
  monthly_radio_button_.flat_style(xtd::forms::flat_style::flat);
  monthly_radio_button_.location({320, 210});
  monthly_radio_button_.text("Monthly");
  monthly_radio_button_.text_align(content_alignment::middle_center);
  monthly_radio_button_.width(75);
  monthly_radio_button_.checked_changed += {*this, &task_editor_form::on_monthly_radio_button_checked_changed};

  yearly_radio_button_.appearance(forms::appearance::button);
  yearly_radio_button_.flat_appearance(flat_button_appearance().border_color(application::style_sheet().system_colors().control_text()).border_size(1).mouse_down_back_color(application::style_sheet().system_colors().accent()));
  yearly_radio_button_.flat_style(xtd::forms::flat_style::flat);
  yearly_radio_button_.location({395, 210});
  yearly_radio_button_.text("Yearly");
  yearly_radio_button_.text_align(content_alignment::middle_center);
  yearly_radio_button_.width(75);
  yearly_radio_button_.checked_changed += {*this, &task_editor_form::on_yearly_radio_button_checked_changed};

  custom_radio_button_.appearance(forms::appearance::button);
  custom_radio_button_.flat_appearance(flat_button_appearance().border_color(application::style_sheet().system_colors().control_text()).border_size(1).mouse_down_back_color(application::style_sheet().system_colors().accent()));
  custom_radio_button_.flat_style(xtd::forms::flat_style::flat);
  custom_radio_button_.location({470, 210});
  custom_radio_button_.text("Custom");
  custom_radio_button_.text_align(content_alignment::middle_center);
  custom_radio_button_.width(75);
  custom_radio_button_.checked_changed += {*this, &task_editor_form::on_custom_radio_button_checked_changed};

  time_label_.auto_size(true);
  time_label_.location({20, 260});
  time_label_.text("Every");

  minute_label_.auto_size(true);
  minute_label_.location({20, 290});
  minute_label_.text("Minute");
  
  hour_label_.auto_size(true);
  hour_label_.location({105, 290});
  hour_label_.text("Hour");
  
  day_label_.auto_size(true);
  day_label_.location({190, 290});
  day_label_.text("Day");
  
  month_label_.auto_size(true);
  month_label_.location({275, 290});
  month_label_.text("Month");
  
  day_of_week_label_.auto_size(true);
  day_of_week_label_.location({415, 290});
  day_of_week_label_.text("Day of week");
  
  minute_choice_.auto_size(true);
  minute_choice_.location({20, 310});
  minute_choice_.items().push_back("-");
  for (auto minute = 0; minute < 60; ++minute)
    minute_choice_.items().push_back(ustring::format("{}",minute));
  minute_choice_.width(75);
  minute_choice_.selected_index(0);

  hour_choice_.auto_size(true);
  hour_choice_.location({105, 310});
  hour_choice_.items().push_back("-");
  for (auto hour = 0; hour < 24; ++hour)
    hour_choice_.items().push_back(ustring::format("{}",hour));
  hour_choice_.width(75);
  hour_choice_.selected_index(0);
  
  day_choice_.auto_size(true);
  day_choice_.location({190, 310});
  day_choice_.items().push_back("-");
  for (auto day = 1; day < 32; ++day)
    day_choice_.items().push_back(ustring::format("{}",day));
  day_choice_.width(75);
  day_choice_.selected_index(0);
  
  month_choice_.auto_size(true);
  month_choice_.location({275, 310});
  month_choice_.items().push_back_range({"-", "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"});
  month_choice_.width(130);
  month_choice_.selected_index(0);
  
  day_of_week_choice_.auto_size(true);
  day_of_week_choice_.location({415, 310});
  day_of_week_choice_.items().push_back_range({"-", "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"});
  day_of_week_choice_.width(130);
  day_of_week_choice_.selected_index(0);

  name_text_box_.focus();

  on_load_task();
}

const cron_gui::task& task_editor_form::task() const noexcept {
  return task_;
}

task_editor_form& task_editor_form::task(const cron_gui::task& value) noexcept {
  if (task_ != value) {
    task_ = value;
    on_load_task();
  }
  return *this;
}

void task_editor_form::on_command_open_file_dialog_button_click(xtd::object& sender, const xtd::event_args& e) {
  open_file_dialog dialog;
  dialog.initial_directory(!command_text_box_.text().empty() ? io::path::get_directory_name(command_text_box_.text()) : environment::get_folder_path(environment::special_folder::desktop));
  if (!command_text_box_.text().empty()) dialog.file_name(io::path::get_file_name(command_text_box_.text()));
  if (dialog.show_sheet_dialog(*this) != forms::dialog_result::ok) return;
  command_text_box_.text(dialog.file_name());
}

void task_editor_form::on_command_text_box_text_changed(xtd::object& sender, const xtd::event_args& e) {
  task_.command(command_text_box_.text());
  on_update_task();
}

void task_editor_form::on_custom_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e) {
  if (!custom_radio_button_.checked()) return;
  task_.reboot(false);
  task_.minute(nullptr);
  task_.hour(nullptr);
  task_.day(nullptr);
  task_.month(nullptr);
  task_.day_of_week(nullptr);
  on_update_task();
}

void task_editor_form::on_dayly_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e) {
  if (!dayly_radio_button_.checked()) return;
  task_.reboot(false);
  task_.minute(0U);
  task_.hour(0U);
  task_.day(nullptr);
  task_.month(nullptr);
  task_.day_of_week(nullptr);
  on_update_task();
}

void task_editor_form::on_hourly_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e) {
  if (!hourly_radio_button_.checked()) return;
  task_.reboot(false);
  task_.minute(0U);
  task_.hour(nullptr);
  task_.day(nullptr);
  task_.month(nullptr);
  task_.day_of_week(nullptr);
  on_update_task();
}

void task_editor_form::on_load_task() {
  on_update_task();
}

void task_editor_form::on_monthly_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e) {
  if (!monthly_radio_button_.checked()) return;
  task_.reboot(false);
  task_.minute(0U);
  task_.hour(0U);
  task_.day(1U);
  task_.month(nullptr);
  task_.day_of_week(nullptr);
  on_update_task();
}

void task_editor_form::on_name_text_box_text_changed(xtd::object& sender, const xtd::event_args& e) {
  task_.name(name_text_box_.text());
  on_update_task();
}

void task_editor_form::on_reboot_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e) {
  if (!reboot_radio_button_.checked()) return;
  task_.reboot(true);
  task_.minute(nullptr);
  task_.hour(nullptr);
  task_.day(nullptr);
  task_.month(nullptr);
  task_.day_of_week(nullptr);
  on_update_task();
}

void task_editor_form::on_save_button_click(xtd::object& sender, const xtd::event_args& e) {
  on_save_task();
}

void task_editor_form::on_save_task() {
  task_.name(name_text_box_.text());
  task_.command(command_text_box_.text());
  task_.reboot(reboot_radio_button_.checked());
  if (minute_choice_.selected_index() != minute_choice_.npos && minute_choice_.selected_index() > 0U) task_.minute(as<uint32>(minute_choice_.selected_index() - 1));
  else task_.minute(nullptr);
  if (hour_choice_.selected_index() != hour_choice_.npos && hour_choice_.selected_index() > 0U) task_.hour(as<uint32>(hour_choice_.selected_index() - 1));
  else task_.hour(nullptr);
  if (day_choice_.selected_index() != day_choice_.npos && day_choice_.selected_index() > 0U) task_.day(as<uint32>(day_choice_.selected_index()));
  else task_.day(nullptr);
  if (month_choice_.selected_index() != month_choice_.npos && month_choice_.selected_index() > 0U) task_.month(as<uint32>(month_choice_.selected_index()));
  else task_.month(nullptr);
  if (day_of_week_choice_.selected_index() != day_of_week_choice_.npos && day_of_week_choice_.selected_index() > 0U) task_.day_of_week(as<xtd::day_of_week>(day_of_week_choice_.selected_index() - 1));
  else task_.day_of_week(nullptr);
}

void task_editor_form::on_update_task() {
  name_text_box_.text(task_.name());
  command_text_box_.text(task_.command());
  
  if (task_.reboot()) reboot_radio_button_.checked(true);
  else if (task_.minute() == 0 && !task_.hour() && !task_.day() && !task_.month() && !task_.day_of_week()) hourly_radio_button_.checked(true);
  else if (task_.minute() == 0 && task_.hour() == 0 && !task_.day() && !task_.month() && !task_.day_of_week()) dayly_radio_button_.checked(true);
  else if (task_.minute() == 0 && task_.hour() == 0 && !task_.day() && !task_.month() && task_.day_of_week() == xtd::day_of_week::sunday) weekly_radio_button_.checked(true);
  else if (task_.minute() == 0 && task_.hour() == 0 && task_.day() == 1 && !task_.month() && !task_.day_of_week()) monthly_radio_button_.checked(true);
  else if (task_.minute() == 0 && task_.hour() == 0 && task_.day() == 1 && task_.month() == 1 && !task_.day_of_week()) yearly_radio_button_.checked(true);
  else custom_radio_button_.checked(true);
  
  minute_choice_.selected_index(!task_.minute() ? 0U : task_.minute().value() + 1U);
  hour_choice_.selected_index(!task_.hour() ? 0U : task_.hour().value() + 1U);
  day_choice_.selected_index(!task_.day() ? 0U : task_.day().value());
  month_choice_.selected_index(!task_.month() ? 0U : task_.month().value());
  day_of_week_choice_.selected_index(!task_.day_of_week() ? 0U : as<uint32>(task_.day_of_week().value()) + 1U);
}

void task_editor_form::on_weekly_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e) {
  if (!weekly_radio_button_.checked()) return;
  task_.reboot(false);
  task_.minute(0U);
  task_.hour(0U);
  task_.day(nullptr);
  task_.month(nullptr);
  task_.day_of_week(xtd::day_of_week::sunday);
  on_update_task();
}

void task_editor_form::on_yearly_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e) {
  if (!yearly_radio_button_.checked()) return;
  task_.reboot(false);
  task_.minute(0U);
  task_.hour(0U);
  task_.day(1U);
  task_.month(1U);
  task_.day_of_week(nullptr);
  on_update_task();
}
