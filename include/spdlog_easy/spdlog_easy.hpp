#pragma once
#ifndef SPDLOG_EASY_HPP
#define SPDLOG_EASY_HPP
#include "spdlog/spdlog.h"
#include <string>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <type_traits>

namespace spdlog
{
    namespace easy
    {
        struct config_t
        {
            config_t()
            {
                update();
            }

            void update()
            {
                if (pattern.empty())
                {
                    spdlog::set_pattern("[%Y-%m-%d %T.%e] [%^%8l%$] %v");
                }
                else
                {
                    spdlog::set_pattern(pattern + " %v");
                }
                str = fmt::format("[{{0:<{0}}}] [{{1:<{1}}}] [{{2:>{2}}}] ",
                    file_size, func_size, line_size);;
            }

            friend std::string get_file(const std::string& file);
            friend std::string get_func(const std::string& func);
            friend void set_file(uint32_t file_size);
            friend inline void set_func(uint32_t func_size);
            friend void set_pattern(const std::string& pattern);
            friend void set_line(uint32_t line_size);

            std::string get_str()
            {
                return str;
            }

        private:
            uint32_t file_size = 15;
            uint32_t func_size = 10;
            uint32_t line_size = 5;
            std::string pattern;
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

        inline std::string get_filename(const std::string& file)
        {
            return file.substr(file.rfind(get_path_separator()) + 1);
        }
        
        inline std::string get_file(const std::string& file)
        {
			auto&& config = get_config();
			auto&& filename = get_filename(file);
			if (filename.size() <= config.file_size)
			{
				return filename;
			}
			else
			{
				return filename.substr(0, config.file_size);
			}
        }
        
		inline std::string get_func(const std::string& func)
        {
			auto&& config = get_config();
			if (func.size() <= config.func_size)
			{
				return func;
			}
			else
			{
				return func.substr(0, config.func_size);
			}
        }

        template<typename Arg, typename ...Args>
        void log(
            spdlog::level::level_enum level, 
            const char* file, 
            const char* func, 
            int line, 
            std::shared_ptr<spdlog::logger> logger,
            const char* f, 
            Arg arg, 
            Args&& ...args)
        {
            using namespace std;
            if (logger->should_log(level))
            {
				auto&& base = fmt::format(get_config().get_str(), get_file(file), get_func(func), line);
				auto&& str = fmt::format("{0} {1}", base, f);
				logger->log(level, str, arg, forward<Args>(args)...);
            }
        }

        template<typename Arg, typename ...Args>
        void log(
            spdlog::level::level_enum level, 
            const char* file, 
            const char* func, 
            int line, 
            const char* f, 
            Arg arg, 
            Args&& ...args)
        {
            using namespace std;
            auto&& logger = spdlog::default_logger();
            log(level, file, func, line, logger, f, arg, forward<Args>(args)...);
        }

        template<typename T>
        void log(
            spdlog::level::level_enum level, 
            const char* file, 
            const char* func, 
            int line, 
            std::shared_ptr<spdlog::logger> logger,
            T t)
        {
            log(level, file, func, line, logger, "{0}", t);
        }

        template<typename T>
        void log(
            spdlog::level::level_enum level, 
            const char* file, 
            const char* func, 
            int line, 
            T t)
        {
            auto&& logger = spdlog::default_logger();
            log(level, file, func, line, logger, "{0}", t);
        }

        inline void log(
            spdlog::level::level_enum level, 
            const char* file, 
            const char* func, 
            int line,
            std::shared_ptr<spdlog::logger> logger)
        {
            log(level, file, func, line, logger, "{0}", "");
        }

        inline void log(
            spdlog::level::level_enum level, 
            const char* file, 
            const char* func, 
            int line)
        {
            auto&& logger = spdlog::default_logger();
            log(level, file, func, line, logger, "{0}", "");
        }

        inline void set_pattern(const std::string& pattern)
        {
            get_config().pattern = pattern;
        }

        inline void set_file(uint32_t file_size)
        {
            get_config().file_size = file_size;
        }

        inline void set_func(uint32_t func_size)
        {
            get_config().func_size = func_size;
        }

        inline void set_line(uint32_t line_size)
        {
            get_config().line_size = line_size;
        }

        inline void config()
        {
            get_config().update();
        }
    }
}

#define LOG(_level, ...) \
	spdlog::easy::log(spdlog::level::_level, __FILE__,  __func__, __LINE__, ##__VA_ARGS__)

#endif // !SPDLOG_EASY_HPP
