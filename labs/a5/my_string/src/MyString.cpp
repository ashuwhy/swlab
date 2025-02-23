#include "MyString.h"
#include <cstring>

MyString::MyString() : str(new char[1]), length(0) {
    str[0] = '\0';
}

MyString::MyString(const char* s) {
    if (s == nullptr) {
        str = new char[1];
        str[0] = '\0';
        length = 0;
        return;
    }
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str, s);
}

MyString::MyString(const MyString& other) {
    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);
}

MyString::~MyString() {
    delete[] str;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        char* temp = new char[other.length + 1];
        strcpy(temp, other.str);
        delete[] str;
        str = temp;
        length = other.length;
    }
    return *this;
}

MyString MyString::operator+(const MyString& other) const {
    size_t newLength = length + other.length;
    char* newStr = new char[newLength + 1];
    strcpy(newStr, str);
    strcat(newStr, other.str);
    
    MyString result;
    delete[] result.str;
    result.str = newStr;
    result.length = newLength;
    return result;
}

bool MyString::compareChar(char a, char b) const {
    // Custom case-insensitive character comparison
    if (a >= 'A' && a <= 'Z') a = a + ('a' - 'A');
    if (b >= 'A' && b <= 'Z') b = b + ('a' - 'A');
    return a == b;
}

bool MyString::operator==(const MyString& other) const {
    if (length != other.length) return false;
    
    for (size_t i = 0; i < length; ++i) {
        if (!compareChar(str[i], other.str[i])) {
            return false;
        }
    }
    return true;
}

void reverse(MyString& s) {
    if (s.length <= 1) return;
    
    // Safe in-place reversal
    for (size_t i = 0; i < s.length / 2; ++i) {
        char temp = s.str[i];
        s.str[i] = s.str[s.length - 1 - i];
        s.str[s.length - 1 - i] = temp;
    }
}

std::ostream& operator<<(std::ostream& os, const MyString& s) {
    os << s.str;
    return os;
}