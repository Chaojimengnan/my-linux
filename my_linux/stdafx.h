#pragma once

#include <unistd.h>

#include <string>

#ifdef _DEBUG

/**
 * POSIX 错误处理，errno类似于Windows的GetLastError，也是线程安全的
 * 通过strerror可以打印出errno的含义，通过errno = 0可以重置错误.
 */

#include <iostream>// For printf()
#include <errno.h> // For errno
#include <string.h>// For strerror()

// 当value和error_value相同时打印错误
#define GET_ERROR_MSG_OUTPUT_NORMAL(value, error_value) if (value == error_value){\
    printf("thread(%d): %s : function fails\n%s : %d \n\n", gettid(), \
        __FUNCTION__, __FILE__, __LINE__);\
}

// 当errno不为0时打印错误
#define GET_ERROR_MSG_OUTPUT() { auto my_error_code = errno;\
    if (my_error_code != 0) { \
        printf("thread(%d): %s (%d) %s\n%s : %d \n\n", gettid(), \
        __FUNCTION__,my_error_code, strerror(my_error_code) , __FILE__, __LINE__);\
        errno = 0;\
    }\
}

#endif


