#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

#include <tchar.h>
#include <string>

// 转换函数声明
const TCHAR* ConvertToTCHAR(const char* str);
const TCHAR* ConvertToTCHAR(const std::string& str);

#endif // FUNCTION_H

