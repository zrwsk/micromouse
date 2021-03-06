#include "maze.h"

void Maze::readFromFile(string filename) {
    ifstream mazeFileStream;
    string line;
    
    mazeFileStream.open(filename.c_str());
    
    while (getline(mazeFileStream, line)) {
        mazeBoard.push_back(line);
    }
}

vector<int> Maze::getStartPosition() {
    vector<int> position {0,0};
    
    for (vector<string>::iterator it = mazeBoard.begin(); it != mazeBoard.end(); it++) {
        size_t found = (*it).find('s');
        if (found != string::npos) {
            position[0] = found;
            break;
        }
        position[1]++;
    } 
    return position;
}

vector<string> Maze::getMaze() {
    return mazeBoard;
}

bool Maze::isFinish(int x, int y) {
    if (mazeBoard[y][x] == 'e') {
        return true;
    } else {
        return false;
    }
}

bool Maze::isWall(int x, int y) {
    if (mazeBoard[y][x] == '#') {
        return true;
    } else {
        return false;
    }
}