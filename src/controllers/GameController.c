#include "GameController.h"
#include "../models/GameModel.h"

//TODO implement functions
ControllerReturnStatus_t reconfigureMouse() {
    return CONTROLLER_OK;
}

ControllerReturnStatus_t reconfigureCat() {
    return CONTROLLER_OK;
}

ControllerReturnStatus_t goToMainMenu() {
    return CONTROLLER_OK;
}

ControllerReturnStatus_t restartGame() {
    return CONTROLLER_OK;
}

ControllerReturnStatus_t quitProgram() {
    return CONTROLLER_OK;
}

/**
* performs a move to an adjacent cell according to given movement direction
*/
BoardStatus_t performMoveToDirection(MovementDirection_t movement_direction) {
    return performMove(movement_direction);
}

/**
* performs a move to given coordinate.
* If coordinate isn't adjacent if current player's cell, the function returns an invalid move status.
*/
ControllerReturnStatus_t performMoveToCoordinate(BoardCoordinate_t selected_coordinates) {
    GameBoard_t game_board = getCurrentGameBoard();
    Board board = game_board.board;
    BoardCoordinate_t current_player_coordinates;
    if (game_board.current_turn == CAT) { // checks who is the current player
        current_player_coordinates = getCatCoordinates();
    } else {
        current_player_coordinates = getMouseCoordinates();
    }

    MovementDirection_t movement_direction;
    if (selected_coordinates.x == current_player_coordinates.x) {
        if (selected_coordinates.y == current_player_coordinates.y + 1) {
            movement_direction = UP;
        } else if (selected_coordinates.y == current_player_coordinates.y - 1) {
            movement_direction = DOWN;
        } else {
            return CONTROLLER_INVALID_MOVE;
        }
    } else if (selected_coordinates.y == current_player_coordinates.y) {
        if (selected_coordinates.x == current_player_coordinates.x + 1) {
            movement_direction = RIGHT;
        } else if (selected_coordinates.x == current_player_coordinates.x - 1) {
            movement_direction = LEFT;
        } else {
            return CONTROLLER_INVALID_MOVE;
        }
    }

    return performMoveToDirection(movement_direction);
}

// TODO why is this needed?
GameBoard_t retrieveCurrentGameBoard() {
    return getCurrentGameBoard();
}