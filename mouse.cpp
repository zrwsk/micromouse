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

void Mouse::addSensor(int offsetX, int offsetY) {
    Sensor sensor( offsetX, offsetY, mazeBoard);
    sensors.push_back(sensor);
}

bool Mouse::checkSensor(int sensorNumber) {
    return sensors[sensorNumber].isWall(positionX, positionY, rotation);
}

void Mouse::solveRightHand() {
    this->addSensor(1, 0); //sensor 0 z prawej
    this->addSensor(0, 1); //sensor 1 z góry
    this->addSensor(-1, 0); //sensor 2 z lewej
    // while (!this->isOnFinish()) {
    // if (sensors[0].isWall(positionX, positionY, rotation)) {
    //   this->moveForward();
    // }
    // }
    while (!this->isOnFinish()) {
        this_thread::sleep_for(chrono::milliseconds(1000));
        
        if (!checkSensor(0)) {
            this->turnRight();
        } else if (!checkSensor(1)) {
            //nie rób nic
        } else if (!checkSensor(2)) {
            this->turnLeft();
        } else {
            //zawrócenie
            this->turnRight();
            this->turnRight();
        }

        this->moveForward();
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