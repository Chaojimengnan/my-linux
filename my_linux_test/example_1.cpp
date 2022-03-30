#include "example_1.h"
#include "stdafx.h"
#include <memory>
#include <string>
#include <string_view>

void my_cout(const std::string_view& buf)
{
    mli::write(STDOUT_FILENO, buf.data(), buf.size());
}

// 读取内容不超过512
std::string my_cin()
{
    constexpr int MY_MAX_READ = 512;
    std::unique_ptr<char[]> buf(new char[MY_MAX_READ]);
    mli::read(STDIN_FILENO, buf.get(), MY_MAX_READ);
    return buf.get();
}

// 使用write和read代替std::cout和std::cin
void example_1()
{
    // mli::close(STDIN_FILENO);
    // mli::close(STDOUT_FILENO);
    my_cout("hahahhahaasdoiasjd\n");
    my_cout(my_cin());
}

// 默认文件模式，用户读写，组和其他读权限
constexpr auto FILE_MODE = (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

// 使用文件操作函数简单操作一个文件
void example_1_1()
{

    auto file_fd = mli::creat("./mymy.txt", FILE_MODE);
    mli::write(file_fd, "Hello my linux!", 15);

    // 默认creat只能写，不能读
    mli::close(file_fd);

    file_fd = mli::openat(AT_FDCWD, "./mymy.txt", O_RDWR);

    std::unique_ptr<char[]> temp_buf(new char[16]);

    mli::read(file_fd, temp_buf.get(), 16);
    std::cout << temp_buf.get() << "\n";

    // 偏移设为起点
    mli::lseek(file_fd, 0, SEEK_SET);

    mli::write(file_fd, "fuck ", 5);

    // 显式将缓存数据刷入磁盘
    mli::fsync(file_fd);

    mli::close(file_fd);
}

// 测试dup，dup2，和fcntl
void example_1_2()
{
    // 复制一个新的fd，它源自std out
    int output_fd = mli::dup(STDOUT_FILENO);
    mli::write(output_fd, "wo cao ni ma\n", 14);

    // 创建一个新文件
    int file_fd = mli::creat("./lala.txt", FILE_MODE);

    // 复制一个新的fd，它源自新文件
    mli::dup2(file_fd, output_fd);

    // 重新写一次
    mli::write(output_fd, "wo cao ni ma", 12);
    
    // 修改该fd的文件状态标志，output_fd也会受到影响
    // 因为他们指向同一个文件项
    // 如下获取fd的文件状态标志
    int file_state = mli::fcntl(file_fd, F_GETFL);

    // 判断访问模式
    switch (file_state & O_ACCMODE)
    {
    case O_WRONLY:
        std::cout << "write only!\n";
        break;
    case O_RDONLY:
        std::cout << "read only!\n";
        break;
    case O_RDWR:
        std::cout << "read write!\n";
        break;
    default:
        std::cout << "unknown access type!\n";
        break;
    }


    mli::close(file_fd);
    mli::close(output_fd);

}