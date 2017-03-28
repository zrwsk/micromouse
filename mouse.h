#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "sensor.h"
#include "applicationui.h"
#include "maze.h"

using namespace std;

class Mouse {
    int positionX;
    int positionY;
    int rotation;
    vector<Sensor> sensors;
    Maze mazeBoard;
    ApplicationUI ui;
    void addSensor(int offsetX, int offsetY, Maze mazeBoard);
    void moveForward();
    void turnLeft();
    void turnRight();
    bool isOnFinish();
    public:
        Mouse(Maze _mazeBoard, ApplicationUI _ui);
        void solveRightHand();
}; 

