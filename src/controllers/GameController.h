#include "../common/CommonEnums.h"
#include "../common/CommonStructs.h"
#include "../services/game/GameService.h"

#ifndef _CATANDMOUSE_GAMECONTROLLER_H_
#define _CATANDMOUSE_GAMECONTROLLER_H_

ControllerReturnStatus_t reconfigureMouse();
ControllerReturnStatus_t reconfigureCat();
ControllerReturnStatus_t restartGame();
ControllerReturnStatus_t goToMainMenu();
ControllerReturnStatus_t quitProgram();

BoardStatus_t performMoveToDirection(MovementDirection_t movement_direction);
BoardStatus_t performMoveToCoordinate(BoardCoordinate_t selected_coordinates);

GameBoard_t retrieveCurrentGameBoard();

#endif //_CATANDMOUSE_GAMECONTROLLER_H_
