#pragma once

#ifndef CXX_NOEXCEPT
#if defined(_MSC_VER) && _MSC_VER >= 1900 // VS 2015
#define CXX_NOEXCEPT
#elif defined(__clang__) && __clang_major__ >= 3 // Clang 3.0
#define CXX_NOEXCEPT
#elif defined(__GNUC__) && (__GNUC__ >= 5 || (__GNUC__ == 4 && __GNUC__MINOR__ >= 6)) // GCC 4.6
#define CXX_NOEXCEPT
#endif
#endif // !CXX_NOEXCEPT

#ifndef CXX_DEFAULTED_FUNCTIONS
#if defined(_MSC_VER) && _MSC_VER >= 1800 // VS 2013
#define CXX_DEFAULTED_FUNCTIONS
#elif defined(__clang__) && __clang_major__ >= 3 // Clang 3.0
#define CXX_DEFAULTED_FUNCTIONS
#elif defined(__GNUC__) && (__GNUC__ >= 5 || (__GNUC__ == 4 && __GNUC__MINOR__ >= 4)) // GCC 4.4
#define CXX_DEFAULTED_FUNCTIONS
#endif
#endif // !CXX_DEFAULTED_FUNCTIONS

#ifndef CXX_DELETED_FUNCTIONS
#if defined(_MSC_VER) && _MSC_VER >= 1800 // VS 2013
#define CXX_DELETED_FUNCTIONS
#elif defined(__clang__) && __clang_major__ >= 3 // Clang 3.0
#define CXX_DELETED_FUNCTIONS
#elif defined(__GNUC__) && (__GNUC__ >= 5 || (__GNUC__ == 4 && __GNUC__MINOR__ >= 4)) // GCC 4.4
#define CXX_DELETED_FUNCTIONS
#endif
#endif // !CXX_DELETED_FUNCTIONS

#ifndef CXX_STRONG_ENUMS
#if defined(_MSC_VER) && _MSC_VER >= 1700 // VS 2012
#define CXX_STRONG_ENUMS
#elif defined(__clang__) && (__clang_major__ >= 3 || (__clang_major__ == 2 && __clang_minor__ >= 9)) // Clang 2.9
#define CXX_STRONG_ENUMS
#elif defined(__GNUC__) && (__GNUC__ >= 5 || (__GNUC__ == 4 && __GNUC__MINOR__ >= 4)) // GCC 4.4
#define CXX_STRONG_ENUMS
#endif
#endif // !CXX_STRONG_ENUMS

#ifndef CXX_OVERRIDE
#if defined(_MSC_VER) && _MSC_VER >= 1700 // VS 2012
#define CXX_OVERRIDE
#elif defined(__clang__) && (__clang_major__ >= 3 || (__clang_major__ == 2 && __clang_minor__ >= 9)) // Clang 2.9
#define CXX_OVERRIDE
#elif defined(__GNUC__) && (__GNUC__ >= 5 || (__GNUC__ == 4 && __GNUC__MINOR__ >= 7)) // GCC 4.7
#define CXX_OVERRIDE
#endif
#endif // !CXX_OVERRIDE

#ifndef CXX_NULLPTR
#if defined(_MSC_VER) && _MSC_VER >= 1600 // VS 2010
#define CXX_NULLPTR
#elif defined(__clang__) && (__clang_major__ >= 3 || (__clang_major__ == 2 && __clang_minor__ >= 9)) // Clang 2.9
#define CXX_NULLPTR
#elif defined(__GNUC__) && (__GNUC__ >= 5 || (__GNUC__ == 4 && __GNUC__MINOR__ >= 6)) // GCC 4.6
#define CXX_NULLPTR
#endif
#endif // !CXX_NULLPTR
