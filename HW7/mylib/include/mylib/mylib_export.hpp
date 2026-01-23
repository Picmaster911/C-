#pragma once

#if defined(_WIN32)
#if defined(MYLIB_BUILD)
#define MYLIB_API __declspec(dllexport)
#else
#define MYLIB_API __declspec(dllimport)
#endif
#else
#define MYLIB_API
#endif
