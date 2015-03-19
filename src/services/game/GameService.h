#ifndef _CATANDMOUSE_GAME_SERVICE_H_
#define _CATANDMOUSE_GAME_SERVICE_H_

#include "../../common/CommonStructs.h"
#include "../world_builder/WorldsService.h"

#define BOARD_SIZE 7;

enum playerName {
    CAT, MOUSE
};

enum playerType {
    HUMAN, MACHINE
};

enum movementDirection {
    LEFT, UP, RIGHT, DOWN
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
    int board[7][7]; // TODO find out why i can't replace 7 with BOARD_SIZE
    enum playerName current_turn;
    int turns_left;
};

int initNewGame(struct gameParams game_params);

int setCatParams(enum playerType player_type, int difficulty);

int setMouseParams(enum playerType player_type, int difficulty);

struct gameBoard getCurrentGameBoard();

int performMove(enum movementDirection movement_direction);

#endif //_CATANDMOUSE_GAME_SERVICE_H_
