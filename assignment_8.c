#include <stdio.h>

int main() {
    int marks[5], i, total = 0, fail = 0;
    float percentage;

    printf("Enter marks for 5 subjects: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &marks[i]);
        if (marks[i] < 40) fail = 1;
        total += marks[i];
    }

    if (fail) {
        printf("Result: FAIL (Scored less than 40 in one or more subjects)\n");
    } else {
        percentage = (float)total / 5.0;
        printf("Total: %d\nPercentage: %.2f%%\n", total, percentage);
        
        if (percentage >= 75) printf("Grade: Distinction\n");
        else if (percentage >= 60) printf("Grade: First Division\n");
        else if (percentage >= 50) printf("Grade: Second Division\n");
        else if (percentage >= 40) printf("Grade: Third Division\n");
    }

    return 0;
}