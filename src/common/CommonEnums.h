#ifndef _CATANDMOUSE_COMMONENUMS_H_
#define _CATANDMOUSE_COMMONENUMS_H_

typedef enum PlayerName {
    CAT, MOUSE
} PlayerName_t;

typedef enum PlayerType {
    HUMAN, MACHINE
} PlayerType_t;

typedef enum BoardCell {
    EMPTY_CELL, OBSTACLE_CELL, MOUSE_CELL, CAT_CELL, CHEESE_CELL
} BoardCell_t;

typedef BoardCell_t** Board;

typedef enum MovementDirection {
    LEFT, UP, RIGHT, DOWN
} MovementDirection_t;

typedef enum BoardStatus {
    GAME_CONTINUES, INVALID, CAT_WINS, MOUSE_WINS, DRAW
} BoardStatus_t;

typedef enum ServiceReturnStatus {
    MOVEMENT_ERROR,
    OK,
    COORDINATE_OUT_OF_BOUNDS
} ServiceReturnStatus_t;

typedef enum ControllerReturnStatus {
    CONTROLLER_OK,
    CONTROLLER_INVALID_MOVE
} ControllerReturnStatus_t;

#endif //_CATANDMOUSE_COMMONENUMS_H_
