#include <stdio.h>
#include <stdlib.h>

void multiplyMatrices(int *firstMatrix, int *secondMatrix, int *result, int row1, int col1, int row2, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            *(result + i * col2 + j) = 0;
            for (int k = 0; k < col1; k++) {
                *(result + i * col2 + j) += *(firstMatrix + i * col1 + k) * *(secondMatrix + k * col2 + j);
            }
        }
    }
}

void displayMatrix(int *matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", *(matrix + i * col + j));
        }
        printf("\n");
    }
}

int main() {
    int row1, col1, row2, col2;

    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &row1, &col1);

    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    int *firstMatrix = (int *)malloc(row1 * col1 * sizeof(int));
    int *secondMatrix = (int *)malloc(row2 * col2 * sizeof(int));
    int *result = (int *)malloc(row1 * col2 * sizeof(int));

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            scanf("%d", (firstMatrix + i * col1 + j));
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", (secondMatrix + i * col2 + j));
        }
    }

    multiplyMatrices(firstMatrix, secondMatrix, result, row1, col1, row2, col2);

    printf("Resultant matrix after multiplication:\n");
    displayMatrix(result, row1, col2);

    free(firstMatrix);
    free(secondMatrix);
    free(result);

    return 0;
}