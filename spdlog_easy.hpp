#pragma once
#include <spdlog/spdlog.h>
#include <string>
#include <cstddef>
#include <filesystem>

namespace spdlog
{
    namespace easy
    {
		template<typename Arg, typename ...Args>
		void log(spdlog::level::level_enum level, std::string file, std::string func, std::size_t line, std::string f, Arg arg, Args&& ...args)
		{
			using namespace std;
			filesystem::path path(file);
			auto fmts = fmt::format("[{0:>20}] [{1:>20}:{2:>5}] ",
				path.filename().string().substr(0, 20),
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
