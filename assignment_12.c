#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n1, n2, i, min, scd = -1;

    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);

    // Finding GCD
    printf("Greatest Common Divisor (GCD): %d\n", gcd(n1, n2));

    // Finding Smallest Common Divisor (SCD)
    min = (n1 < n2) ? n1 : n2;
    for (i = 2; i <= min; i++) {
        if (n1 % i == 0 && n2 % i == 0) {
            scd = i;
            break; // Found the first (smallest) one
        }
    }

    if (scd != -1)
        printf("Smallest Common Divisor: %d\n", scd);
    else
        printf("No Common Divisor other than 1.\n");

    return 0;
}