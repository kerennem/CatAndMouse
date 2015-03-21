#ifndef _CATANDMOUSE_GAME_SERVICE_H_
#define _CATANDMOUSE_GAME_SERVICE_H_

#include "../../common/CommonStructs.h"
#include "../../common/CommonEnums.h"
#include "../world_builder/WorldsService.h"

#define BOARD_SIZE 7

typedef enum PlayerType {
    HUMAN, MACHINE
} PlayerType_t;

typedef enum MovementDirection {
    LEFT, UP, RIGHT, DOWN
} MovementDirection_t;

typedef enum BoardStatus {
    GAME_CONTINUES, INVALID, CAT_WINS, MOUSE_WINS, DRAW
} BoardStatus_t;

typedef struct GameParams {
    PlayerType_t cat_player_type;
    PlayerType_t mouse_player_type;
    int cat_machine_difficulty;
    int mouse_machine_difficulty;
    int turns_bound;
    struct World world;
} GameParams_t;

typedef struct GameBoard {
    Board board;
    PlayerName_t current_turn;
    int turns_left;
} GameBoard_t;

int initNewGame(GameParams_t game_params);

int setCatParams(PlayerType_t player_type, int difficulty);

int setMouseParams(PlayerType_t player_type, int difficulty);

GameBoard_t getCurrentGameBoard();

BoardStatus_t performMove(MovementDirection_t movement_direction);

#endif //_CATANDMOUSE_GAME_SERVICE_H_
