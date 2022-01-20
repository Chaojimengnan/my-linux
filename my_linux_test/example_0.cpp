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