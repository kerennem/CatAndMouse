#ifndef _CATANDMOUSE_COMMONSTRUCTS_H_
#define _CATANDMOUSE_COMMONSTRUCTS_H_

#include <stdbool.h>
#include "CommonEnums.h"

typedef struct BoardCoordinate {
    int x;
    int y;
} BoardCoordinate_t;

bool isBoardCoordinateValid(BoardCoordinate_t coordinate);

/**
* a struct that holds the parameters that define a specific world
*/
typedef struct World {
    Board board;
    // TODO These are for convenience (this data should already be in board). Probably should be replaced with some service functions.
    BoardCoordinate_t cat_coordinates;
    BoardCoordinate_t mouse_coordinates;
    BoardCoordinate_t cheese_coordinates;
    PlayerName_t first_move;
    int turns_bound;
} World_t;

#endif //_CATANDMOUSE_COMMONSTRUCTS_H_
