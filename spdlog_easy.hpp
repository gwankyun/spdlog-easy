#pragma once
#include <spdlog/spdlog.h>

namespace spdlog
{
	namespace easy
	{
		template<typename Arg, typename ...Args>
		void info(std::string logger, std::string func, std::size_t line, std::string f, Arg arg, Args&& ...args)
		{
			using namespace std;
			auto log = spdlog::get(logger);
			if (log == nullptr)
			{
				return;
			}
			auto fmts = fmt::format("[{0}:{1}] ", func, line) + f;
			log->info(fmts.c_str(), arg, forward<Args>(args)...);
		}

		template<typename T>
		void info(std::string logger, std::string func, std::size_t line, T t)
		{
			info(logger, func, line, "{0}", t);
		}

		inline void info(std::string logger, std::string func, std::size_t line)
		{
			info(logger, func, line, "{0}", "");
		}

		template<typename Arg, typename ...Args>
		void error(std::string logger, std::string func, std::size_t line, std::string f, Arg arg, Args&& ...args)
		{
			using namespace std;
			auto log = spdlog::get(logger);
			if (log == nullptr)
			{
				return;
			}
			auto fmts = fmt::format("[{0}:{1}] ", func, line) + f;
			log->error(fmts.c_str(), arg, forward<Args>(args)...);
		}

		template<typename T>
		void error(std::string logger, std::string func, std::size_t line, T t)
		{
			error(logger, func, line, "{0}", t);
		}

		inline void error(std::string logger, std::string func, std::size_t line)
		{
			error(logger, func, line, "{0}", "");
		}
	}
}


#define INFO(logger, ...) \
	spdlog::easy::info(logger, __func__, __LINE__, ##__VA_ARGS__);

#define ERROR(logger, ...) \
	spdlog::easy::error(logger, __func__, __LINE__, ##__VA_ARGS__);
