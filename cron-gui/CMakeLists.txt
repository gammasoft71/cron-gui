cmake_minimum_required(VERSION 3.3)

# Project
project(cron-gui)
find_package(xtd REQUIRED)
add_sources(
  src/cron.h
  src/cron.cpp
  src/cron_api.h
  src/cron_api_unix.cpp
  src/cron_api_win32.cpp
  src/editor_form.h
  src/editor_form.cpp
  src/main_form.h
  src/main_form.cpp
  src/task.h
  src/task.cpp
)
target_type(GUI_APPLICATION)

# Install
install_component()
