#include "ArrayUtils.h"
#include <stdlib.h>

/**
* creates a 2D array using malloc
*/
void **make2dArray(int rows, int cols, unsigned long ptr_to_cell_size, unsigned long cell_size) {
    void** arr = (void**) malloc(ptr_to_cell_size * rows); // TODO check if malloc fails
    for (int i = 0; i < rows; ++i) {
        arr[i] = malloc(cell_size * cols);
    }

    return arr;
}

/**
* frees a 2D array from memory
*/
void free2dArray(int rows, int cols, void** arr){
    for (int i = 0; i < rows; ++i) { // TODO check if arr != NULL
        free(arr[i]);
    }
    free(arr);
}