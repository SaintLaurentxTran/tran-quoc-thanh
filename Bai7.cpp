#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **createMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Khong du bo nho!");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Khong du bo nho!");
            exit(1);
        }
    }
    return matrix;
}

void generateRandomValues(int **matrix, int rows, int cols) {
    srand(time(NULL)); 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; 
        }
    }
}

void sumRowElements(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        printf("Tong cac phan tu tren dong %d: %d\n", i + 1, sum);
    }
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int **matrix;
    int num_rows, num_cols;
  
    printf("Nhap so dong cua ma tran: ");
    scanf("%d", &num_rows);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &num_cols);
    
    matrix = createMatrix(num_rows, num_cols);
  
    generateRandomValues(matrix, num_rows, num_cols);

    printf("Ma tran da tao:\n");
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    sumRowElements(matrix, num_rows, num_cols);

    freeMatrix(matrix, num_rows);

    return 0;
}
