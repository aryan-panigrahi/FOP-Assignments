#include <stdio.h>

int main() {
    float basic_pay, hra, ta, gross_salary, prof_tax, net_salary;

    printf("Enter Basic Pay: ");
    scanf("%f", &basic_pay);

    hra = 0.10 * basic_pay;
    ta = 0.05 * basic_pay;
    gross_salary = basic_pay + hra + ta;
    
    // Professional tax is 2% of total (gross) salary
    prof_tax = 0.02 * gross_salary; 
    net_salary = gross_salary - prof_tax;

    printf("\n--- Salary Slip ---\n");
    printf("Basic Pay: %.2f\n", basic_pay);
    printf("HRA (10%%): %.2f\n", hra);
    printf("TA (5%%): %.2f\n", ta);
    printf("Gross Salary: %.2f\n", gross_salary);
    printf("Professional Tax (2%%): %.2f\n", prof_tax);
    printf("Net Salary Payable: %.2f\n", net_salary);

    return 0;
}