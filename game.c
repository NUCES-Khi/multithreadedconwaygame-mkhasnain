#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int rows, cols;
int** grid;
int** new_grid;
pthread_mutex_t mutex;

// Initialize the grid with zeros
void init_grid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            new_grid[i][j] = 0;
        }
    }
}

// Print the grid
void print_grid(int** grid) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Count the number of live neighbors around a cell
int count_neighbors(int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < rows && j >= 0 && j < cols && !(i == row && j == col)) {
                count += grid[i][j];
            }
        }
    }
    return count;
}

// Update the grid for the next generation
void* update_row(void* arg) {
    
    int row = *((int*) arg);
    pthread_mutex_lock(&mutex);
    for (int col = 0; col < cols; col++) {
        int neighbors = count_neighbors(row, col);
        if (grid[row][col] == 1 && (neighbors == 2 || neighbors == 3)) {
            new_grid[row][col] = 1;
        } else if (grid[row][col] == 0 && neighbors == 3) {
            new_grid[row][col] = 1;
        }
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}


int main() {
    int generations;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    grid = (int**) malloc(rows * sizeof(int*));
    new_grid = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*) malloc(cols * sizeof(int));
        new_grid[i] = (int*) malloc(cols * sizeof(int));
    }
    int tid[rows];
    for (int i = 0; i < rows; i++) {
        tid[i] = i;
    }
    printf("Enter the initial grid:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    printf("Enter the number of generations: ");
    scanf("%d", &generations);
    pthread_t threads[rows];
    pthread_mutex_init(&mutex, 0);
    printf("Initial grid:\n");
    print_grid(grid);
    for (int i = 0; i < generations; i++) {
        init_grid();
        for (int j = 0; j < rows; j++) {
pthread_create(&threads[j], NULL, update_row, &tid[j]);
}
    // Wait for all threads to finish
    for (int j = 0; j < rows; j++) {
        pthread_join(threads[j], NULL);
    }
    
    // Copy new grid to old grid
    for (int j = 0; j < rows; j++) {
        for (int k = 0; k < cols; k++) {
            grid[j][k] = new_grid[j][k];
        }
    }
    
    // Print the updated grid
    printf("Generation %d:\n", i + 1);
    print_grid(grid);
}

// Destroy the mutex
pthread_mutex_destroy(&mutex);
free(grid);
free(new_grid);
return 0;
}
