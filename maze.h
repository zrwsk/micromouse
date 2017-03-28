#pragma once
#include <string>
#include <vector>
#include<iostream>
#include<fstream>

using namespace std;

class Maze {
    vector<string> mazeBoard;
    public:
        void readFromFile(string filename);
        vector<int> getStartPosition();
        bool isFinish(int x, int y);
        bool isWall(int x, int y);
        vector<string> getMaze();
}; 

