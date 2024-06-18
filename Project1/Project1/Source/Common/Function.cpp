#include "Function.h"
const TCHAR* ConvertToTCHAR(const char* str) {
#ifdef UNICODE
    size_t newSize = strlen(str) + 1;
    wchar_t* wStr = new wchar_t[newSize];
    size_t convertedChars = 0;
    mbstowcs_s(&convertedChars, wStr, newSize, str, _TRUNCATE);
    return wStr;
#else
    return str;
#endif
}

const TCHAR* ConvertToTCHAR(const std::string& str) {
    return ConvertToTCHAR(str.c_str());
}