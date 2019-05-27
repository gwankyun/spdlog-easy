#pragma once
#ifndef SPDLOG_EASY
#define SPDLOG_EASY
#include <spdlog/spdlog.h>
#include <string>
#include <cstddef>

#ifdef __cpp_lib_filesystem
#include <filesystem>
#endif // __cpp_lib_filesystem

namespace spdlog
{
	namespace easy
	{
		inline char get_path_separator()
		{
#ifdef _WIN32
			return '\\';
#else
			return '/';
#endif // _WIN32
		}

		inline std::string get_filename(std::string file)
		{
			using namespace std;
#ifdef __cpp_lib_filesystem
			return filesystem::path(file).filename().string();
#endif // __cpp_lib_filesystem

#ifdef BOOST_FILESYSTEM_FILESYSTEM_HPP
			return boost::filesystem::path(file).filename().string();
#endif // BOOST_FILESYSTEM_FILESYSTEM_HPP

			return file.substr(file.rfind(get_path_separator()) + 1);
		}

		template<typename Arg, typename ...Args>
		void log(spdlog::level::level_enum level, std::string file, std::string func, std::size_t line, std::string f, Arg arg, Args&& ...args)
		{
			using namespace std;
			filesystem::path path(file);
			auto fmts = fmt::format("[{0:>20}] [{1:>20}:{2:>5}] ",
				get_filename(file).substr(0, 20),
				func.substr(0, 20),
				to_string(line).substr(0, 5)
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
	}
}

#define LOG(_level, ...) \
	spdlog::easy::log(spdlog::level::_level, __FILE__,  __func__, __LINE__, ##__VA_ARGS__)

#endif // !SPDLOG_EASY
