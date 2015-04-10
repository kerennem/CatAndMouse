#ifndef _CATANDMOUSE_WORLDCREATORCONTROLLER_H_
#define _CATANDMOUSE_WORLDCREATORCONTROLLER_H_

#include "../common/CommonEnums.h"
#include "../common/CommonStructs.h"

ControllerReturnStatus_t saveWorld();
ControllerReturnStatus_t goToMainMenuFromWorldCreator();
ControllerReturnStatus_t quitProgramFromWorldCreator();

ControllerReturnStatus_t placeMouseClicked(BoardCoordinate_t coordinate);
ControllerReturnStatus_t placeCatClicked(BoardCoordinate_t coordinate);
ControllerReturnStatus_t placeCheeseClicked(BoardCoordinate_t coordinate);
ControllerReturnStatus_t placeObstacleClicked(BoardCoordinate_t coordinate);
ControllerReturnStatus_t placeEmptyCellClicked(BoardCoordinate_t coordinate);

#endif //_CATANDMOUSE_WORLDCREATORCONTROLLER_H_
