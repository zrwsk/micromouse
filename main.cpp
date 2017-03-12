#include<iostream>
#include<fstream>

#include "applicationui.h"

using namespace std;

int main() {
    ApplicationUI ui;
    
    ui.clearScreen();
    
    string fileName = ui.showFileSelectionScreen("./maze_files");
    
    vector<string> mazeBoard;
    int counter = 0;
    ifstream mazeFileStream;
    
    mazeFileStream.open(fileName.c_str());
    
    string line;
    
    while (getline(mazeFileStream, line)) {
        mazeBoard.push_back(line);
    }
    
    ui.clearScreen();
    
    for (vector<string>::iterator it = mazeBoard.begin(); it != mazeBoard.end(); it++) {
        cout << *it << endl;
    } 
}
