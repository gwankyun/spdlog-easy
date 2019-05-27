# spdlog-easy

用法

```c++
#include <spdlog_easy.hpp>

spdlog::set_pattern("[%Y-%m-%d %T.%e] [%^%8l%$] %v");
spdlog::set_level(spdlog::level::debug);
LOG(debug);
LOG(debug, "hello");
LOG(debug, "{0}", "world");
```