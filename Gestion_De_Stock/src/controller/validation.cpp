#include "validation.h"

#include <cstring>
#include <iostream>

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
        return str1 == str2;
    }

    bool IsEqual(const char* str1, const char* str2) {
        if (str1 == nullptr || str2 == nullptr) {
            return str1 == str2;
        }
        return std::strcmp(str1, str2) == 0;
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

    void RemoveSpaces(string &s) {
        string out;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') out.push_back(s[i]);
        }
        s = out;
    }
    
    void ClearInputLine() {
        while (std::cin.good()) {
            int ch = std::cin.get();
            if (ch == '\n' || ch == '\r' || ch == EOF) break;
        }
    }
}
