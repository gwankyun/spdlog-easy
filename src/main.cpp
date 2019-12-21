#include <spdlog_easy/spdlog_easy.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>

int main()
{
    spdlog::easy::set_pattern("[%^%8l%$]");
    spdlog::easy::set_line(3);
    spdlog::easy::init();
    spdlog::set_level(spdlog::level::debug);
    LOG(info);
    LOG(warn, "warn");
    LOG(debug, "{0}", "debug");
    auto logger = spdlog::stderr_color_mt("log");
    LOG(info, logger);
    LOG(warn, logger, "warn");
    LOG(debug, logger, "{0}", "debug");
    return 0;
}
