# spdlog-easy

CMake

```cmake
set(Spdlog_easy_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
find_package(Spdlog_easy)
if(Spdlog_easy_FOUND)
    cmake_print_variables(Spdlog_easy_INCLUDE_DIR)
endif()
```

用法

```c++
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog_easy.hpp>

spdlog::easy::init();
spdlog::set_level(spdlog::level::debug);

LOG(info);
LOG(warn, "warn");
LOG(debug, "{0}", "debug")
auto logger = spdlog::stderr_color_mt("log");
LOG(info, logger);
LOG(warn, logger, "warn");
LOG(debug, logger, "{0}", "debug");
```

