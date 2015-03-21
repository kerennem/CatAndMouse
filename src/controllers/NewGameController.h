#include "../common/CommonEnums.h"

#ifndef _CATANDMOUSE_NEWGAMECONTROLLER_H_
#define _CATANDMOUSE_NEWGAMECONTROLLER_H_

ControllerReturnStatus_t setCatPlayerType(PlayerType_t player_type);
ControllerReturnStatus_t setCatDifficulty(int difficulty);

ControllerReturnStatus_t setMousePlayerType(PlayerType_t player_type);
ControllerReturnStatus_t setMouseDifficulty(int difficulty);

ControllerReturnStatus_t back();

#endif //_CATANDMOUSE_NEWGAMECONTROLLER_H_
