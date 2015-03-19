#ifndef _CATANDMOUSE_WORLDSSERVICE_H_
#define _CATANDMOUSE_WORLDSSERVICE_H_

#include "../../common/CommonStructs.h"

struct world {
    int board[7][7];
    struct boardCoordinate cat_coordinates;
    struct boardCoordinate mouse_coordinates;
    struct boardCoordinate cheese_coordinates;
};



#endif //_CATANDMOUSE_WORLDSSERVICE_H_