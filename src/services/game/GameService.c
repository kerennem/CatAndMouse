#include "GameService.h"

struct gameParams current_game_settings;
struct gameBoard current_game_board;
struct boardCoordinate current_cat_coordinates;
struct boardCoordinate current_mouse_coordinates;

bool isMoveValid(enum movementDirection movement_direction);

void updateBoardCells(enum movementDirection *movement_direction);

void updateOldCell();

void updateNewCell(enum movementDirection movement_direction);

bool isCatNearMouse();

bool isMouseNearCheese();

bool areTwoCoordinatesAdjacent(struct boardCoordinate coord1, struct boardCoordinate coord2);

struct boardCoordinate getNewCoordinate(enum movementDirection movement_direction);

void updateCurrentPlayerCoordinates(enum movementDirection movement_direction);

enum boardStatus calculateBoardStatus();

/* *********** Implementation **************/

int initNewGame(struct gameParams game_params) {
    current_game_params = game_params;
    current_cat_coordinates = game_params.world.cat_coordinates;
    current_mouse_coordinates = game_params.world.mouse_coordinates;
    int game_board[7][7] = {0};
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            game_board[i][j] = game_params.world.board[i][j];
        }
    }
    current_game_board = {.board = game_board, .current_turn = MOUSE, .turns_left = game_params.turns_bound};
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

enum boardStatus {
    GAME_CONTINUES, INVALID, CAT_WINS, MOUSE_WINS, DRAW
};

int performMove(enum movementDirection movement_direction) {
    if (current_game_board.turns_left > 0 && isMoveValid(movement_direction)) {
        updateBoardCells(movement_direction);
        updateCurrentPlayerCoordinates(movement_direction);
        current_game_board.current_turn = (current_game_board.current_turn + 1) % 2;
        current_game_board.turns_left--;

        return calculateBoardStatus();

    } else {
        return MOVEMENT_ERROR;
    }
}

enum boardStatus calculateBoardStatus() {
    if (current_game_board.turns_left == 0) {
        return DRAW;
    }
    if (isCatNearMouse()) {
        return CAT_WINS;
    }
    if (isMouseNearCheese()) {
        return MOUSE_WINS;
    }

    return GAME_CONTINUES;
}

bool isCatNearMouse() {
    return areTwoCoordinatesAdjacent(current_mouse_coordinates, current_cat_coordinates);
}

bool isMouseNearCheese() {
    return areTwoCoordinatesAdjacent(current_mouse_coordinates, current_game_settings.world.cheese_coordinates);
}

bool areTwoCoordinatesAdjacent(struct boardCoordinate coord1, struct boardCoordinate coord2) {
    if (coord1.x != coord2.x && coord1.y != coord2.y) {
        return false;
    }
    if (coord1.x == coord2.x) {
        if (coord1.y == coord2.y + 1 || coord1.y == coord2.y - 1) return true;
    }
    if (coord1.y == coord2.y) {
        if (coord1.x == coord2.x + 1 || coord1.x == coord2.x - 1) return true;
    }
}

void updateCurrentPlayerCoordinates(enum movementDirection movement_direction) {
    struct boardCoordinate current_player_new_coordinate = getNewCoordinate(movement_direction);
    if (current_game_board.current_turn == CAT) {
        current_cat_coordinates = current_player_new_coordinate;
    } else {
        current_mouse_coordinates = current_player_new_coordinate;
    }
}

bool isMoveValid(enum movementDirection movement_direction) {
    struct boardCoordinate newCoordinate = getNewCoordinate(movement_direction);
    return (current_game_board.board[newCoordinate.x][newCoordinate.y] != OBSTACLE_CELL) &&
            (newCoordinate.x >= 0) && (newCoordinate.x < 7)
            && (newCoordinate.y >= 0) && (newCoordinate.y < 7);
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
    struct boardCoordinate new_board_coordinate = getNewCoordinate(movement_direction);
    current_game_board.board[new_board_coordinate.x][new_board_coordinate.y] = current_game_board.current_turn;
}

struct boardCoordinate getNewCoordinate(enum movementDirection movement_direction) {
    struct boardCoordinate new_board_coordinate;
    if (current_game_board.current_turn == CAT) {
        new_board_coordinate = current_cat_coordinates;
    } else {
        new_board_coordinate = current_mouse_coordinates;
    }

    switch (movement_direction) {
        case LEFT:
            new_board_coordinate.x--;
            break;
        case UP:
            new_board_coordinate.y++;
            break;
        case RIGHT:
            new_board_coordinate.x++;
            break;
        case DOWN:
            new_board_coordinate.y--;
            break;
    }
    return new_board_coordinate;
}
