#pragma once
#include "maze.h"
using namespace std;

/**
 * \class Sensor
 * 
 * \brief Klasa reprezentująca sensor robota micromouse
 * 
 * Klasa reprezentuje sensor myszy. Sensor posiada ustalony
 * kierunek w którym bada obecność ściany. Na podstawie pozycji
 * myszy ustala czy w danym punkcie znajduje się ściana czy puste pole.
 * 
 * \author Jakub Żurawski
 * 
 */
 
 
class Sensor {
    int offsetX; ///< Pole na osi x które bada sensor (w odniesieniu do pozycji myszy)
    int offsetY; ///< Pole na osi y które bada sensor (w odniesieniu do pozycji myszy)
    Maze mazeBoard; ///< instancja labiryntu
    public:
        /**
        * \brief Konstruktor
        * 
        * Tworzy instancję sensora przekazując mu
        * offsety na osi X i Y oraz instancję wczytanego
        * labiryntu.
        */
        Sensor(int _offsetX, int _offsetY, Maze _mazeBoard);
        /**
        * \brief Funkcja zwracająca wartość sensora
        * \param mousePosX pozycja myszy w osi X
        * \param mousePosY pozycja myszy w osi Y
        * \param mouseRotation obrót myszy
        * \return Zwraca true jeżeli sensor wykryje ścianę
        * 
        * Funkcja na podstawie pozycji myszy zwraca wartość
        * sensora - w praktyce sprowadza się to do sprawdzenia
        * czy w danym kierunku 'patrzenia' sensora znajduje się ściana.
        */
        bool isWall(int mousePosX, int mousePosY, int mouseRotation);
};

