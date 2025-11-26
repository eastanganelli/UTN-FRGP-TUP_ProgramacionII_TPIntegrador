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
}