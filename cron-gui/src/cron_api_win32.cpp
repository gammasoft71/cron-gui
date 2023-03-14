#if defined(WIN32)

#include "cron_api.h"

using namespace std;
using namespace cron_gui::api;

vector<cron::task> cron::load() {
  auto result = vector<task> {};

  /// @todo load tasks on Windows...

  return result;
}


void cron::save(const std::vector<task>& tasks) {
  /// @todo save tasks on Windows...
}

#endif
