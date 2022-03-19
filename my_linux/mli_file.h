#pragma once
#include "stdafx.h"

namespace mli {

/**
 * @brief C语言不支持重载，所以原本是一个变参函数，当创建新文件时才需要第三个参数mode。
 * open系统调用根据指定pathname，根据flags打开或创建文件，并返回这个文件的文件描述符
 * @param pathname 指定要操作的文件路径字符串
 * @param flags 它应该是O_开头的宏的组合，其中在O_RDONLY，O_WRONLY或O_RDWR(可能还包含O_EXEC和O_SEARCH)中必须选一个且只有一个。
 * 然后从其他的O_开头的宏或运算一个或多个(即可选的)。(O_RDONLY只读,O_WRONLY只写,O_RDWR读写)
 * @return int 返回新的最小未用文件描述符，如果出错，返回-1，并设置errno
 */
inline int open(const std::string_view& pathname, int flags)
{
    auto val = ::open(pathname.data(), flags);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief C语言不支持重载，所以原本是一个变参函数，当创建新文件时才需要第三个参数mode。
 * open系统调用根据指定pathname，根据flags打开或创建文件，并返回这个文件的文件描述符
 * @param pathname 指定要操作的文件路径字符串
 * @param flags 它应该是O_开头的宏的组合，其中在O_RDONLY，O_WRONLY或O_RDWR(可能还包含O_EXEC和O_SEARCH)中必须选一个且只有一个。
 * 然后从其他的O_开头的宏或运算一个或多个(即可选的)。(O_RDONLY只读,O_WRONLY只写,O_RDWR读写)
 * @param mode 当使用O_CREAT(或者还有O_TMPFILE)时，必须指定该参数，该参数用于指定该新文件的访问权限位
 * @return int 返回新的最小未用文件描述符，如果出错，返回-1，并设置errno
 */
inline int open(const std::string_view& pathname, int flags, mode_t mode)
{
    auto val = ::open(pathname.data(), flags, mode);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief C语言不支持重载，所以原本是一个变参函数，当创建新文件时才需要第四个参数mode。
 * 1.当pathname指定绝对路径名，dirfd参数被忽略，此时openat函数就相当于open函数;
 * 2.当pathname指定相对路径名，dirfd则指出了相对路径名在文件系统中的开始地质。dirfd可以通过打开相对路径名所在的目录来获取；
 * 3.当pathname指定相对路径名，dirfd具有特殊值AT_FDCWD，此时，路径名在当前工作目录，此时openat函数就相当于open函数;
 * 
 * @param dirfd 指定开始的目录，若pathname是绝对路径则忽略该参数，若是AT_FDCWD，则开始目录在当前工作目录
 * @param pathname 指定要操作的文件路径字符串
 * @param flags 它应该是O_开头的宏的组合，其中在O_RDONLY，O_WRONLY或O_RDWR(可能还包含O_EXEC和O_SEARCH)中必须选一个且只有一个。
 * 然后从其他的O_开头的宏或运算一个或多个(即可选的)。(O_RDONLY只读,O_WRONLY只写,O_RDWR读写)
 * @return int 返回新的最小未用文件描述符，如果出错，返回-1，并设置errno
 */
inline int openat(int dirfd, const std::string_view& pathname, int flags)
{
    auto val = ::openat(dirfd, pathname.data(), flags);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief C语言不支持重载，所以原本是一个变参函数，当创建新文件时才需要第四个参数mode。
 * 1.当pathname指定绝对路径名，dirfd参数被忽略，此时openat函数就相当于open函数;
 * 2.当pathname指定相对路径名，dirfd则指出了相对路径名在文件系统中的开始地质。dirfd可以通过打开相对路径名所在的目录来获取；
 * 3.当pathname指定相对路径名，dirfd具有特殊值AT_FDCWD，此时，路径名在当前工作目录，此时openat函数就相当于open函数;
 * 
 * @param dirfd 指定开始的目录，若pathname是绝对路径则忽略该参数，若是AT_FDCWD，则开始目录在当前工作目录
 * @param pathname 指定要操作的文件路径字符串
 * @param flags 它应该是O_开头的宏的组合，其中在O_RDONLY，O_WRONLY或O_RDWR(可能还包含O_EXEC和O_SEARCH)中必须选一个且只有一个。
 * 然后从其他的O_开头的宏或运算一个或多个(即可选的)。(O_RDONLY只读,O_WRONLY只写,O_RDWR读写)
 * @param mode 当使用O_CREAT(或者还有O_TMPFILE)时，必须指定该参数，该参数用于指定该新文件的访问权限位
 * @return int 返回新的最小未用文件描述符，如果出错，返回-1，并设置errno
 */
inline int openat(int dirfd, const std::string_view& pathname, int flags, mode_t mode)
{
    auto val = ::openat(dirfd, pathname.data(), flags, mode);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 该函数等效于open(pathname, O_WRONLY|O_CREAT|O_TRUNC, mode)。
 * 注意，使用该函数创建的文件是只写的，如果你需要创建一个临时文件能够读写，使用
 * open(pathname, O_RDWR|O_CREAT|O_TRUNC, mode)
 * 
 * @param pathname 要创建的文件的路径以及文件名
 * @param mode 该参数用于指定该新文件的访问权限位
 * @return int 返回新的最小未用文件描述符，如果出错，返回-1，并设置errno
 */
inline int creat(const std::string_view& pathname, mode_t mode)
{
    auto val = ::creat(pathname.data(), mode);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 关闭指定文件描述符(fd)，并释放改进从加在该文件上的所有记录锁。如果
 * 该fd是最后一个引用打开文件的文件描述符，那么该打开文件的相关资源将被释放。
 * 
 * @param fd 指定要关闭的文件描述符
 * @return int 成功则返回0，若出错返回-1，并设置errno
 */
inline int close(int fd)
{
    auto val = ::close(fd);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 设置文件描述符(fd)所关联文件的偏移量，该函数仅将新偏移量记录于内核中，
 * 没有任何I/O操作，它影响之后的读写操作。
 * 
 * @param fd 要设置偏移量的文件的文件描述符
 * @param offset 新偏移量，它可以比文件本身大小更大，这样会产生"空洞"，它并不会改变文件本身大小
 * @param where 它的可选值为SEEK_SET, SEEK_CUR, SEEK_END，用于指定offset的起点
 * @return off_t 若成功，返回结果偏移量(以字节为单位，从文件开始到当前偏移)，若出错，返回(off_t)-1，并设置errno
 */
inline off_t lseek(int fd, off_t offset, int where)
{
    auto val = ::lseek(fd, offset, where);
    GET_ERROR_MSG_OUTPUT();
    return val;
}



} // namespace mli