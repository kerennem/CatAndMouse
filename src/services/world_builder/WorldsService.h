#ifndef _CATANDMOUSE_WORLDSSERVICE_H_
#define _CATANDMOUSE_WORLDSSERVICE_H_

#include "../../common/CommonStructs.h"
#include "../../common/CommonEnums.h"


Board getBoardFrom(World_t world);

ServiceReturnStatus_t setCatCoordinate(World_t *world, BoardCoordinate_t coord);

ServiceReturnStatus_t setMouseCoordinate(World_t *world, BoardCoordinate_t coord);

ServiceReturnStatus_t setCheeseCoordinate(World_t *world, BoardCoordinate_t coord);

ServiceReturnStatus_t setFirstMove(World_t *world, PlayerName_t player_name);

bool validateWorld(World_t *world_t);


#endif //_CATANDMOUSE_WORLDSSERVICE_H_
