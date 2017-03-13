#include "applicationui.h"

void ApplicationUI::clearScreen() {
#ifdef WINDOWS
    system("cls");
#else
    system ("clear");
#endif
}

string ApplicationUI::showFileSelectionScreen(string dir) {
    path directory (dir);
    vector<directory_entry> mazeFiles;
    int counter = 0;
    int selectedFile;
    
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
    
    return mazeFiles[selectedFile - 1].path().string();
}