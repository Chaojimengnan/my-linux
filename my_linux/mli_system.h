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
[[nodiscard]] inline DIR* opendir (const char *dir_path)
{
    auto val = ::opendir(dir_path);
    GET_ERROR_MSG_OUTPUT();
    return val;
}

/**
 * @brief 关闭指定目录流，若成功同时也会关闭关联的底层的文件描述符。之后文件流不再可用
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

}//mli
