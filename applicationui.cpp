#include "applicationui.h"
#include <cstdio>
ApplicationUI::ApplicationUI() {
    initscr();
    start_color();
    use_default_colors();
	init_pair(1, 0, COLOR_GREEN);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_WHITE);
	curs_set(0);
}

ApplicationUI::~ApplicationUI() {
    endwin();
}

string ApplicationUI::showFileSelectionScreen(string dir) {
    path directory (dir);
    vector<directory_entry> mazeFiles;
    int counter = 0;
    int selectedFile;
    char input[4];
    
    copy(directory_iterator(directory), directory_iterator(), back_inserter(mazeFiles));
    
    printw("Maze Solver v.1.0.0\n");
    printw("Wykonal: Jakub Zurawski\n\n");
    
    if (mazeFiles.size() == 0) {
        printw("Brak plików labiryntu, naciśnij dowolny klawisz aby zakończyć...\n");
        getchar();
        return 0;
    }
    
    printw("Wybierz plik labiryntu:\n");
    
    for (vector<directory_entry>::iterator it = mazeFiles.begin(); it != mazeFiles.end(); it++, counter++) {
        stringstream ss;
        ss << counter + 1 << ". " << it->path().stem().string() << endl;
        printw(ss.str().c_str());
    } 
    
    do {
        printw("\nWybor: \n");
        refresh();
        getstr(input);
        selectedFile = atoi(input);
        if (selectedFile > counter || selectedFile <= 0) {
            printw("Wybrano bledny numer pliku\n");
        }
    } while (selectedFile > counter || selectedFile <= 0);

    return mazeFiles[selectedFile - 1].path().string();
}

void ApplicationUI::displayMaze(vector<string> mazeBoard) {
    clear();
    attron(COLOR_PAIR(3));
    for (vector<string>::iterator it = mazeBoard.begin(); it != mazeBoard.end(); it++) {
        printw((*it).c_str());
        printw("\n");
        row++;
    } 
    attroff(COLOR_PAIR(3));
    refresh();
}

void ApplicationUI::displayMouse(int x, int y, int rotation) {
    string mouseSigns ="^>v<";
    attron(COLOR_PAIR(2));
    mvaddch(y, x, mouseSigns[rotation]);
    attroff(COLOR_PAIR(2));
    moveCursorOutsideMaze();
    refresh();
}

void ApplicationUI::displayPath(int x, int y) {
    attron(COLOR_PAIR(1));
    mvprintw(y, x, "*");
    attroff(COLOR_PAIR(1));
    moveCursorOutsideMaze();
    refresh();
}

void ApplicationUI::moveCursorOutsideMaze() {
    move(row, 0);
}