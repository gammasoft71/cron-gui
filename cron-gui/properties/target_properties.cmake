target_default_namespace("cron_gui")
target_icon(resources/cron-gui)
target_name("cron-gui")
target_startup("cron_gui::main_form" src/main_form.h)
