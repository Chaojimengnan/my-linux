#include "example_0.h"
#include "stdafx.h"
#include <iostream>
#include <utility>

// 测试myls
void example_0()
{
    // 获取当前目录的目录流
    auto* dir_stream = mli::opendir(".");

    dirent* dir_item = nullptr;
    while ((dir_item = mli::readdir(dir_stream)) != nullptr)
    {
        std::cout << dir_item->d_name << "\n";
    }

    mli::closedir(dir_stream);
}

// 测试sysconf,pathconf,fpathconf
void example_0_1()
{
    // 数值限制-------------------
    std::cout << "页面大小:" << mli::sysconf(_SC_PAGE_SIZE) << "\n";

    std::cout << "相对路径名最大字节数:" << mli::pathconf(".", _PC_PATH_MAX) << "\n";
    std::cout << "最大文件名字节数:" << mli::pathconf(".", _PC_NAME_MAX) << "\n";

    // 选项----------------------
    std::cout << "是否支持异步IO:" << mli::pathconf("my_linux_test", _PC_ASYNC_IO) << "\n";
    std::cout << "是否支持同步IO:" << mli::pathconf("my_linux_test", _PC_SYNC_IO) << "\n";

    // 实际上，只要_POSIX_THREADS有定义，就可以用了
    // 否则需要sysconf来确定是否可用
    std::cout << "是否支持线程:" << mli::sysconf(_SC_THREADS) << "\n";
    std::cout << "POSIX版本:" << mli::sysconf(_SC_VERSION) << "\n";

    std::cout << "OPEN_MAX:" << mli::sysconf(_SC_OPEN_MAX) << "\n";

    auto val = mli::sysconf(_SC_ATEXIT_MAX);
    std::cout << "ATEXIT_MAX:" << val << "\n";
}

const char* print_file_type(mode_t file_mode)
{
    if (S_ISREG(file_mode))
        return "普通文件";
    
    if (S_ISDIR(file_mode))
        return "目录文件";

    if (S_ISCHR(file_mode))
        return "字符特殊文件";

    if (S_ISBLK(file_mode))
        return "块特殊文件";

    if (S_ISFIFO(file_mode))
        return "管道或FIFO";

    if (S_ISLNK(file_mode))
        return "符号链接";

    if (S_ISSOCK(file_mode))
        return "套接字";

    return "未知类型";
}

// 测试stat系列函数
void example_0_2()
{
    struct stat my_stat{};
    mli::stat("/home", &my_stat);

    std::cout << print_file_type(my_stat.st_mode) << "\n";

    auto file_fd = mli::creat("./kaka.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    mli::fstat(file_fd, &my_stat);

    std::cout << print_file_type(my_stat.st_mode) << "\n";

    mli::close(file_fd);
}