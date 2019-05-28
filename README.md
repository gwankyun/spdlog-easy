# spdlog-easy

用法

```c++
#include <spdlog_easy.hpp>

spdlog::easy::init();
spdlog::set_level(spdlog::level::debug);

LOG(info);
LOG(warn, "warn");
LOG(debug, "{0}", "debug")
```