#if defined(WIN32)

#include "cron_api.h"

using namespace cron_gui;

vector<cron::task> cron::load() {
  auto result = vector<task> {};

  /// @todo load tasks on Windows...

  return result;
}

#endif
