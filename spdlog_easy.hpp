#pragma once
#include <spdlog/spdlog.h>
#include <string>
#include <vector>
#include <set>

namespace spdlog
{
    namespace easy
    {
		template<typename Arg, typename ...Args>
		void log(spdlog::level::level_enum level, std::string func, std::size_t line, std::string f, Arg arg, Args&& ...args)
		{
			using namespace std;
			auto fmts = fmt::format("[{0}:{1}] ", func, line) + f;
			spdlog::default_logger_raw()->log(level, fmts.c_str(), arg, forward<Args>(args)...);
		}

		template<typename T>
		void log(spdlog::level::level_enum level, std::string func, std::size_t line, T t)
		{
			log(level, func, line, "{0}", t);
		}

		inline void log(spdlog::level::level_enum level, std::string func, std::size_t line)
		{
			log(level, func, line, "{0}", "");
		}

        //std::string logger;
        //template<typename Arg, typename ...Args>
        //void log(spdlog::level::level_enum level, std::string logger, std::string func, std::size_t line, std::string f, Arg arg, Args&& ...args)
        //{
        //    using namespace std;
        //    auto logg = spdlog::get(logger);
        //    if (logg == nullptr)
        //    {
        //        return;
        //    }
        //    string str(func_guard_t::call_level, '=');
        //    auto fmts = fmt::format("[{0}{1}:{2}] ", str, func, line) + f;
        //    logg->log(level, fmts.c_str(), arg, forward<Args>(args)...);
        //}

        //template<typename T>
        //void log(spdlog::level::level_enum level, std::string logger, std::string func, std::size_t line, T t)
        //{
        //    log(level, logger, func, line, "{0}", t);
        //}

        //inline void log(spdlog::level::level_enum level, std::string logger, std::string func, std::size_t line)
        //{
        //    log(level, logger, func, line, "{0}", "");
        //}

        //class func_guard_t
        //{
        //public:
        //    func_guard_t(std::string log, spdlog::level::level_enum level, const char* func)
        //    {
        //        using namespace std;
        //        func_ = func;
        //        level_ = level;
        //        func_guard_t::call_level++;
        //        string str(func_guard_t::call_level, '<');
        //        if (spdlog::get("log") != nullptr)
        //        {
        //            spdlog::get("log")->log(level_, "[{0}enter@{1}]", str, func_);
        //        }
        //    }

        //    ~func_guard_t()
        //    {
        //        using namespace std;
        //        string str(func_guard_t::call_level, '>');
        //        if (spdlog::get("log") != nullptr)
        //        {
        //            spdlog::get("log")->log(level_, "[{0}exit@{1}]", str, func_);
        //        }
        //        func_guard_t::call_level--;
        //    }

        //    static int call_level;

        //private:
        //    std::string func_;
        //    spdlog::level::level_enum level_;
        //};
    }
}

//#define LOG(level, logger, ...) \
//	spdlog::easy::log(level, logger, __func__, __LINE__, ##__VA_ARGS__);
//
//#define LOG_LEVEL(logger, ...) \
//	LOG(spdlog::level::level_enum::info, logger, ##__VA_ARGS__);
//
//#define LOG_INFO(logger, ...) \
//	LOG(spdlog::level::level_enum::info, logger, ##__VA_ARGS__);
//
//#define LOGGER_ERROR(logger, ...) \
//	LOG(spdlog::level::level_enum::err, logger, ##__VA_ARGS__);
//
//#define LOG_WARN(logger, ...) \
//	LOG(spdlog::level::level_enum::warn, logger, ##__VA_ARGS__);
//
//#define LOG_CRITICAL(logger, ...) \
//	LOG(spdlog::level::level_enum::critical, logger, ##__VA_ARGS__);
//
//#define LOGGER_DEBUG(logger, ...) \
//	LOG(spdlog::level::level_enum::debug, logger, ##__VA_ARGS__);
//
//#define LOG_DEBUG(...) \
//    LOGGER_DEBUG("log", ##__VA_ARGS__)
//
//#define LOGGER_TRACE(logger, ...) \
//	LOG(spdlog::level::level_enum::trace, logger, ##__VA_ARGS__);
//
//#define LOG_TRACE(...) \
//    LOGGER_TRACE("log", ##__VA_ARGS__)
//
//int spdlog::easy::func_guard_t::call_level = 0;
//
//#define LOG_FUNC(log, level) \
//    spdlog::easy::func_guard_t func_guard(log, level, __func__);
//
//#define LOG_FUNC_DEBUG(log) \
//    LOG_FUNC(log, spdlog::level::level_enum::debug);
//
//#define LOG_FUNC_INFO(log) \
//    LOG_FUNC(log, spdlog::level::level_enum::info);
//
//#define LOG_FUNC_ERROR(log) \
//    LOG_FUNC(log, spdlog::level::level_enum::err);
//
//#define LOG_FUNC_WARN(log) \
//    LOG_FUNC(log, spdlog::level::level_enum::warn);
//
//#define LOG_FUNC_TRACE(log) \
//    LOG_FUNC(log, spdlog::level::level_enum::trace);
//
//#define LOG_FUNC_CRITICAL(log) \
//    LOG_FUNC(log, spdlog::level::level_enum::critical);

#define LOG(lvl_, ...) \
	spdlog::easy::log(spdlog::level::level_enum::lvl_, __func__, __LINE__, ##__VA_ARGS__);
