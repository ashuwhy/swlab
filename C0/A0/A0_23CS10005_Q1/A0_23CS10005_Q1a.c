//author: Ashutosh Sharma

#include <stdio.h>

// Recursive function to find the length of a string
int string_length(char *str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + string_length(str + 1);
}

// Main function to test the string length function
int main() {
    char str1[100];
    printf("Enter a string: ");
    scanf("%s", str1);
    printf("The length of the string is: %d\n", string_length(str1));

    return 0;
}