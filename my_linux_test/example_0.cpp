#include "example_0.h"
#include "stdafx.h"


// 测试myls
void example_0()
{
    // 获取当前目录的目录流
    auto dir_stream = mli::opendir(".");

    dirent* dir_item = nullptr; 
    while (dir_item = mli::readdir(dir_stream))
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
}