cmake_minimum_required(VERSION 3.1)
project(CatAndMouse)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=C99")

set(SOURCE_FILES src/main.c src/common/ListUtils.c src/common/MiniMax.c src/menu/main_menu/MainMenu.c)
add_executable(CatAndMouse ${SOURCE_FILES} src/services/game/BoardEvaluationService.h src/services/game/BoardEvaluationService.c src/services/game/BoardEvaluationService.h src/services/game/BoardEvaluationService.c src/common/CommonStructs.h src/common/CommonEnums.h src/services/world_builder/WorldsService.h src/services/world_builder/WorldsService.c src/common/ArrayUtils.h src/common/ArrayUtils.c src/controllers/MainMenuController.h src/controllers/MainMenuController.c src/controllers/NewGameController.h src/controllers/NewGameController.c src/controllers/GameController.h src/controllers/GameController.c src/controllers/LoadGameController.h src/controllers/LoadGameController.c src/models/WorldModel.h src/models/WorldModel.c src/common/Constants.h src/common/CommonStructs.c src/controllers/WorldCreatorController.h src/controllers/WorldCreatorController.c src/services/world_builder/WorldReaderService.h src/services/world_builder/WorldReaderService.c src/models/GameModel.h src/models/GameModel.c)

add_definitions(-std=c99)