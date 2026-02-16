#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double n1, n2, res;
    long long fact = 1;

    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power (x^y)\n6. Factorial (x!)\nEnter choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 5) {
        printf("Enter two numbers (for x! enter number then 0): ");
        scanf("%lf %lf", &n1, &n2);
    } else if (choice == 6) {
        printf("Enter number: ");
        scanf("%lf", &n1);
    }

    switch(choice) {
        case 1: printf("Result: %.2lf\n", n1 + n2); break;
        case 2: printf("Result: %.2lf\n", n1 - n2); break;
        case 3: printf("Result: %.2lf\n", n1 * n2); break;
        case 4: 
            if(n2 != 0) printf("Result: %.2lf\n", n1 / n2); 
            else printf("Error: Div by Zero\n");
            break;
        case 5: 
            res = pow(n1, n2);
            printf("Result: %.2lf\n", res);
            break;
        case 6:
            for(int i=1; i<=n1; ++i) fact *= i;
            printf("Factorial of %.0lf = %lld\n", n1, fact);
            break;
        default: printf("Invalid Choice\n");
    }
    return 0;
}