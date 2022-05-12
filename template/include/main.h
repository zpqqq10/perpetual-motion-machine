#ifndef __E9PATCH_H
#define __E9PATCH_H

#include <cstdarg>
#include <cassert>
#include <cstdio>

#define NO_RETURN               __attribute__((__noreturn__))
#define NO_INLINE               __attribute__((__noinline__))

static inline void logImpl(char c)
{
    putchar(c);
}
static inline void logImpl(const char *s)
{
    fputs(s, stdout);
}

#define debug(msg, ...)                                                 \
    do {                                                                \
        if (__builtin_expect(option_debug, false))                      \
            debugImpl((msg), ##__VA_ARGS__);                            \
    } while (false)
// #define log(color, msg, ...)                                            \
//     do {                                                                \
//         logImpl(msg, ##__VA_ARGS__);                                    \
//     } while (false)


extern bool option_debug;

extern void warning(const char *msg, ...);
extern void NO_RETURN error(const char *msg, ...);
extern void debugImpl(const char *msg, ...);

#endif