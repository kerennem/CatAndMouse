#ifndef _CATANDMOUSE_GAMEMODEL_H_
#define _CATANDMOUSE_GAMEMODEL_H_

#include "../common/CommonStructs.h"
#include "../common/CommonEnums.h"
#include "../services/world_builder/WorldsService.h"

/**
* a struct that holds all the the parameters that define the current game
*/
typedef struct GameParams {
    PlayerType_t cat_player_type;
    PlayerType_t mouse_player_type;
    int cat_machine_difficulty;
    int mouse_machine_difficulty;
    struct World world;
} GameParams_t;

/**
* a struct that holds the current state of the game
*/
typedef struct GameBoard {
    Board board;
    PlayerName_t current_turn;
    int turns_left;
} GameBoard_t;

// TODO why is return type int?
int initNewGame(GameParams_t game_params);

// TODO why is return type int?
int setCatParams(PlayerType_t player_type, int difficulty);

// TODO why is return type int?
int setMouseParams(PlayerType_t player_type, int difficulty);

BoardCoordinate_t getCatCoordinates();

BoardCoordinate_t getMouseCoordinates();

GameBoard_t getCurrentGameBoard();

BoardStatus_t performMove(MovementDirection_t movement_direction);

#endif //_CATANDMOUSE_GAMEMODEL_H_
