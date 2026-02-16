#include <stdio.h>
#include <math.h>

int main() {
    int num, choice, i, isPrime = 1;
    long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("1. Square Root\n2. Square\n3. Cube\n4. Check Prime\n5. Factorial\n6. Prime Factors\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if(num >= 0) printf("Square Root: %.2f\n", sqrt(num));
            else printf("Invalid for negative numbers.\n");
            break;
        case 2:
            printf("Square: %d\n", num * num);
            break;
        case 3:
            printf("Cube: %d\n", num * num * num);
            break;
        case 4:
            if (num <= 1) isPrime = 0;
            for (i = 2; i <= num / 2; ++i) {
                if (num % i == 0) { isPrime = 0; break; }
            }
            if (isPrime) printf("%d is Prime\n", num);
            else printf("%d is not Prime\n", num);
            break;
        case 5:
            for (i = 1; i <= num; ++i) fact *= i;
            printf("Factorial: %lld\n", fact);
            break;
        case 6:
            printf("Prime Factors: ");
            int temp = num;
            for (i = 2; i * i <= temp; i++) {
                while (temp % i == 0) {
                    printf("%d ", i);
                    temp /= i;
                }
            }
            if (temp > 1) printf("%d", temp);
            printf("\n");
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}