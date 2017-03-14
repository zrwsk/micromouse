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
}; 

