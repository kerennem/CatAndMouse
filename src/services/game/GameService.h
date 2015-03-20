#ifndef _CATANDMOUSE_GAME_SERVICE_H_
#define _CATANDMOUSE_GAME_SERVICE_H_

#include "../../common/CommonStructs.h"
#include "../../common/CommonEnums.h"
#include "../world_builder/WorldsService.h"

#define BOARD_SIZE 7

enum playerType {
    HUMAN, MACHINE
};

enum movementDirection {
    LEFT, UP, RIGHT, DOWN
};

enum boardStatus {
    GAME_CONTINUES, INVALID, CAT_WINS, MOUSE_WINS, DRAW
};

struct gameParams {
    enum playerType cat_player_type;
    enum playerType mouse_player_type;
    int cat_machine_difficulty;
    int mouse_machine_difficulty;
    int turns_bound;
    struct world world;
};

struct gameBoard {
    int board[BOARD_SIZE][BOARD_SIZE];
    enum playerName current_turn;
    int turns_left;
};

int initNewGame(struct gameParams game_params);

int setCatParams(enum playerType player_type, int difficulty);

int setMouseParams(enum playerType player_type, int difficulty);

struct gameBoard getCurrentGameBoard();

int performMove(enum movementDirection movement_direction);

#endif //_CATANDMOUSE_GAME_SERVICE_H_
