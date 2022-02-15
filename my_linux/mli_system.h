#pragma once
#include "stdafx.h"
#include <dirent.h>

namespace mli
{

/**
 * @brief 在指定目录名字打开一个目录流(directory stream)，返回这个目录流的指针。该流位置在
 * 目录的第一个条目中。使用closedir关闭该目录流
 * 
 * @param dir_path 目录的名字
 * @return DIR* 返回目录流对象，若失败返回NULL，使用errno以获得更多错误信息
 */
[[nodiscard]] inline DIR* opendir (const std::string& dir_path)
{
    auto val = ::opendir(dir_path.c_str());
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 关闭指定目录流，若成功同时也会关闭关联的底层的文件描述符(fd)。之后文件流不再可用
 * 
 * @param dir_stream 要关闭的目录流对象
 * @return int 若成功返回0，若失败返回-1，使用errno以获得更多错误信息
 */
inline int closedir(DIR *dir_stream)
{
    auto val = ::closedir(dir_stream);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 从目录流获取一个目录条目并返回，该目录条目是一个dirent结构体。当到达目录流结尾或出现错误时
 * 返回NULL，使用errno来判断是出错还是到达结尾。
 * 
 * @param dir_stream 要从中获取一个目录条目的目录流
 * @return dirent* 若成功，返回这个目录条目结构体指针，若失败返回NULL，若到达目录流结尾也返回NULL
 */
inline dirent* readdir(DIR *dir_stream)
{
    auto val = ::readdir(dir_stream);
    GET_ERROR_MSG_OUTPUT();
    return val;
}


/**
 * @brief 改变调用进程的工作目录，工作目录是相对路径查找的起点(不以/开头即为相对路径)。
 * 随后通过fork创建的子进程将继承父进程的当前工作目录
 * 
 * @param path 新的工作目录
 * @return int 若成功返回0，若失败返回-1，使用errno以获得更多错误信息
 */
inline int chdir(const std::string& path)
{
    auto val = ::chdir(path.c_str());
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 在运行时获取系统配置信息，如是否支持某个选项或限制，大部分限制数值和选项可在unistd.h和limits.h中编译期获取。
 * 
 * @param name 它应该是一个_SC_开头的宏
 * @return long 若出现错误，返回-1，并设置errno以指示错误类型，
 * 若指定限制值是不确定的，则返回-1，而errno不设置。
 * 若指定选项不支持，则返回-1，而errno不设置。
 * 否则当前指定选项或限制值返回正数(>0)
 */
inline long sysconf(int name)
{
    auto val = ::sysconf(name);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 获取指定文件的配置值，该函数使用文件路径字符串来指定文件。大部分限制数值和选项可在unistd.h和limits.h中编译期获取。
 * 
 * @param path 指定文件的路径字符串
 * @param name 它应该是一个_PC_开头的宏，它必须与指定文件类型兼容，如_PC_MAX_INPUT则指定文件必须是一个终端
 * @return long 若出现错误，返回-1，并设置errno以指示错误类型，
 * 若指定限制值是不确定的，则返回-1，而errno不设置。
 * 若指定选项不支持，则返回-1，而errno不设置。
 * 否则当前指定选项或限制值返回正数(>0)
 */
inline long pathconf(const std::string& path, int name)
{
    auto val = ::pathconf(path.c_str(), name);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 获取指定文件的配置值，该函数使用一个打开的文件描述符来指定文件。大部分限制数值和选项可在unistd.h和limits.h中编译期获取。
 * 
 * @param fd 指定文件的打开的文件描述符
 * @param name 它应该是一个_PC_开头的宏，它必须与指定文件类型兼容，如_PC_MAX_INPUT则指定文件必须是一个终端
 * @return long 若出现错误，返回-1，并设置errno以指示错误类型，
 * 若指定限制值是不确定的，则返回-1，而errno不设置。
 * 若指定选项不支持，则返回-1，而errno不设置。
 * 否则当前指定选项或限制值返回正数(>0)
 */
inline long fpathconf(int fd, int name)
{
    auto val = ::fpathconf(fd, name);
    GET_ERROR_MSG_OUTPUT();
    return val;
}


}//mli
