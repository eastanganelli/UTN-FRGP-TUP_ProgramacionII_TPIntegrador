#include "validation.h"

#include <cctype>

namespace Validation {
    bool IsSpaceChar(char c) {
        return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
    }

    bool IsDigitChar(char c) {
        return c >= '0' && c <= '9';
    }

    bool IsAlphaChar(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    bool IsAlnumChar(char c) {
        return IsAlphaChar(c) || IsDigitChar(c);
    }

    template <typename T>
    bool IsPositiveNumber(T number) {
        return number > 0;
    }

    template <typename T>
    bool IsInRange(T value, T min, T max) {
        return value >= min && value <= max;
    }

    bool IsEmpty(const string& str) {
        if (str.empty()) return true;
        for (char c : str) {
            if (!IsSpaceChar(c)) return false;
        }
        return true;
    }

    bool IsEmpty(const char* str) {
        if (str == nullptr) {
            return true;
        }
        while (*str != '\0') {
            if (!IsSpaceChar(*str)) {
                return false;
            }
            str++;
        }
        return true;
    }

    bool IsNumeric(const string& str) {
        if (str.empty()) return false;
        for (char c : str) {
            if (!IsDigitChar(c)) return false;
        }
        return true;
    }

    bool IsAlphabetic(const string& str) {
        if (str.empty()) return false;
        for (char c : str) {
            if (!IsAlphaChar(c)) return false;
        }
        return true;
    }

    bool IsAlphanumeric(const string& str) {
        if (str.empty()) return false;
        for (char c : str) {
            if (!IsAlnumChar(c)) return false;
        }
        return true;
    }

    bool IsEqual(const string& str1, const string& str2) {
        return str1.find(str2) != string::npos;
    }

    bool IsEqual(const char* str1, const char* str2) {
        if (str1 == nullptr || str2 == nullptr) {
            return str1 == str2;
        }
        return string(str1).find(string(str2)) != string::npos;
    }

    string ToUpper(const string& str) {
        string result = str;
        for (char& c : result) {
            c = toupper(c);
        }
        return result;
    }

    string ToFixedDecimal(float number, unsigned int precision) {
        std::string num_text = std::to_string(number);
        std::string rounded = num_text.substr(0, num_text.find(".") + precision + 1);
        return rounded;
    }
}