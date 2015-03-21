#include <stdlib.h>
#include "WorldsService.h"
#include "../game/GameService.h"
#include "../../common/ArrayUtils.h"

BoardCell_t** getBoardFrom(World_t world) {
    BoardCell_t** src_board = world.board;
    BoardCell_t **dst_board = make2dArray(BOARD_SIZE, BOARD_SIZE, sizeof(BoardCell_t *), sizeof(BoardCell_t));

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            dst_board[i][j] = src_board[i][j];
        }
    }

    return dst_board;
}