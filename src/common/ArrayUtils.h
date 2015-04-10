//
// Created by nemzer on 3/21/2015.
//

#ifndef _CATANDMOUSE_ARRAYUTILS_H_
#define _CATANDMOUSE_ARRAYUTILS_H_

void **make2dArray(int rows, int cols, unsigned long ptr_to_cell_size, unsigned long cell_size);

void free2dArray(int rows, int cols, void** array);

#endif //_CATANDMOUSE_ARRAYUTILS_H_
