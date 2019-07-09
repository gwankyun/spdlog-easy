#include <spdlog_easy.hpp>

int main()
{
    spdlog::easy::init();
    spdlog::set_level(spdlog::level::debug);
    LOG(info);
    LOG(warn, "warn");
    LOG(debug, "{0}", "debug");
    return 0;
}
