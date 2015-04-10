#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <stdlib.h>
#include "WorldReaderService.h"
#include "../../common/Constants.h"
#include "../../common/ArrayUtils.h"

static const char WORLDS_FILE_PATH[] = "C:\\temp\\worlds";

char *readNextLine(FILE *file);

ServiceReturnStatus_t processFirstMove(World_t *world, FILE *world_file);

ServiceReturnStatus_t processBoard(World_t *world, FILE *world_file);

ServiceReturnStatus_t produceBoardRowFromLine(Board board, char *line, int line_num);

ServiceReturnStatus_t readWorldWithId(int id, World_t* world) {
    char world_file_path[100]; // TODO How long should this string be?
    sprintf(world_file_path, "%s\\world_%d.txt", WORLDS_FILE_PATH, id);
    FILE *world_file = fopen(world_file_path, "r");

    if (world_file != NULL) {
        char* turns_bound = strtok(readNextLine(world_file), "\r");
        world->turns_bound = atoi(turns_bound); // TODO add validation ( > 0)

        ServiceReturnStatus_t first_move_status = processFirstMove(world, world_file);
        if (first_move_status == SERVICE_INVALID_WORLD_FILE_FIRST_MOVE) {
            return SERVICE_INVALID_WORLD_FILE_FIRST_MOVE;
        }

        ServiceReturnStatus_t board_status = processBoard(world, world_file);
        if (board_status == SERVICE_INVALID_WORLD_FILE_BOARD) {
            return SERVICE_INVALID_WORLD_FILE_BOARD;
        }

        fclose(world_file);
        return SERVICE_OK;
    } else {
        return SERVICE_WORLD_FILE_NOT_FOUND;
    }
}

ServiceReturnStatus_t processBoard(World_t *world, FILE *world_file) {
    Board board = (Board) make2dArray(BOARD_SIZE, BOARD_SIZE, sizeof(BoardCell_t *), sizeof(BoardCell_t));
    char* line = NULL;
    int row_index = 0;
    while ((line = readNextLine(world_file)) != NULL) {
        line = strtok(line, "\r");
        if (produceBoardRowFromLine(board, line, row_index) == SERVICE_INVALID_WORLD_FILE_BOARD) {
            return SERVICE_INVALID_WORLD_FILE_BOARD;
        }
        row_index++;
    }
    world->board = board;

    return SERVICE_OK;
}

ServiceReturnStatus_t produceBoardRowFromLine(Board board, char *line, int line_num) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        switch (line[i]) {
            case 'M': board[line_num][i] = MOUSE_CELL; break;
            case 'C': board[line_num][i] = CAT_CELL; break;
            case 'P': board[line_num][i] = CHEESE_CELL; break;
            case 'W': board[line_num][i] = OBSTACLE_CELL; break;
            case '#': board[line_num][i] = EMPTY_CELL; break;
            default: return SERVICE_INVALID_WORLD_FILE_BOARD;
        }
    }

    return SERVICE_OK;
}

ServiceReturnStatus_t processFirstMove(World_t *world, FILE *world_file) {
    char* first_move = strtok(readNextLine(world_file), "\r");
    if (strcmp(first_move, "mouse") == 0) {
            world->first_move = MOUSE;
        } else if (strcmp(first_move, "cat") == 0) {
            world->first_move = CAT;
        } else {
            return SERVICE_INVALID_WORLD_FILE_FIRST_MOVE;
        }
}

char *readNextLine(FILE *file) {
    if (file != NULL) {
        ssize_t read_size;
        char *line = NULL;
        size_t len = 0;
        read_size = getline(&line, &len, file);

        if (read_size != -1) {
            return line;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}
