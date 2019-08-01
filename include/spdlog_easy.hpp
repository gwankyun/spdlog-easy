#pragma once
#ifndef SPDLOG_EASY_HPP
#define SPDLOG_EASY_HPP
#include <spdlog/spdlog.h>
#include <string>
#include <cstddef>
#include <cstdint>

namespace spdlog
{
    namespace easy
    {
        struct config_t
        {
            uint32_t file_size = 15;
            uint32_t func_size = 10;
            uint32_t line_size = 5;
            std::string str;
        };

        inline config_t& get_config()
        {
            static config_t instance;
            return instance;
        }

        constexpr char get_path_separator()
        {
#ifdef _WIN32
            return '\\';
#else
            return '/';
#endif // _WIN32
        }

        inline std::string get_filename(std::string file)
        {
            return file.substr(file.rfind(get_path_separator()) + 1);
        }

        template<typename Arg, typename ...Args>
        void log(spdlog::level::level_enum level, std::string file, std::string func, int line, std::string f, Arg arg, Args&& ...args)
        {
            using namespace std;
            if (spdlog::default_logger_raw()->should_log(level))
            {
                spdlog::default_logger_raw()->force_log(
                    spdlog::source_loc{ file.c_str(), line, func.c_str() },
                    level, f, arg, forward<Args>(args)...);
            }
        }

        template<typename T>
        void log(spdlog::level::level_enum level, std::string file, std::string func, int line, T t)
        {
            log(level, file, func, line, "{0}", t);
        }

        inline void log(spdlog::level::level_enum level, std::string file, std::string func, int line)
        {
            log(level, file, func, line, "{0}", "");
        }

        inline void init()
        {
            auto& config = get_config();
            auto& file_size = config.file_size;
            auto& func_size = config.func_size;
            auto& line_size = config.line_size;
            auto& str = config.str;
            spdlog::set_pattern("[%Y-%m-%d %T.%e] [%^%8l%$] %v");
            str = fmt::format("[{{0:<{0}}}] [{{2:<{2}}}] [{{1:>{1}}}] ",
                file_size, line_size, func_size);
        }
    }
}

#define LOG(_level, ...) \
	spdlog::easy::log(spdlog::level::_level, __FILE__,  __func__, __LINE__, ##__VA_ARGS__)

#endif // !SPDLOG_EASY_HPP
