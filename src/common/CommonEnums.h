#ifndef _CATANDMOUSE_COMMONENUMS_H_
#define _CATANDMOUSE_COMMONENUMS_H_

typedef enum PlayerName {
    CAT, MOUSE
} PlayerName_t;

typedef enum LogicalError {
    MOVEMENT_ERROR
} LogicalError_t;

typedef enum BoardCell {
    EMPTY_CELL, OBSTACLE_CELL, MOUSE_CELL, CAT_CELL, CHEESE_CELL
} BoardCell_t;

#endif //_CATANDMOUSE_COMMONENUMS_H_
