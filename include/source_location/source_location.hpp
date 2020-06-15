#pragma once
#ifndef SOURCE_LOCATION_HPP
#define SOURCE_LOCATION_HPP
#include <string>
#include <cstdint> // uint_least32_t
#include "compile_features.h" // CXX_NOEXCEPT

#ifndef NOEXCEPT
#ifdef CXX_NOEXCEPT
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif // CXX_NOEXCEPT
#endif // !NOEXCEPT

#ifndef CONSTEXPR
#ifdef __cpp_constexpr
#define CONSTEXPR constexpr
#else
#define CONSTEXPR inline
#endif // __cpp_constexpr
#endif // !CONSTEXPR

namespace upward
{
#ifndef UINT_LEAST32_MAX
    typedef unsigned int uint_least32_t;
#endif // !UINT_LEAST32_MAX

    struct source_location
    {
    public:
        source_location() NOEXCEPT
            : _line(0), _column(0), _file_name(""), _function_name("")
        {

        }

        source_location(const source_location& other)
            : _line(other.line()), _column(other.column()), _file_name(other.file_name()), _function_name(other.function_name())
        {

        }

#ifdef __cpp_rvalue_references
        source_location(source_location&& other) NOEXCEPT
            : _line(other.line()), _column(other.column()), _file_name(other.file_name()), _function_name(other.function_name())
        {

        }
#endif // __cpp_rvalue_references

        source_location(uint_least32_t line, uint_least32_t column, const std::string& file_name, const std::string& function_name)
            : _line(line), _column(column), _file_name(file_name), _function_name(function_name)
        {

        }

        ~source_location()
        {

        }

        CONSTEXPR uint_least32_t line() const NOEXCEPT
        {
            return _line;
        }

        CONSTEXPR uint_least32_t column() const NOEXCEPT
        {
            return _column;
        }

        inline const char* file_name() const NOEXCEPT
        {
            return _file_name.c_str();
        }

        inline const char* function_name() const NOEXCEPT
        {
            return _function_name.c_str();
        }

    private:
        uint_least32_t _line;
        uint_least32_t _column;
        std::string _file_name;
        std::string _function_name;
    };
}

#define SOURCE_LOCATION_CURRENT() \
    upward::source_location(__LINE__, 0, __FILE__, __func__)

#endif // !SOURCE_LOCATION_HPP
