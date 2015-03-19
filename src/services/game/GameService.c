#include "GameService.h"

struct gameParams current_game_params;
struct gameBoard current_game_board;

void updateOldCell();
void updateNewCell(enum movementDirection movement_direction);
void updateBoardCells(enum movementDirection *movement_direction);

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
    if (current_game_board.turns_left > 0 && isMoveValid(movement_direction)) {
        updateBoardCells(movement_direction);
        current_game_board.current_turn = (current_game_board.current_turn + 1) % 2;
        current_game_board.turns_left--;
    } else {
        return MOVEMENT_ERROR;
    }
}

void updateBoardCells(enum movementDirection movement_direction) {
    updateOldCell();
    updateNewCell(movement_direction);
}

void updateOldCell() {
    struct boardCoordinate playerCoordinate = getCurrentPlayerCoordinate();
    current_game_board.board[playerCoordinate.x][playerCoordinate.y] = EMPTY_CELL;
}

void updateNewCell(enum movementDirection movement_direction) {
    struct boardCoordinate new_board_coordinate;
    switch (movement_direction) {
        case LEFT: new_board_coordinate.x--; break;
        case UP: new_board_coordinate.y++; break;
        case RIGHT: new_board_coordinate.x++; break;
        case DOWN: new_board_coordinate.y--; break;
    }
    current_game_board.board[new_board_coordinate.x][new_board_coordinate.y] = current_game_board.current_turn;
}