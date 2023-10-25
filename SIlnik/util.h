#ifdef UTIL_H
#define UTIL_H

#include <stdio.h>

#define ERROR_EXIT(...) frpintf(stderr, _VA_ARGS_)
#define ERROR_RETURN(R, ...) fprintf(stderr, _VA_ARGS_); return R

#endif // UTIL_H

