#pragma once
#include "maze.h"
using namespace std;

class Sensor {
    int offsetX;
    int offsetY;
    Maze mazeBoard;
    public:
        Sensor(int _offsetX, int _offsetY, Maze _mazeBoard);
        bool isWall(int mousePosX, int mousePosY, int mouseRotation);
};

