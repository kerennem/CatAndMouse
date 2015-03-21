#include "GameService.h"
#include <stdbool.h>

static GameParams_t current_game_settings;
static GameBoard_t current_game_board;
static BoardCoordinate_t current_cat_coordinates;
static BoardCoordinate_t current_mouse_coordinates;

bool isMoveValid(MovementDirection_t movement_direction);

void updateBoardCells(MovementDirection_t movement_direction);

void updateOldCell();

void updateNewCell(MovementDirection_t movement_direction);

bool isCatNearMouse();

bool isMouseNearCheese();

bool areTwoCoordinatesAdjacent(BoardCoordinate_t coord1, BoardCoordinate_t coord2);

BoardCoordinate_t getNewCoordinate(MovementDirection_t movement_direction);

void updateCurrentPlayerCoordinates(MovementDirection_t movement_direction);

BoardStatus_t calculateBoardStatus();

/* *********** Implementation **************/

int initNewGame(GameParams_t game_params) {
    printf("DEBUG GameService::initNewGame()\n");
    current_game_settings = game_params;
    current_cat_coordinates = game_params.world.cat_coordinates;
    current_mouse_coordinates = game_params.world.mouse_coordinates;
    BoardCell_t** game_board;
    game_board = getBoardFrom(game_params.world);

    current_game_board = (GameBoard_t) {
            .board = game_board,
            .current_turn = game_params.world.first_move,
            .turns_left = game_params.turns_bound
    };
    return 0;
}

// Maybe should be replaced with setHumanCat/setMachineMouse...
int setCatParams(PlayerType_t player_type, int difficulty) {
    current_game_settings.cat_player_type = player_type;
    if (player_type == MACHINE) {
        current_game_settings.cat_machine_difficulty = difficulty;
    }
}

int setMouseParams(PlayerType_t player_type, int difficulty) {
    current_game_settings.mouse_player_type = player_type;
    if (player_type == MACHINE) {
        current_game_settings.mouse_machine_difficulty = difficulty;
    }
}

GameBoard_t getCurrentGameBoard() {
    return current_game_board;
}

BoardStatus_t performMove(MovementDirection_t movement_direction) {
    printf("DEBUG GameService::performMove()\n");
    if (current_game_board.turns_left > 0 && isMoveValid(movement_direction)) {
        updateBoardCells(movement_direction);
        updateCurrentPlayerCoordinates(movement_direction);
        current_game_board.current_turn = (current_game_board.current_turn + 1) % 2;
        current_game_board.turns_left--;

        return calculateBoardStatus();
    } else {
        return INVALID;
    }
}

BoardStatus_t calculateBoardStatus() {
    if (isCatNearMouse()) {
        return CAT_WINS;
    }
    if (isMouseNearCheese()) {
        return MOUSE_WINS;
    }
    if (current_game_board.turns_left == 0) {
        return DRAW;
    }

    return GAME_CONTINUES;
}

bool isCatNearMouse() {
    return areTwoCoordinatesAdjacent(current_mouse_coordinates, current_cat_coordinates);
}

bool isMouseNearCheese() {
    return areTwoCoordinatesAdjacent(current_mouse_coordinates, current_game_settings.world.cheese_coordinates);
}

bool areTwoCoordinatesAdjacent(BoardCoordinate_t coord1, BoardCoordinate_t coord2) {
    if (coord1.x == coord2.x) {
        if (coord1.y == coord2.y + 1 || coord1.y == coord2.y - 1) return true;
    }
    if (coord1.y == coord2.y) {
        if (coord1.x == coord2.x + 1 || coord1.x == coord2.x - 1) return true;
    }
    return false;
}

void updateCurrentPlayerCoordinates(MovementDirection_t movement_direction) {
    BoardCoordinate_t current_player_new_coordinate = getNewCoordinate(movement_direction);
    if (current_game_board.current_turn == CAT) {
        current_cat_coordinates = current_player_new_coordinate;
    } else {
        current_mouse_coordinates = current_player_new_coordinate;
    }
}

bool isMoveValid(MovementDirection_t movement_direction) {
    BoardCoordinate_t newCoordinate = getNewCoordinate(movement_direction);
    return  (newCoordinate.x >= 0) && (newCoordinate.x < 7)
            && (newCoordinate.y >= 0) && (newCoordinate.y < 7)
            && (current_game_board.board[newCoordinate.x][newCoordinate.y] != OBSTACLE_CELL);
}

void updateBoardCells(MovementDirection_t movement_direction) {
    updateOldCell();
    updateNewCell(movement_direction);
}

void updateOldCell() {
    BoardCoordinate_t playerCoordinate;
    if (current_game_board.current_turn == CAT) {
        playerCoordinate = current_cat_coordinates;
    } else {
        playerCoordinate = current_mouse_coordinates;
    }
    current_game_board.board[playerCoordinate.x][playerCoordinate.y] = EMPTY_CELL;
}

void updateNewCell(MovementDirection_t movement_direction) {
    BoardCoordinate_t new_board_coordinate = getNewCoordinate(movement_direction);
    if (current_game_board.current_turn == CAT) {
        current_game_board.board[new_board_coordinate.x][new_board_coordinate.y] = CAT_CELL;
    } else {
        current_game_board.board[new_board_coordinate.x][new_board_coordinate.y] = MOUSE_CELL;
    }
}

BoardCoordinate_t getNewCoordinate(MovementDirection_t movement_direction) {
    BoardCoordinate_t new_board_coordinate;
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
            new_board_coordinate.y--;
            break;
        case RIGHT:
            new_board_coordinate.x++;
            break;
        case DOWN:
            new_board_coordinate.y++;
            break;
    }
    return new_board_coordinate;
}
