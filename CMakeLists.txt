cmake_minimum_required(VERSION 3.1)
project(CatAndMouse)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=C99")

set(SOURCE_FILES src/main.c src/common/ListUtils.c src/common/MiniMax.c src/menu/main_menu/MainMenu.c)
add_executable(CatAndMouse ${SOURCE_FILES} src/services/game/GameService.h src/services/game/BoardEvaluationService.h src/services/game/BoardEvaluationService.c src/services/game/BoardEvaluationService.h src/services/game/BoardEvaluationService.c src/common/CommonStructs.h src/common/CommonEnums.h)