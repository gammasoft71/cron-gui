/// @file
/// @brief Contains main_form class.
#pragma once
#include <xtd/xtd>

/// @brief Represents the namespace that contains application objects.
namespace cron_gui {
  /// @brief Represents the main form.
  class main_form : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the main_form class.
    main_form();

    /// @brief The main entry point for the application.
    static void main();
    
  private:
    void load_tasks();
    void on_create_button_click(xtd::object& sender, const xtd::event_args& e);
    void on_delete_button_click(xtd::object& sender, const xtd::event_args& e);
    void on_edit_button_click(xtd::object& sender, const xtd::event_args& e);
    void on_task_list_box_selected_index_changed(xtd::object& sender, const xtd::event_args& e);
    void save_tasks();

    xtd::forms::panel main_panel_;
    xtd::forms::list_box task_list_box_;
    xtd::forms::panel buttons_panel_;
    xtd::forms::button create_button_;
    xtd::forms::button edit_button_;
    xtd::forms::button delete_button_;
  };
}
