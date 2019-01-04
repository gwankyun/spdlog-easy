#pragma once
#include <spdlog/spdlog.h>
#include <functional>

namespace spdlog
{
	namespace easy
	{
		template<typename Arg, typename ...Args>
		void log(spdlog::level::level_enum level, std::string logger, std::string func, std::size_t line, std::string f, Arg arg, Args&& ...args)
		{
			using namespace std;
			auto logg = spdlog::get(logger);
			if (logg == nullptr)
			{
				return;
			}
			auto fmts = fmt::format("[{0}:{1}] ", func, line) + f;
			logg->log(level, fmts.c_str(), arg, forward<Args>(args)...);
		}

		template<typename T>
		void log(spdlog::level::level_enum level, std::string logger, std::string func, std::size_t line, T t)
		{
			log(level, logger, func, line, "{0}", t);
		}

		inline void log(spdlog::level::level_enum level, std::string logger, std::string func, std::size_t line)
		{
			log(level, logger, func, line, "{0}", "");
		}
	}
}

#define LOG(level, logger, ...) \
	spdlog::easy::log(level, logger, __func__, __LINE__, ##__VA_ARGS__);

#define LOG_INFO(logger, ...) \
	LOG(spdlog::level::level_enum::info, logger, ##__VA_ARGS__);

#define LOG_ERROR(logger, ...) \
	LOG(spdlog::level::level_enum::err, logger, ##__VA_ARGS__);

#define LOG_WARN(logger, ...) \
	LOG(spdlog::level::level_enum::warn, logger, ##__VA_ARGS__);

#define LOG_CRITICAL(logger, ...) \
	LOG(spdlog::level::level_enum::critical, logger, ##__VA_ARGS__);
