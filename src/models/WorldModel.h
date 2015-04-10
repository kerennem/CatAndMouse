#include <stdbool.h>
#include "../common/CommonEnums.h"
#include "../common/CommonStructs.h"

#ifndef _CATANDMOUSE_WORLDCREATOR_H_
#define _CATANDMOUSE_WORLDCREATOR_H_

World_t getWorld();
ModelReturnStatus_t setWorld(World_t world);
ModelReturnStatus_t placeMouse(BoardCoordinate_t coordinate);
ModelReturnStatus_t placeCat(BoardCoordinate_t coordinate);
ModelReturnStatus_t placeCheese(BoardCoordinate_t coordinate);
ModelReturnStatus_t placeObstacle(BoardCoordinate_t coordinate);
ModelReturnStatus_t placeEmptyCell(BoardCoordinate_t coordinate);
ModelReturnStatus_t isWorldValid();

#endif //_CATANDMOUSE_WORLDCREATOR_H_
