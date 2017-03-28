#include "sensor.h"

Sensor::Sensor(int _offsetX, int _offsetY, Maze _mazeBoard) {
    offsetX = _offsetX;
    offsetY = _offsetY;
    mazeBoard = _mazeBoard;
}

bool Sensor::isWall(int mousePosX, int mousePosY, int mouseRotation) {
    bool result;
    if (mouseRotation == 0) {
        result = mazeBoard.isWall(mousePosX + offsetX, mousePosY - offsetY);
    } else if (mouseRotation == 1) {
        result = mazeBoard.isWall(mousePosX + offsetY, mousePosY + offsetX);
    } else if (mouseRotation == 2) {
        result = mazeBoard.isWall(mousePosX - offsetX, mousePosY + offsetY);
    } else if (mouseRotation == 3) {
        result = mazeBoard.isWall(mousePosX - offsetY, mousePosY - offsetX);
    }
}