#include <stdio.h>
#include <stdlib.h>

//Prototypes
void rotate_left(int **array, int n, int **new_array);
void rotate_right(int **array, int n, int **new_array);

int main() {
    int n;
    do {
        printf("Enter the matrix size:\n");
        scanf("%d", &n);
    }while (n < 2);
    
    //Dynamic memory allocation for usage of functions
    //Created new matrix and added the values in it because question said it
    int **matrix = malloc(n * sizeof(int *));
    int **new_matrix = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(int));
        new_matrix[i] = malloc(n * sizeof(int));
    }

    printf("Enter the matrices values with spaces between.\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int choice;

    do {
        printf("Type 1 to rotate the matrix to the left.\nType 2 to rotate the matrix to right.\nChoice: ");
        scanf("%d", &choice);
    } while (choice != 1 && choice != 2);


    if (choice == 1) {
        rotate_left(matrix, n, new_matrix);
    }
    else {
        rotate_right(matrix, n, new_matrix);
    }

    printf("New matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < n; j++) {
            printf("%d ", new_matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
        free(new_matrix[i]);
    }

    free(matrix);
    free(new_matrix);

    return 0;
}

void rotate_left(int **array, int n, int **new_array) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            new_array[i][j] = array[j][n - 1 - i];
        }
    }
}

void rotate_right(int **array, int n, int **new_array) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            new_array[j][i] = array[n - 1 - i][j];
        }
    }
}