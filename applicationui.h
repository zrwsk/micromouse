#pragma once
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <cstdio>
#include <ncurses.h>
#include <sstream>

using namespace std;
using namespace boost::filesystem;

/**
 * \class ApplicationUI
 * 
 * \brief Klasa odpowiadająca za interfejs użytkownika
 * 
 * Klasa odpowiada za wyświetlanie interfejsu użytkownika,
 * w szczególności menu wyboru pliku labiryntu, samego labiryntu
 * oraz wyświetlanie pozycji myszy i jej ścieżki.
 * 
 * \author Jakub Żurawski
 * 
 */
 
class ApplicationUI {
    int row; ///< dostępna ilość rzędów terminala
    int col; ///< dostępna ilość kolumn terminala
    /**
     * \brief Odstawia kursor w dolny prawy róg
     * 
     * Ponieważ metoda curs_set z biblioteki ncurses
     * nie działa prawidłowo we wszystkich terminalach,
     * aby kursor nie był widoczny na wizualizacji
     * jest on odstawiany w róg ekranu
     */
    void moveCursorToRightBottomCorner(); 
    public:
        /**
        * \brief Konstruktor
        * 
        * Tworzy instancję interfejsu użytkownika.
        * Jego głównym zadaniem jest inicjalizacja biblioteki ncurses
        * odpowiadającej za wyświetlanie
        */
        ApplicationUI();
        /**
        * \brief Destruktor
        * 
        * Kończy okno utworzone przez bibliotekę ncurses.
        */
        ~ApplicationUI();
        /**
        * \brief Wyświetla ekran startowy
        * \param dir folder zawierający pliki labiryntu
        * 
        * Funkcja wyświetla ekran startowy, będący monitem
        * wyboru labiryntu do przejścia. Pliki labiryntu listowane
        * są na podstawie przekazanego katalogu.
        */
        string showFileSelectionScreen(string dir);
        /**
        * \brief Wyświetla labirynt
        * \param mazeBoard wektor zawierający strukturę labiryntu
        * 
        * Funkcja wyświetla labirynt na podstawie zaczytanego z pliku
        * labiryntu wektora.
        */
        void displayMaze(vector<string> mazeBoard);
        /**
        * \brief Wyświetla mysz
        * \param x pozycja myszy na osi x
        * \param y pozycja myszy na osi y
        * \param rotation obrót myszy
        * 
        * Funkcja wyświetla reprezentację graficzną robota micromouse
        * poruszającego się w labiryncie.
        */
        void displayMouse(int x, int y, int rotation);
        /**
        * \brief Wyświetla ślad robota micromouse
        * \param x historyczna pozycja myszy na osi x
        * \param y historyczna pozycja myszy na osi y
        * 
        * Funkcja wyświetla ślad robota micromouse. Oznacza ona
        * pola które robot odwiedził wcześniej podczas swojej wędrówki
        * przez labirynt.
        */
        void displayPath(int x, int y);
};

