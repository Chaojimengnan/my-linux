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

/**
 * @brief 尝试从指定文件描述符(fd)中读取count个字节到指定buf缓冲区中。若指定fd支持seeking，
 * 那么读取操作将从文件偏移开始，并且文件偏移将增加读取的字节数。如果文件偏移在或超过了文件尾。
 * 那么没有字节将被读取，并返回0。如果count大于SSIZE_MAX，结果由实现决定。
 *
 * @param fd 要读取的文件的文件描述符
 * @param buf 接受读取字节的缓冲区
 * @param count 要读取的字节数量
 * @return ssize_t 若成功，返回读取的字节数量(若返回0表示到达文件底部)，并且文件偏移移动该读取字节数量的距离
 * 该数量若比请求的字节数量少并不是一个错误，因为可能实际文件大小比请求字节少，或者它是一个管道(pipe)，或是一个
 * 终端(terminal)。如果发送错误，返回-1，并且设置errno，在这种情况下，文件位置是否改变没有规定。
 */
inline ssize_t read(int fd, void* buf, size_t count)
{
    auto val = ::read(fd, buf, count);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 将buf地址的count数量字节写入到fd关联的文件中。实际写入的字节数可能小于count，
 * 如磁盘被写满，或者遇到了 RLIMIT_FSIZE资源限制，或者调用在写入少于count字节后被信号处理程序打断。
 * 对于能seek的文件(即lseek能够使用的fd，如一个普通文件)，写操作从文件当前偏移量处开始，如果指定了
 * O_APPEND选项，则在每次写操作之前，将文件偏移量设置在文件的当前结尾处。在一次成功写之后，该文件
 * 偏移量增加实际写的字节数。如果count大于SSIZE_MAX，结果由实现决定。
 *
 * @param fd 要写入的文件的文件描述符
 * @param buf 指向写入内容的缓冲区
 * @param count 要写入的字节数量
 * @return ssize_t 若成功，返回写入的字节数。若出错，返回-1，并设置errno以指示错误。
 * 注意，成功的write()可能写入少于count的字节。如果是因为被信息处理程序打断，调用者
 * 可以再一次调用write()来写入剩余字节。
 */
inline ssize_t write(int fd, const void* buf, size_t count)
{
    auto val = ::write(fd, buf, count);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 从文件描述符fd在offset偏移(从文件开始的偏移)中读取count字节
 * 到buf开始位置，注意，文件自身偏移并不会改变。
 *
 * @param fd 要读取的文件的文件描述符，注意该fd必须是seekable
 * @param buf 接受读取字节的缓冲区
 * @param count 要读取的字节数量
 * @param offset 文件读取的偏移量(从文件开始位置的偏移)
 * @return ssize_t 若成功，返回读取的字节数量(若返回0表示到达文件底部)，如果发生错误，
 * 返回-1，并且设置errno。
 */
inline ssize_t pread(int fd, void* buf, size_t count, off_t offset)
{
    auto val = ::pread(fd, buf, count, offset);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 从buf开始位置写入count字节到文件描述符fd在offset偏移处(从文件开始的偏移)
 * ，注意，文件自身偏移并不会改变。
 *
 * @param fd 要写入的文件的文件描述符，注意该fd必须是seekable
 * @param buf 指向写入内容的缓冲区
 * @param count 要读取的字节数量
 * @param offset 文件写入的偏移量(从文件开始位置的偏移)
 * @return ssize_t 若成功，返回写入的字节数量，如果发生错误，返回-1，并且设置errno。
 */
inline ssize_t pwrite(int fd, const void* buf, size_t count, off_t offset)
{
    auto val = ::pwrite(fd, buf, count, offset);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 使用一个最小未使用的文件描述符创建一个oldfd文件描述符的拷贝。
 * 若成功返回，新fd和oldfd指向相同的文件表(file description)。使得它们共享文件偏移和
 * 文件状态标志(忘记了请看书)。例如：使用lseek改变oldfd的偏移，新fd也会被影响。
 * 注意，fd本身的标志并不共享(请回忆三张表的图)，新fd的close-on-exec标志被关闭。
 *
 * @param oldfd 要复制的文件描述符
 * @return int 若成功，返回新复制的文件描述符。若出错，返回-1，并设置errno
 */
inline int dup(int oldfd)
{
    auto val = ::dup(oldfd);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 使用newfd创建一个oldfd文件描述符的拷贝。若newfd已经被打开，则它将被关闭再拷贝，
 * 该步骤是原子操作，即先关闭newfd(如果之前打开着)，然后在newfd创建一个oldfd的拷贝，这很重要，
 * 因为分别调用close和dup可能导致竞争条件(race condition)。如果oldfd是非法值，则调用失败，
 * newfd不被关闭。如果oldfd是合法值，且oldfd = newfd，则该函数不做任何事，并返回newfd。
 *
 * @param oldfd 要拷贝的文件描述符
 * @param newfd 新的文件描述符，如果它正在被打开，则将会被先关闭，然后被oldfd拷贝
 * @return int 若成功，返回新复制的文件描述符。若出错，返回-1，并设置errno
 */
inline int dup2(int oldfd, int newfd)
{
    auto val = ::dup2(oldfd, newfd);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 使得所有代处理的文件元数据和缓存文件数据的修改写入底层文件系统(磁盘)。
 * 人话：对所有文件的改变写入到磁盘
 */
inline void sync()
{
    ::sync();
}

/**
 * @brief 该函数将fd指定文件的所有被修改的内核数据(即被修改的缓存页)写入(刷新)到磁盘中(或其他永久存储设备)。
 * 这样所有被更改的信息可以被保存即使系统崩溃或重启。调用线程将被阻塞直到写磁盘操作结束才返回。注意该函数
 * 与fdatasync的区别，该函数会同步更新文件的属性(看inode(7))，而fdatasync只更新文件的数据部分。
 *
 * @param fd 要将改变的数据写入磁盘的文件描述符
 * @return int 若成功，返回0，若失败返回-1，并设置errno
 */
inline int fsync(int fd)
{
    auto val = ::fsync(fd);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 该函数将fd指定文件的所有被修改的内核数据(即被修改的缓存页)写入(刷新)到磁盘中(或其他永久存储设备)。
 * 这样所有被更改的信息可以被保存即使系统崩溃或重启。调用线程将被阻塞直到写磁盘操作结束才返回。注意该函数
 * 与fsync的区别，fdatasync只更新文件的数据部分。
 *
 * @param fd 要将改变的数据写入磁盘的文件描述符
 * @return int 若成功，返回0，若失败返回-1，并设置errno
 */
inline int fdatasync(int fd)
{
    auto val = ::fdatasync(fd);
    GET_ERROR_MSG_OUTPUT();
    return val;
}


/**
 * @brief 该函数可以对已经打开的fd作各种操作(fcntl，file control)，操作类型取决于cmd，它是一个F_开头的宏，
 * 第三个参数的意义取决于cmd的值，大多数情况下第三个参数是一个int，而有些cmd并不需要第三个参数。
 * 如下说明一下，不要妄想使用该函数修改fd引用文件的访问模式，比如你不要想只读可以通过该函数改为可写。
 * 具体请看文档。
 * 
 * @param fd 要进行指定操作的已经打开的fd
 * @param cmd 它是一个F_开头的宏，用于指定具体操作，详情看文档
 * @param arg 它与cmd的值有关系，有些cmd忽略第三个参数
 * @return int 若成功，其返回值取决于cmd的类型。若失败返回-1，并且设置errno
 */
inline int fcntl(int fd, int cmd, int arg = 0)
{
    auto val = ::fcntl(fd, cmd, arg);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/* ioctl() */

} // namespace mli