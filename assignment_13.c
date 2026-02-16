#include <stdio.h>

int main() {
    int num, digit;

    [cite_start]// Input [cite: 338]
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Digits in reverse order: ");

    // Handle negative numbers by converting to positive
    if (num < 0) {
        num = -num;
    }

    // Special case for 0
    if (num == 0) {
        printf("0");
    }

    [cite_start]// Loop to extract and print digits [cite: 342]
    while (num > 0) {
        digit = num % 10;      // Get the last digit
        printf("%d ", digit);  // Print it
        num = num / 10;        // Remove the last digit
    }

    printf("\n");
    return 0;
}