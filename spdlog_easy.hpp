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
			auto fmts = fmt::format("({0}:{1}) ", func, line) + f;
			log->info(fmts.c_str(), arg, forward<Args>(args)...);
		}

		template<typename T>
		void info(std::string logger, std::string func, std::size_t line, T t)
		{
			info(logger, func, line, "{0}", t);
		}
	}
}


#define INFO(logger, ...) \
	info(logger, __func__, __LINE__, __VA_ARGS__);
