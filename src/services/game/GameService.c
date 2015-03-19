#include "GameService.h"

struct gameParams current_game_params;
struct gameBoard current_game_board;

int initNewGame(struct gameParams) {

    return 0;
}

int setCatParams(enum playerType player_type, int difficulty) {
    current_game_params.cat_player_type = player_type;
    if (player_type == MACHINE) {
        current_game_params.cat_machine_difficulty = difficulty;
    }
}

int setMouseParams(enum playerType player_type, int difficulty) {
    current_game_params.mouse_player_type = player_type;
    if (player_type == MACHINE) {
        current_game_params.mouse_machine_difficulty = difficulty;
    }
}

struct currentGameBoard getCurrentGameBoard() {
    return current_game_board;
}

enum movementResult {
    OK, INVALID, CAT_WINS, MOUSE_WINS, DRAW
};

int performMove(enum movementDirection movement_direction) {
    if (isMoveValid(movement_direction)) {


    } else {

    }
}