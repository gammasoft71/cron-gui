/// @file
/// @brief Contains editor_form class.
#pragma once
#include <xtd/xtd>
#include "task.h"

/// @brief Represents the namespace that contains application objects.
namespace cron_gui {
  /// @brief Represents the editor form.
  class task_editor_form : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the editor_form class.
    task_editor_form();
    
    const cron_gui::task& task() const noexcept;
    task_editor_form& task(const cron_gui::task& value) noexcept;

  private:
    void on_command_open_file_dialog_button_click(xtd::object& sender, const xtd::event_args& e);
    void on_command_text_box_text_changed(xtd::object& sender, const xtd::event_args& e);
    void on_custom_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e);
    void on_dayly_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e);
    void on_hourly_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e);
    void on_load_task();
    void on_monthly_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e);
    void on_name_text_box_text_changed(xtd::object& sender, const xtd::event_args& e);
    void on_reboot_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e);
    void on_save_button_click(xtd::object& sender, const xtd::event_args& e);
    void on_save_task();
    void on_update_task();
    void on_weekly_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e);
    void on_yearly_radio_button_checked_changed(xtd::object& sender, const xtd::event_args& e);

    xtd::forms::panel buttons_panel_;
    xtd::forms::button cancel_button_;
    xtd::forms::button save_button_;
    xtd::forms::panel main_panel_;
    xtd::forms::label name_label_;
    xtd::forms::text_box name_text_box_;
    xtd::forms::label command_label_;
    xtd::forms::text_box command_text_box_;
    xtd::forms::button command_open_file_dialog_button_;
    xtd::forms::label special_label_;
    xtd::forms::radio_button hourly_radio_button_;
    xtd::forms::radio_button dayly_radio_button_;
    xtd::forms::radio_button weekly_radio_button_;
    xtd::forms::radio_button monthly_radio_button_;
    xtd::forms::radio_button yearly_radio_button_;
    xtd::forms::radio_button reboot_radio_button_;
    xtd::forms::radio_button custom_radio_button_;
    xtd::forms::label time_label_;
    xtd::forms::label minute_label_;
    xtd::forms::label hour_label_;
    xtd::forms::label day_label_;
    xtd::forms::label month_label_;
    xtd::forms::label day_of_week_label_;
    xtd::forms::choice minute_choice_;
    xtd::forms::choice hour_choice_;
    xtd::forms::choice day_choice_;
    xtd::forms::choice month_choice_;
    xtd::forms::choice day_of_week_choice_;
    cron_gui::task task_;
  };
}
