//author: Ashutosh Sharma

#include <stdio.h>

// Recursive function to find the sum of two strings
long int sumof_two_strings(char *str1, char *str2) {
    int len1 = 0, len2 = 0;
    while (str1[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;
    
    len1--;
    len2--;
    
    long int sum = 0;
    long int place = 1;
    
    while (len1 >= 0 || len2 >= 0) {
        if (len1 >= 0) {
            sum += (str1[len1] - '0') * place;
            len1--;
        }
        if (len2 >= 0) {
            sum += (str2[len2] - '0') * place;
            len2--;
        }
        place *= 10;
    }
    
    return sum;
}

// Main function to test the sum of two strings function
int main() {
    char str2[100], str3[100];
    printf("Enter string1 (number): ");
    scanf("%s", str2);
    printf("Enter string2 (number): ");
    scanf("%s", str3);

    printf("The sum of two strings is: %ld\n", sumof_two_strings(str2, str3));

    return 0;
}