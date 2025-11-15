#include "validation.h"

#include <cctype>

namespace Validation {
    template <typename T>
    bool IsPositiveNumber(T number) {
        return number > 0;
    }

    template <typename T>
    bool IsInRange(T value, T min, T max) {
        return value >= min && value <= max;
    }

    bool IsEmpty(const string& str) {
        return str.empty();
    }

    bool IsNumeric(const string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    bool IsAlphabetic(const string& str) {
        for (char c : str) {
            if (!isalpha(c)) {
                return false;
            }
        }
        return true;
    }

    bool IsAlphanumeric(const string& str) {
        for (char c : str) {
            if (!isalnum(c)) {
                return false;
            }
        }
        return true;
    }
}