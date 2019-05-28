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

		inline uint32_t file_size = 20;
		inline uint32_t func_size = 20;
		inline uint32_t line_size = 5;
		inline std::string str;

		template<typename Arg, typename ...Args>
		void log(spdlog::level::level_enum level, std::string file, std::string func, std::size_t line, std::string f, Arg arg, Args&& ...args)
		{
			using namespace std;
			auto fmts = fmt::format(str,
				get_filename(file).substr(0, file_size),
				func.substr(0, func_size),
				to_string(line).substr(0, line_size)
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
			spdlog::set_pattern("[%Y-%m-%d %T.%e] [%^%8l%$] %v");
			str = fmt::format("[{{0:>{0}}}] [{{1:>{1}}}:{{2:>{2}}}] ",
				file_size, func_size, line_size);
		}
	}
}

#define LOG(_level, ...) \
	spdlog::easy::log(spdlog::level::_level, __FILE__,  __func__, __LINE__, ##__VA_ARGS__)

#endif // !SPDLOG_EASY_HPP
