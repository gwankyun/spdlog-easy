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

        static config_t& get_config()
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
        void log(spdlog::level::level_enum level, std::string file, std::string func, std::size_t line, std::string f, Arg arg, Args&& ...args)
        {
            using namespace std;
            auto& config = get_config();
            auto& file_size = config.file_size;
            auto& func_size = config.func_size;
            auto& line_size = config.line_size;
            auto& str = config.str;
            auto fmts = fmt::format(str,
                get_filename(file).substr(0, file_size),
                to_string(line).substr(0, line_size),
                func.substr(0, func_size)
            ) + f;
            spdlog::default_logger_raw()->log(level, fmts.c_str(), arg, forward<Args>(args)...);
        }

        template<typename t>
        void log(spdlog::level::level_enum level, std::string file, std::string func, std::size_t line, t t)
        {
            log(level, file, func, line, "{0}", t);
        }

        inline void log(spdlog::level::level_enum level, std::string file, std::string func, std::size_t line)
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
