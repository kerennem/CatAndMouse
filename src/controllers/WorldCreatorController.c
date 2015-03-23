#include "WorldCreatorController.h"
#include "../models/WorldCreatorModel.h"

ControllerReturnStatus_t saveWorld() {
    ControllerReturnStatus_t res;
    switch(isWorldValid()) {
        case MODEL_CAT_IS_MISSING: res = CONTROLLER_CAT_IS_MISSING; break;
        case MODEL_MOUSE_IS_MISSING: res = CONTROLLER_MOUSE_IS_MISSING; break;
        case MODEL_CHEESE_IS_MISSING: res = CONTROLLER_CHEESE_IS_MISSING; break;
        default: res = CONTROLLER_OK; break;
    }

    if (res == CONTROLLER_OK) {
        // TODO implement save to disk logic
    }
    
    return res;
}

ControllerReturnStatus_t goToMainMenuFromWorldCreator() {
    return CONTROLLER_OK;
}

ControllerReturnStatus_t quitProgramFromWorldCreator() {
    return CONTROLLER_OK;
}

ControllerReturnStatus_t placeMouseClicked(BoardCoordinate_t coordinate) {
    placeMouse(coordinate);
    return CONTROLLER_OK;
}

ControllerReturnStatus_t placeCatClicked(BoardCoordinate_t coordinate) {
    placeCat(coordinate);
    return CONTROLLER_OK;
}

ControllerReturnStatus_t placeCheeseClicked(BoardCoordinate_t coordinate) {
    placeCheese(coordinate);
    return CONTROLLER_OK;
}

ControllerReturnStatus_t placeObstacleClicked(BoardCoordinate_t coordinate) {
    placeObstacle(coordinate);
    return CONTROLLER_OK;
}

ControllerReturnStatus_t placeEmptyCellClicked(BoardCoordinate_t coordinate) {
    placeEmptyCell(coordinate);
    return CONTROLLER_OK;
}