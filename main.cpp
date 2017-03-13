#include "applicationui.h"
#include "maze.h"

using namespace std;

int main() {
    ApplicationUI ui;
    Maze maze;
    
    ui.clearScreen();
    string filename = ui.showFileSelectionScreen("./maze_files");
    
    maze.readFromFile(filename);
    
    // for (vector<string>::iterator it = mazeBoard.begin(); it != mazeBoard.end(); it++) {
    //     cout << *it << endl;
    // } 
}
