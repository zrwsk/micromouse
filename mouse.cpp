#include "mouse.h"

Mouse::Mouse(Maze _mazeBoard, ApplicationUI _ui) {
    mazeBoard = _mazeBoard;
    ui = _ui;
    
    vector<int> startPosition;
    startPosition = mazeBoard.getStartPosition();
    
    positionX = startPosition[0];
    positionY = startPosition[1];
    rotation = 0;

    ui.displayMouse(positionX, positionY, rotation);
}

void Mouse::addSensor(int offsetX, int offsetY, Maze mazeBoard) {
    Sensor sensor( offsetX, offsetY, mazeBoard);
    sensors.push_back(sensor);
}

void Mouse::solveRightHand() {
    this->addSensor(1, 0, mazeBoard); //sensor 0
    this->addSensor(0, 1, mazeBoard); //sensor 1
    // while (!this->isOnFinish()) {
    // if (sensors[0].isWall(positionX, positionY, rotation)) {
    //   this->moveForward();
    // }
    // }
    while (!this->isOnFinish()) {
        if (!sensors[0].isWall(positionX, positionY, rotation)) {
            this->turnRight();
            this->moveForward();
        } else if (!sensors[1].isWall(positionX, positionY, rotation)) {
            this->moveForward();
        } else {
            this->turnLeft();
            this->moveForward();
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void Mouse::turnRight() {
    if (this->rotation < 3) {
        this->rotation++;
    } else {
        this->rotation = 0;
    }
    ui.displayMouse(positionX, positionY, rotation);
}

void Mouse::turnLeft() {
    if (this->rotation > 0) {
        this->rotation--;
    } else {
        this->rotation = 3;
    }
    ui.displayMouse(positionX, positionY, rotation);
}

void Mouse::moveForward() {
    ui.displayPath(positionX, positionY);
    if (this->rotation == 0) {
        positionY--;
    } else if (this->rotation == 1) {
        positionX++;
    } else if (this->rotation == 2) {
        positionY++;
    } else if (this->rotation == 3) {
        positionX--;
    }
    ui.displayMouse(positionX, positionY, rotation);
}

bool Mouse::isOnFinish() {
    return mazeBoard.isFinish(positionX, positionY);
}