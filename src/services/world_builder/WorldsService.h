#ifndef _CATANDMOUSE_WORLDSSERVICE_H_
#define _CATANDMOUSE_WORLDSSERVICE_H_

#include "../../common/CommonStructs.h"
#include "../../common/CommonEnums.h"

struct world {
    int board[7][7];
    // TODO These are for convenience (this data should already be in board). Probably should be replaced with some service functions.
    struct boardCoordinate cat_coordinates;
    struct boardCoordinate mouse_coordinates;
    struct boardCoordinate cheese_coordinates;
    enum playerName first_move;
};



#endif //_CATANDMOUSE_WORLDSSERVICE_H_
