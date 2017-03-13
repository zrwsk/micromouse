#include "maze.h"

void Maze::readFromFile(string filename) {
    ifstream mazeFileStream;
    string line;
    
    mazeFileStream.open(filename.c_str());
    
    while (getline(mazeFileStream, line)) {
        mazeBoard.push_back(line);
    }
}