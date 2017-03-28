#pragma once
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <cstdio>
#include <ncurses.h>
#include <sstream>

using namespace std;
using namespace boost::filesystem;

class ApplicationUI {
    public:
        ApplicationUI();
        ~ApplicationUI();
        string showFileSelectionScreen(string dir);
        void displayMaze(vector<string> mazeBoard);
        void displayMouse(int x, int y, int rotation);
        void displayPath(int x, int y);
        void printInt(int x);
};

