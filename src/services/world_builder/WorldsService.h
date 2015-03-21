#ifndef _CATANDMOUSE_WORLDSSERVICE_H_
#define _CATANDMOUSE_WORLDSSERVICE_H_

#include "../../common/CommonStructs.h"
#include "../../common/CommonEnums.h"

typedef struct World {
    BoardCell_t** board;
    // TODO These are for convenience (this data should already be in board). Probably should be replaced with some service functions.
    BoardCoordinate_t cat_coordinates;
    BoardCoordinate_t mouse_coordinates;
    BoardCoordinate_t cheese_coordinates;
    PlayerName_t first_move;
} World_t;

BoardCell_t** getBoardFrom(World_t world);

#endif //_CATANDMOUSE_WORLDSSERVICE_H_
