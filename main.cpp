#include "applicationui.h"
#include "maze.h"
#include "mouse.h"

using namespace std;

int main() {
    ApplicationUI ui;
    Maze maze;

    string filename = ui.showFileSelectionScreen("./maze_files");
    
    maze.readFromFile(filename);
    ui.displayMaze(maze.getMaze());
    
    Mouse mouse(maze, ui);
    mouse.solveRightHand();
}
