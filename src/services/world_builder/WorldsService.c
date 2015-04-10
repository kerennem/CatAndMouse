#include <stdlib.h>
#include <stdbool.h>
#include "WorldsService.h"
#include "../../common/ArrayUtils.h"
#include "../../common/Constants.h"

Board getBoardFrom(World_t world) {
    Board src_board = world.board;
    Board dst_board = (Board) make2dArray(BOARD_SIZE, BOARD_SIZE, sizeof(BoardCell_t *), sizeof(BoardCell_t));

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            dst_board[i][j] = src_board[i][j];
        }
    }

    return dst_board;
}

ServiceReturnStatus_t setCatCoordinate(World_t *world, BoardCoordinate_t coord) {
    if (coord.x >= 0 && coord.x < BOARD_SIZE
            && coord.y >= 0 && coord.y < BOARD_SIZE) {
        BoardCoordinate_t current_cat_coordinates = world->cat_coordinates;
        world->board[current_cat_coordinates.x][current_cat_coordinates.y] = EMPTY_CELL;
        world->board[coord.x][coord.y] = CAT_CELL;
        world->cat_coordinates = coord;
        world->first_move = CAT;

        return OK;
    } else {
        return COORDINATE_OUT_OF_BOUNDS;
    }
}

ServiceReturnStatus_t setMouseCoordinate(World_t *world, BoardCoordinate_t coord) {
    if (coord.x >= 0 && coord.x < BOARD_SIZE
            && coord.y >= 0 && coord.y < BOARD_SIZE) {
        BoardCoordinate_t current_mouse_coordinates = world->mouse_coordinates;
        world->board[current_mouse_coordinates.x][current_mouse_coordinates.y] = EMPTY_CELL;
        world->board[coord.x][coord.y] = MOUSE_CELL;
        world->mouse_coordinates = coord;
        world->first_move = MOUSE;

        return OK;
    } else {
        return COORDINATE_OUT_OF_BOUNDS;
    }
}

ServiceReturnStatus_t setCheeseCoordinate(World_t *world, BoardCoordinate_t coord) {
    if (coord.x >= 0 && coord.x < BOARD_SIZE
            && coord.y >= 0 && coord.y < BOARD_SIZE) {
        BoardCoordinate_t current_cheese_coordinates = world->cheese_coordinates;
        world->board[current_cheese_coordinates.x][current_cheese_coordinates.y] = EMPTY_CELL;
        world->board[coord.x][coord.y] = CHEESE_CELL;
        world->cheese_coordinates = coord;

        return OK;
    } else {
        return COORDINATE_OUT_OF_BOUNDS;
    }
}

ServiceReturnStatus_t setFirstMove(World_t *world, PlayerName_t player_name) {
    world->first_move = player_name;
}

bool validateWorld(World_t *world) {
    if (world->first_move == NULL) {
        return false;
    }
    // TODO find out how to check that a struct exists - *****should probably save a pointer to structs*****
    if ((world->cat_coordinates.x < 0 && world->cat_coordinates.x >= BOARD_SIZE) ||
            (world->cat_coordinates.y < 0 && world->cat_coordinates.y >= BOARD_SIZE)) {
        return false;
    }
    if ((world->mouse_coordinates.x < 0 && world->mouse_coordinates.x >= BOARD_SIZE) ||
            (world->mouse_coordinates.y < 0 && world->mouse_coordinates.y >= BOARD_SIZE)) {
        return false;
    }
    if ((world->cheese_coordinates.x < 0 && world->cheese_coordinates.x >= BOARD_SIZE) ||
            (world->cheese_coordinates.y < 0 && world->cheese_coordinates.y >= BOARD_SIZE)) {
        return false;
    }
    Board board = world->board;

    bool isCatFound = false, isMouseFound = false, isCheeseFound = false;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            switch (board[i][j]) {
                case MOUSE_CELL: isMouseFound = true; break;
                case CAT_CELL: isCatFound = true; break;
                case CHEESE_CELL: isCheeseFound = true; break;
                default: break;
            }
        }
    }

    return (isCatFound && isMouseFound && isCheeseFound);
}
