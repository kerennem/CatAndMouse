#include "CommonStructs.h"
#include "CommonEnums.h"
#include "Constants.h"

/**
* Checks whether given board coordinate is on the board.
*/
// TODO return type probably should be ModelReturnStatus_t, but how is this func used then? (no option to do (if isBoardCoordinateValid))
bool isBoardCoordinateValid(BoardCoordinate_t coordinate) {
    if (coordinate.x >= 0 && coordinate.x < BOARD_SIZE
            && coordinate.y >= 0 && coordinate.y < BOARD_SIZE) {
        return MODEL_INVALID_COORDINATE;
    }

}
