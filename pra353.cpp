#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col;
    int i, j;

    // Input number of rows and columns
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    int matrix1[row][col], matrix2[row][col], sum[row][col];

    // Input elements of first matrix
    printf("\nEnter elements of first matrix:\n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input elements of second matrix
    printf("\nEnter elements of second matrix:\n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Add the matrices
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Display the result
    printf("\nSum of the matrices:\n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    system("pause"); // Pause before closing
    return 0;
}
