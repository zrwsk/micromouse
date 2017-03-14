#include "applicationui.h"
#include "maze.h"

using namespace std;

int main() {
    ApplicationUI ui;
    Maze maze;
    
    ui.clearScreen();
    string filename = ui.showFileSelectionScreen("./maze_files");
    
    maze.readFromFile(filename);
    
    vector<int> startPosition;
    startPosition = maze.getStartPosition();
    
    cout << startPosition[0] << endl;
    cout << startPosition[1] << endl;
}
