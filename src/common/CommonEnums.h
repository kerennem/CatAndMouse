#ifndef _CATANDMOUSE_COMMONENUMS_H_
#define _CATANDMOUSE_COMMONENUMS_H_

// TODO change names of typedefs (not only in this file)

typedef enum PlayerName {
    CAT, MOUSE
} PlayerName_t;

typedef enum PlayerType {
    HUMAN, MACHINE
} PlayerType_t;

typedef enum BoardCell {
    EMPTY_CELL, OBSTACLE_CELL, MOUSE_CELL, CAT_CELL, CHEESE_CELL
} BoardCell_t;

/**
* a typedef for a board - a 2D array of board cells
*/
typedef BoardCell_t** Board;

typedef enum MovementDirection {
    LEFT, UP, RIGHT, DOWN
} MovementDirection_t;

/**
* the status of current board according to the placement of game pieces
*/
typedef enum BoardStatus {
    GAME_CONTINUES, INVALID, CAT_WINS, MOUSE_WINS, DRAW
} BoardStatus_t;

/**
* status of service. Whether it is o.k or not ant type of error, if not.
*/
typedef enum ServiceReturnStatus {
    MOVEMENT_ERROR, // TODO change names to be SERVICE_XXX
    OK,
    COORDINATE_OUT_OF_BOUNDS,
    SERVICE_OK,
    SERVICE_WORLD_FILE_NOT_FOUND,
    SERVICE_INVALID_WORLD_FILE_FIRST_MOVE,
    SERVICE_INVALID_WORLD_FILE_BOARD
} ServiceReturnStatus_t;

/**
* status of controller. Whether it is o.k or not ant type of error, if not.
*/
typedef enum ControllerReturnStatus {
    CONTROLLER_OK,
    CONTROLLER_INVALID_MOVE,
    CONTROLLER_SAVE_ERROR,
    CONTROLLER_CAT_IS_MISSING,
    CONTROLLER_MOUSE_IS_MISSING,
    CONTROLLER_CHEESE_IS_MISSING
} ControllerReturnStatus_t;

/**
* status of model. Whether it is o.k or not ant type of error, if not.
*/
typedef enum ModelReturnStatus {
    MODEL_OK,
    MODEL_INVALID_COORDINATE,
    MODEL_PARAMETER_IS_NULL,
    MODEL_CAT_IS_MISSING,
    MODEL_MOUSE_IS_MISSING,
    MODEL_CHEESE_IS_MISSING
} ModelReturnStatus_t;

#endif //_CATANDMOUSE_COMMONENUMS_H_
