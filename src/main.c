#include <stdio.h>
#include "menu/main_menu/MainMenu.h"
#include "services/game/GameService.c"
#include "common/CommonEnums.h"

int main() {
    printf("DEBUG starting main\n");

    struct boardCoordinate catCoord = {
            .x = 0,
            .y = 0
    };
    struct boardCoordinate mouseCoord = {
            .x = 6,
            .y = 0
    };
    struct boardCoordinate cheeseCoord = {
            .x = 5,
            .y = 4
    };

    int board[7][7] = {0};
    board[0][0] = CAT_CELL;
    board[6][0] = MOUSE_CELL;
    board[5][4] = CHEESE_CELL;

    struct world world = {
            .cheese_coordinates = cheeseCoord,
            .mouse_coordinates = mouseCoord,
            .cat_coordinates = catCoord,
            .board = board
    };
    struct gameParams game_params = {
            .cat_player_type = HUMAN,
            .mouse_player_type = HUMAN,
            .cat_machine_difficulty = 7,
            .mouse_machine_difficulty = 7,
            .turns_bound = 10,
            .world = world
    };

    initNewGame(game_params);
    return 0;
}