#include "main_form.h"
#include "cron.h"
#include "editor_form.h"
#include "../properties/resources.h"
#include "../properties/settings.h"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;
using namespace cron_gui;

main_form::main_form() {
  start_position(form_start_position::manual);
  client_size(properties::settings::default_settings().client_size());
  controls().push_back_range({main_panel_, buttons_panel_});
  icon(properties::resources::cron_gui_ico());
  location(properties::settings::default_settings().location());
  text("Cron");

  buttons_panel_.controls().push_back_range({delete_button_, edit_button_, create_button_});
  buttons_panel_.dock(dock_style::bottom);
  buttons_panel_.padding(10);
  buttons_panel_.height(50);
  
  main_panel_.controls().push_back_range({task_list_box_});
  main_panel_.dock(dock_style::fill);
  
  task_list_box_.dock(dock_style::fill);
  task_list_box_.selected_index_changed += event_handler {*this, &main_form::on_task_list_box_selected_index_changed};
  task_list_box_.double_click += event_handler {*this, &main_form::on_edit_button_click};
  
  create_button_.dock(dock_style::right);
  create_button_.image(button_images::add());
  create_button_.image_align(content_alignment::middle_left);
  create_button_.text("Create");
  create_button_.width(90);
  create_button_.click += event_handler {*this, &main_form::on_create_button_click};

  edit_button_.dock(dock_style::right);
  edit_button_.enabled(false);
  edit_button_.image(button_images::from_name("document-edit"));
  edit_button_.image_align(content_alignment::middle_left);
  edit_button_.text("Edit");
  edit_button_.width(90);
  edit_button_.click += event_handler {*this, &main_form::on_edit_button_click};
  
  delete_button_.dock(dock_style::right);
  delete_button_.enabled(false);
  delete_button_.image(button_images::remove());
  delete_button_.image_align(content_alignment::middle_left);
  delete_button_.text("Delete");
  delete_button_.width(90);
  delete_button_.click += event_handler {*this, &main_form::on_delete_button_click};

  load_tasks();
}

main_form::~main_form() {
  properties::settings::default_settings().client_size(client_size());
  properties::settings::default_settings().location(location());
  properties::settings::default_settings().save();
}

void main_form::main() {
  xtd::forms::debug_form debug_form;
  application::run(main_form());
}

void main_form::load_tasks() {
  for (auto task : cron::tasks()) {
    task_list_box_.items().push_back({task.name(), task});
    debug::write_line("{} ==> {}", task.to_cron_raw_string(), task);
  }
  if (!task_list_box_.items().empty()) task_list_box_.selected_index(0);
}

void main_form::on_create_button_click(object& sender, const event_args& e) {
  auto task = cron_gui::task();
  debug::write_line("Create new task");
  editor_form editor;
  editor.task(task);
  if (editor.show_sheet_dialog(*this) == forms::dialog_result::cancel) return;
  task = editor.task();
  debug::write_line("Save {}", task);
  task_list_box_.items().push_back({task.name(), task});
  task_list_box_.selected_index(task_list_box_.items().size() - 1);
  save_tasks();
}

void main_form::on_delete_button_click(object& sender, const event_args& e) {
  if (task_list_box_.selected_index() == task_list_box_.npos) return;
  auto selected_index = task_list_box_.selected_index();
  task_list_box_.items().erase_at(selected_index);
  task_list_box_.selected_index(task_list_box_.npos);
  if (selected_index < task_list_box_.items().size()) task_list_box_.selected_index(selected_index);
  else if (task_list_box_.items().size()) task_list_box_.selected_index(task_list_box_.items().size() - 1);
  save_tasks();
}

void main_form::on_edit_button_click(object& sender, const event_args& e) {
  if (task_list_box_.selected_index() == task_list_box_.npos) return;
  auto task = as<cron_gui::task>(task_list_box_.items()[task_list_box_.selected_index()].tag());
  debug::write_line("Edit task ==> {}", task);
  editor_form editor;
  editor.task(task);
  if (editor.show_sheet_dialog(*this) == forms::dialog_result::cancel) return;
  task = editor.task();
  debug::write_line("Save {}", task);
  task_list_box_.items()[task_list_box_.selected_index()] = {task.name(), task};
  save_tasks();
}

void main_form::on_task_list_box_selected_index_changed(object& sender, const event_args& e) {
  delete_button_.enabled(task_list_box_.selected_index() != task_list_box_.npos);
  edit_button_.enabled(task_list_box_.selected_index() != task_list_box_.npos);
}

void main_form::save_tasks() {
  auto tasks = cron::task_collection {};
  for (auto task : task_list_box_.items()) {
    tasks.push_back(as<cron_gui::task>(task.tag()));
  }
  cron::tasks(tasks);
}

