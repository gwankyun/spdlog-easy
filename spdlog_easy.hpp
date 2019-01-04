#pragma once
#include <spdlog/spdlog.h>
#include <functional>

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

		template<typename Arg, typename ...Args>
		void warn(std::string logger, std::string func, std::size_t line, std::string f, Arg arg, Args&& ...args)
		{
			using namespace std;
			auto log = spdlog::get(logger);
			if (log == nullptr)
			{
				return;
			}
			auto fmts = fmt::format("[{0}:{1}] ", func, line) + f;
			log->warn(fmts.c_str(), arg, forward<Args>(args)...);
		}

		template<typename T>
		void warn(std::string logger, std::string func, std::size_t line, T t)
		{
			warn(logger, func, line, "{0}", t);
		}

		inline void warn(std::string logger, std::string func, std::size_t line)
		{
			warn(logger, func, line, "{0}", "");
		}

		template<typename Arg, typename ...Args>
		void critical(std::string logger, std::string func, std::size_t line, std::string f, Arg arg, Args&& ...args)
		{
			using namespace std;
			auto log = spdlog::get(logger);
			if (log == nullptr)
			{
				return;
			}
			auto fmts = fmt::format("[{0}:{1}] ", func, line) + f;
			log->critical(fmts.c_str(), arg, forward<Args>(args)...);
		}

		template<typename T>
		void critical(std::string logger, std::string func, std::size_t line, T t)
		{
			critical(logger, func, line, "{0}", t);
		}

		inline void critical(std::string logger, std::string func, std::size_t line)
		{
			warn(logger, func, line, "{0}", "");
		}

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


#define LOG_INFO(logger, ...) \
	spdlog::easy::info(logger, __func__, __LINE__, ##__VA_ARGS__);

#define LOG_ERROR(logger, ...) \
	spdlog::easy::error(logger, __func__, __LINE__, ##__VA_ARGS__);

#define LOG_WARN(logger, ...) \
	spdlog::easy::warn(logger, __func__, __LINE__, ##__VA_ARGS__);

#define LOG_CRITICAL(logger, ...) \
	spdlog::easy::critical(logger, __func__, __LINE__, ##__VA_ARGS__);

#define LOG(level, logger, ...) \
	spdlog::easy::log(level, logger, __func__, __LINE__, ##__VA_ARGS__);
