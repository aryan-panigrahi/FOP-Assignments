#include <stdio.h>
#include <stdlib.h>

// Function for 3x3 Determinant
float determinant(float a[3][3], float k) {
  float s = 1, det = 0, b[3][3];
  int i, j, m, n, c;
  if (k == 1) return (a[0][0]);
  det = 0;
  for (c = 0; c < k; c++) {
    m = 0;
    n = 0;
    for (i = 0; i < k; i++) {
      for (j = 0; j < k; j++) {
        b[i][j] = 0;
        if (i != 0 && j != c) {
          b[m][n] = a[i][j];
          if (n < (k - 2)) n++;
          else {
            n = 0;
            m++;
          }
        }
      }
    }
    det = det + s * (a[0][c] * determinant(b, k - 1));
    s = -1 * s;
  }
  return (det);
}

// Function for Cofactor and Inverse
void cofactor(float num[3][3], float f) {
  float b[3][3], fac[3][3];
  int p, q, m, n, i, j;
  for (q = 0; q < f; q++) {
    for (p = 0; p < f; p++) {
      m = 0;
      n = 0;
      for (i = 0; i < f; i++) {
        for (j = 0; j < f; j++) {
          if (i != q && j != p) {
            b[m][n] = num[i][j];
            if (n < (f - 2)) n++;
            else {
              n = 0;
              m++;
            }
          }
        }
      }
      fac[q][p] = (float)pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  
  // Transpose of cofactor (Adjoint) and Multiply by 1/det
  float d = determinant(num, f);
  float inv[3][3];
  for (i = 0; i < f; i++) {
    for (j = 0; j < f; j++) {
      inv[i][j] = fac[j][i] / d;
    }
  }
  printf("\nInverse of the matrix:\n");
  for (i = 0; i < f; i++) {
    for (j = 0; j < f; j++) {
      printf("%.2f\t", inv[i][j]);
    }
    printf("\n");
  }
}


int main() {
    int choice, r, c, i, j, k;
    int a[10][10], b[10][10], sum[10][10];
    float mat3[3][3]; // For inverse
    
    printf("\nMENU:\n1. Addition\n2. Saddle Point\n3. Inverse (3x3 only)\n4. Magic Square\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter rows and cols: ");
        scanf("%d %d", &r, &c);
        printf("Matrix A elements:\n");
        for(i=0; i<r; i++) for(j=0; j<c; j++) scanf("%d", &a[i][j]);
        printf("Matrix B elements:\n");
        for(i=0; i<r; i++) for(j=0; j<c; j++) scanf("%d", &b[i][j]);
        
        printf("Sum:\n");
        for(i=0; i<r; i++) {
            for(j=0; j<c; j++) printf("%d\t", a[i][j] + b[i][j]);
            printf("\n");
        }
    } 
    else if (choice == 2) {
        // Saddle Point
        printf("Enter rows and cols: ");
        scanf("%d %d", &r, &c);
        printf("Elements:\n");
        for(i=0; i<r; i++) for(j=0; j<c; j++) scanf("%d", &a[i][j]);
        
        int found = 0;
        for (i = 0; i < r; i++) {
            int min_row = a[i][0], col_ind = 0;
            for (j = 1; j < c; j++) {
                if (a[i][j] < min_row) {
                    min_row = a[i][j];
                    col_ind = j;
                }
            }
            // Check if min_row is max in that col
            int k, is_max = 1;
            for (k = 0; k < r; k++) {
                if (a[k][col_ind] > min_row) {
                    is_max = 0;
                    break;
                }
            }
            if (is_max) {
                printf("Saddle Point found: %d at (%d, %d)\n", min_row, i, col_ind);
                found = 1;
            }
        }
        if (!found) printf("No Saddle Point found.\n");
    }
    else if (choice == 3) {
        printf("Enter 3x3 Matrix elements:\n");
        for(i=0; i<3; i++) for(j=0; j<3; j++) scanf("%f", &mat3[i][j]);
        float d = determinant(mat3, 3);
        if (d == 0) printf("Inverse not possible (Determinant is 0).\n");
        else cofactor(mat3, 3);
    }
    else if (choice == 4) {
        // Magic Square
        printf("Enter dimension (N for NxN): ");
        scanf("%d", &r);
        printf("Elements:\n");
        for(i=0; i<r; i++) for(j=0; j<r; j++) scanf("%d", &a[i][j]);
        
        int sum_diag1 = 0, sum_diag2 = 0;
        for(i=0; i<r; i++) {
            sum_diag1 += a[i][i];
            sum_diag2 += a[i][r-i-1];
        }
        
        if (sum_diag1 != sum_diag2) {
             printf("Not a Magic Square\n");
             return 0;
        }
        
        int flag = 1;
        for(i=0; i<r; i++) {
            int row_sum = 0, col_sum = 0;
            for(j=0; j<r; j++) {
                row_sum += a[i][j];
                col_sum += a[j][i];
            }
            if (row_sum != sum_diag1 || col_sum != sum_diag1) {
                flag = 0;
                break;
            }
        }
        if(flag) printf("It is a Magic Square!\n");
        else printf("Not a Magic Square\n");
    }

    return 0;
}