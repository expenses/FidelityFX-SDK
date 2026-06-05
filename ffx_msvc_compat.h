// MSVC _s function shims for GCC (force-included via -include in build.rs)
#ifndef FFX_MSVC_COMPAT_H
#define FFX_MSVC_COMPAT_H

#include <cstdio>
#include <cwchar>
#include <cstring>
#include <new>

#define _countof(arr) (sizeof(arr) / sizeof((arr)[0]))

#define sprintf_s(buf, sz, fmt, ...) snprintf(buf, sz, fmt, ##__VA_ARGS__)
#define swprintf_s(buf, sz, fmt, ...) swprintf(buf, sz, fmt, ##__VA_ARGS__)
// MSVC _s functions: the SDK uses both 2-arg (template size deduction)
// and 3-arg (explicit size) forms. A single macro won't handle both.
// We use variadic macros that pass everything through to the standard function.
#define wcscpy_s(dst, ...) wcscpy(dst, __VA_ARGS__)
#define wcscat_s(dst, ...) wcscat(dst, __VA_ARGS__)
#define strcpy_s(dst, ...) strcpy(dst, __VA_ARGS__)
// wcstombs_s: (&retval, dst, dstsz, src, srcsz) -> wcstombs(dst, src, dstsz), ignoring retval
#define wcstombs_s(pret, dst, dstsz, src, srcsz) wcstombs(dst, src, dstsz)
#define memcpy_s(dst, ...) memcpy(dst, __VA_ARGS__)
#define memset_s(dst, ...) memset(dst, __VA_ARGS__)

#endif
