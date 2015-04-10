#include <stddef.h>
#include <w32api/winsnmp.h>
#include <malloc.h>
#include "WorldModel.h"
#include "../common/ArrayUtils.h"
#include "../common/Constants.h"

static Board current_board;
static BoardCoordinate_t *current_cat_coordinates;
static BoardCoordinate_t *current_mouse_coordinates;
static BoardCoordinate_t *current_cheese_coordinates;
static PlayerName_t *first_move;
static int turns_bound;

void setWorldFirstMove(PlayerName_t player_name);

void placePieceOnBoard(BoardCell_t board_cell, BoardCoordinate_t *current_coordinates, BoardCoordinate_t new_coordinates);

void checkImportantPieces(BoardCoordinate_t coordinate);

World_t getWorld() {
    World_t dst_world;
    Board dst_board = (Board) make2dArray(BOARD_SIZE, BOARD_SIZE, sizeof(BoardCell_t *), sizeof(BoardCell_t));
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            dst_board[i][j] = current_board[i][j];
        }
    }
    dst_world.board = dst_board;
    dst_world.mouse_coordinates = *current_mouse_coordinates;
    dst_world.cat_coordinates = *current_cat_coordinates;
    dst_world.cheese_coordinates = *current_cheese_coordinates;
    dst_world.first_move = *first_move;
    dst_world.turns_bound = turns_bound;

    return dst_world;
}

ModelReturnStatus_t setWorld(World_t world) {
    if (world.board == NULL) {
        return MODEL_PARAMETER_IS_NULL;
    }
    if (current_board != NULL) {
        free2dArray(BOARD_SIZE, BOARD_SIZE, current_board);
    }
    current_board = (Board) make2dArray(BOARD_SIZE, BOARD_SIZE, sizeof(BoardCell_t *), sizeof(BoardCell_t));

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            current_board[i][j] = world.board[i][j];
        }
    }

    *current_cat_coordinates = world.cat_coordinates;
    *current_mouse_coordinates = world.mouse_coordinates;
    *current_cheese_coordinates = world.cheese_coordinates;
    *first_move = world.first_move;
    turns_bound = world.turns_bound;
    return MODEL_OK;
}

ModelReturnStatus_t placeMouse(BoardCoordinate_t coordinate) {
    if (!isBoardCoordinateValid(coordinate)) {
        return MODEL_INVALID_COORDINATE;
    }
    checkImportantPieces(coordinate);

    placePieceOnBoard(MOUSE_CELL, current_mouse_coordinates, coordinate);

    setWorldFirstMove(MOUSE);

    return MODEL_OK;
}

ModelReturnStatus_t placeCat(BoardCoordinate_t coordinate) {
    if (!isBoardCoordinateValid(coordinate)) {
        return MODEL_INVALID_COORDINATE;
    }
    checkImportantPieces(coordinate);

    placePieceOnBoard(CAT_CELL, current_cat_coordinates, coordinate);

    setWorldFirstMove(CAT);

    return MODEL_OK;
}

ModelReturnStatus_t placeCheese(BoardCoordinate_t coordinate) {
    if (!isBoardCoordinateValid(coordinate)) {
        return MODEL_INVALID_COORDINATE;
    }
    checkImportantPieces(coordinate);

    placePieceOnBoard(CHEESE_CELL, current_cheese_coordinates, coordinate);

    return MODEL_OK;
}

ModelReturnStatus_t placeObstacle(BoardCoordinate_t coordinate) {
    if (!isBoardCoordinateValid(coordinate)) {
        return MODEL_INVALID_COORDINATE;
    }

    checkImportantPieces(coordinate);

    current_board[coordinate.x][coordinate.y] = OBSTACLE_CELL;

    return MODEL_OK;
}

ModelReturnStatus_t placeEmptyCell(BoardCoordinate_t coordinate) {
    if (!isBoardCoordinateValid(coordinate)) {
        return MODEL_INVALID_COORDINATE;
    }

    checkImportantPieces(coordinate);

    current_board[coordinate.x][coordinate.y] = EMPTY_CELL;

    return MODEL_OK;
}

void checkImportantPieces(BoardCoordinate_t coordinate) {
    switch (current_board[coordinate.x][coordinate.y]) {
        case MOUSE_CELL:
            current_mouse_coordinates = NULL;
            if (*first_move == MOUSE) {
                first_move = NULL;
            }
            break;
        case CAT_CELL:
            current_cat_coordinates = NULL;
            if (*first_move == CAT) {
                first_move = NULL;
            }
            break;
        case CHEESE_CELL:
            current_cheese_coordinates = NULL;
            break;
        default:
            break;
    }

}

void placePieceOnBoard(BoardCell_t board_cell, BoardCoordinate_t *current_coordinates, BoardCoordinate_t new_coordinates) {
    if (current_coordinates->x != NULL) {
        current_board[current_coordinates->x][current_coordinates->y] = EMPTY_CELL;
    }
    current_coordinates->x = new_coordinates.x;
    current_coordinates->y = new_coordinates.y;
    current_board[current_coordinates->x][current_coordinates->y] = board_cell;
}

ModelReturnStatus_t isWorldValid() {
    bool isCatFound = false, isMouseFound = false, isCheeseFound = false;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            switch (current_board[i][j]) {
                case MOUSE_CELL:
                    isMouseFound = true;
                    break;
                case CAT_CELL:
                    isCatFound = true;
                    break;
                case CHEESE_CELL:
                    isCheeseFound = true;
                    break;
                default:
                    break;
            }
        }
    }

    if (!isCatFound) {
        return MODEL_CAT_IS_MISSING;
    }
    if (!isMouseFound) {
        return MODEL_MOUSE_IS_MISSING;
    }
    if (!isCheeseFound) {
        return MODEL_CHEESE_IS_MISSING;
    }

    return MODEL_OK;
}

void setWorldFirstMove(PlayerName_t player_name) {
    *first_move = player_name;
}

