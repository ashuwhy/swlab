#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString {
private:
    char* str;
    size_t length;

    // Helper function for case-insensitive comparison
    bool compareChar(char a, char b) const;

public:
    // Constructors and destructor
    MyString();  // Default constructor
    MyString(const char* s);  // Parameterized constructor
    MyString(const MyString& other);  // Copy constructor
    ~MyString();  // Destructor

    // Operators
    MyString& operator=(const MyString& other);  // Copy assignment
    MyString operator+(const MyString& other) const;  // Concatenation
    bool operator==(const MyString& other) const;  // Case-insensitive comparison
    
    // Friend functions
    friend void reverse(MyString& s);  // Reverse string in-place
    friend std::ostream& operator<<(std::ostream& os, const MyString& s);  // Output operator

    // Helper methods for testing
    const char* c_str() const { return str; }
    size_t size() const { return length; }
};

#endif // MYSTRING_H