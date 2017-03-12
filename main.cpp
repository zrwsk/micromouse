#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include<iostream>
#include<fstream>

using namespace std;
using namespace boost::filesystem;

void clearScreen() {
#ifdef WINDOWS
    system("cls");
#else
    system ("clear");
#endif
}

int main() {
    path directory ("./maze_files");
    vector<directory_entry> mazeFiles;
    vector<vector<char>> mazeArray;
    int counter = 0;
    int selectedFile;
    ifstream mazeFileStream;
    
    copy(directory_iterator(directory), directory_iterator(), back_inserter(mazeFiles));
    
    clearScreen();
    cout << "Maze Solver v.1.0.0" << endl;
    cout << "Wykonał: Jakub Żurawski" << endl;
    cout << endl;
    
    if (mazeFiles.size() == 0) {
        cout << "Brak plików labiryntu, naciśnij dowolny klawisz aby zakończyć..." << endl;
        getchar();
        return 0;
    }
    
    cout << "Wybierz plik labiryntu:" << endl;
    
    for (vector<directory_entry>::iterator it = mazeFiles.begin(); it != mazeFiles.end(); it++, counter++) {
        cout << counter + 1 << ". " << it->path().stem().string() << endl;
    } 
    
    do {
        cout << endl << "Wybór: ";
        cin >> selectedFile;
        
        if (selectedFile > counter || selectedFile <= 0) {
            cout << "Wybrano błędny numer pliku";
        }
    } while (selectedFile > counter || selectedFile <= 0);
    
    mazeFileStream.open(mazeFiles[selectedFile - 1].path().string());
    

    cout << mazeFileStream.get();
}
