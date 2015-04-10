#include <stdio.h>
#include <stdlib.h>
#include "common/ArrayUtils.h"
#include "common/Constants.h"
#include "services/world_builder/WorldReaderService.h"

void printBoard(Board board);

int main() {
    printf("DEBUG starting main\n");

    /*BoardCoordinate_t catCoord = {
            .x = 0,
            .y = 0
    };
    BoardCoordinate_t mouseCoord = {
            .x = 6,
            .y = 0
    };
    BoardCoordinate_t cheeseCoord = {
            .x = 5,
            .y = 4
    };

    Board board = make2dArray(BOARD_SIZE, BOARD_SIZE, sizeof(BoardCell_t *), sizeof(BoardCell_t));
    for (int j = 0; j < BOARD_SIZE; ++j) {
        for (int k = 0; k < BOARD_SIZE; ++k) {
            board[j][k] = EMPTY_CELL;
        }
    }
    board[0][0] = CAT_CELL;
    board[6][0] = MOUSE_CELL;
    board[5][4] = CHEESE_CELL;
    // Obstacaling
    board[1][0] = OBSTACLE_CELL;
    board[5][0] = OBSTACLE_CELL;

    World_t world = {
            .cheese_coordinates = cheeseCoord,
            .mouse_coordinates = mouseCoord,
            .cat_coordinates = catCoord,
            .board = board,
            .first_move = MOUSE
    };
    GameParams_t game_params = {
            .cat_player_type = HUMAN,
            .mouse_player_type = HUMAN,
            .cat_machine_difficulty = 7,
            .mouse_machine_difficulty = 7,
            .turns_bound = 10,
            .world = world
    };

    initNewGame(game_params);

    MovementDirection_t move_dir[10] = {
            LEFT, RIGHT, RIGHT, LEFT, UP, UP, UP, UP, UP, UP
    };
    for (int i = 0; i < 10; ++i) {
        BoardStatus_t move_result = performMove(move_dir[i]);
        if (move_result == MOUSE_WINS) {
            printf("MOUSE WINS!!!\n");
            break;
        } else if (move_result == CAT_WINS) {
            printf("CAT WINS!!!\n");
            break;
        } else if (move_result == INVALID) {
            printf("INVALID MOVE\n");
        } else if (move_result == DRAW) {
            printf("DRAW!!!\n");
            break;
        }
    }
    printBoard(getCurrentGameBoard().board);
*/
    World_t *world = (World_t *) malloc(sizeof(World_t));

    readWorldWithId(0, world);

    printBoard(world->board);

    return 0;
}

// This is for debugging purposes
void printBoard(Board board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            char cell_rep;
            switch(board[j][i]) { // I know this is reversed and it's OK
                case EMPTY_CELL: cell_rep = '0'; break;
                case CAT_CELL: cell_rep = 'C'; break;
                case MOUSE_CELL: cell_rep = 'M'; break;
                case OBSTACLE_CELL: cell_rep = 'X'; break;
                case CHEESE_CELL: cell_rep = 'P'; break;
                default: cell_rep = '?'; break;
            }
            printf("%c", cell_rep);
        }
        printf("\n");
    }
}