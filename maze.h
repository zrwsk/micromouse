#pragma once
#include <string>
#include <vector>
#include<iostream>
#include<fstream>

using namespace std;

/**
 * \class Maze
 * 
 * \brief Klasa reprezentująca labirynt
 * 
 * Odpowiada za obsługę logiki labiryntu,
 * w szczególności wczytanie labiryntu oraz
 * sprawdzanie co znajduje się w labiryncie na danej pozycji.
 * 
 * \author Jakub Żurawski
 * 
 */
 
class Maze {
    vector<string> mazeBoard; ///< przechowuje wektor labiryntu
    public:
        /**
        * \brief Wczytanie labiryntu z pliku
        * \param filename relatywna ścieżka do pliku labiryntu
        * 
        * Funkcja wczytuje labirynt do wektora z podanego w parametrze pliku
        */
        void readFromFile(string filename);
        /**
        * \brief Pobranie pozycji startowej
        * \return Pozycja startowa myszy
        * 
        * Funckja zwraca wektor zawierający współrzędne startu
        * labiryntu [pozX, pozY]
        */
        vector<int> getStartPosition();
        /**
        * \brief Sprawdzenie czy pole jest końcem labiryntu
        * \param x położenie pola na osi x
        * \param y położenie pola na osi y
        * \return Zwraca true jeżeli podane pole jest końcem
        * 
        * Funkcja umożliwiająca sprawdzenie czy na danej pozycji (x, y)
        * znajduje się wyjście z labiryntu
        */
        bool isFinish(int x, int y);
        /**
        * \brief Sprawdzenie czy pole jest ścianą
        * \param x położenie pola na osi x
        * \param y położenie pola na osi y
        * \return Zwraca true jeżeli podane pole jest ścianą
        * 
        * Funkcja umożliwiająca sprawdzenie czy na danej pozycji (x, y)
        * znajduje się ściana labiiryntu
        */
        bool isWall(int x, int y);
        /**
        * \brief Pobranie całego wektora labiryntu
        * \return Wektor labiryntu
        * 
        * Funkcja zwraca wektor zawierający cały układ labiryntu.
        */
        vector<string> getMaze();
}; 

