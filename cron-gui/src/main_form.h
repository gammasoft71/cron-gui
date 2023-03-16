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
    /// @cond
    ~main_form();
    /// @endcond
    
    /// @brief The main entry point for the application.
    static void main();
    
  private:
    void load_tasks();
    void on_create_button_click(xtd::object& sender, const xtd::event_args& e);
    void on_delete_button_click(xtd::object& sender, const xtd::event_args& e);
    void on_edit_button_click(xtd::object& sender, const xtd::event_args& e);
    void on_help_abut_menu_item_click(xtd::object& sender, const xtd::event_args& e);
    void on_task_exit_menu_item_click(xtd::object& sender, const xtd::event_args& e);
    void on_task_list_box_selected_index_changed(xtd::object& sender, const xtd::event_args& e);
    void save_tasks();
    
    xtd::forms::about_dialog about_dialog_;
    xtd::forms::menu_item task_create_menu_item_ {"&Create", {*this, &main_form::on_create_button_click}, xtd::forms::menu_images::from_name("list-add"), xtd::forms::shortcut::cmd_n};
    xtd::forms::menu_item task_edit_menu_item_ {"&Edit", {*this, &main_form::on_edit_button_click}, xtd::forms::menu_images::from_name("document-edit"), xtd::forms::shortcut::cmd_o};
    xtd::forms::menu_item task_delete_menu_item_ {"&Delete", {*this, &main_form::on_delete_button_click}, xtd::forms::menu_images::from_name("list-remove"), xtd::forms::shortcut::cmd_del};
    xtd::forms::menu_item task_separator4_menu_item_ {"-"};
    xtd::forms::menu_item task_exit_menu_item_ {xtd::forms::system_texts::exit(), {*this, &main_form::on_task_exit_menu_item_click}, xtd::forms::menu_images::file_exit(), xtd::forms::shortcut::alt_f4};
    xtd::forms::menu_item task_menu_item_ {"&Task", {task_create_menu_item_, task_edit_menu_item_, task_delete_menu_item_, task_separator4_menu_item_, task_exit_menu_item_}};
    xtd::forms::menu_item help_about_menu_item_ {xtd::forms::system_texts::about(), {*this, &main_form::on_help_abut_menu_item_click}, xtd::forms::menu_images::help_about()};
    xtd::forms::menu_item help_menu_item_ {xtd::forms::system_texts::help(), {help_about_menu_item_}};
    xtd::forms::main_menu main_menu_ {task_menu_item_, help_menu_item_};
    xtd::forms::panel main_panel_;
    xtd::forms::list_box task_list_box_;
    xtd::forms::panel buttons_panel_;
    xtd::forms::button create_button_;
    xtd::forms::button delete_button_;
    xtd::forms::button edit_button_;
  };
}
