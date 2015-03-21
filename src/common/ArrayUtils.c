#include "ArrayUtils.h"
#include <stdlib.h>

void **make2dArray(int rows, int cols, unsigned long ptr_to_cell_size, unsigned long cell_size) {
    void** arr = (void**) malloc(ptr_to_cell_size * rows);
    for (int i = 0; i < rows; ++i) {
        arr[i] = malloc(cell_size * cols);
    }

    return arr;
}
