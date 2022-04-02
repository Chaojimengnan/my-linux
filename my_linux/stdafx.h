#pragma once

#include <fcntl.h>  //文件控制
#include <unistd.h> //定义了符号常量

#include <string_view>

#ifdef MY_LINUX_PRINT_ERROR
#    define LOERR_ENABLE_TRANSFER
#    define LOERR_ENABLE_PREDEFINE
#    define LOERR_ENABLE_PREDEFINE_UNIX

#    include <loerr/loerr.h>

#    ifndef GET_ERROR_MSG_OUTPUT()
#        define GET_ERROR_MSG_OUTPUT() LOERR_UNIX_OUTPUT_IF_ERROR()
#    endif
#    ifndef GET_ERROR_MSG_OUTPUT_NORMAL(value, error_value)
#        define GET_ERROR_MSG_OUTPUT_NORMAL(value, error_value) LOERR_OUTPUT_IF_VALUE_EQUAL(value, error_value)
#    endif
#else
#    define GET_ERROR_MSG_OUTPUT()
#    define GET_ERROR_MSG_OUTPUT_NORMAL(value, error_value)
#endif