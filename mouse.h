#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "sensor.h"
#include "applicationui.h"
#include "maze.h"

using namespace std;

/**
 * \class Mouse
 * 
 * \brief Klasa reprezentująca robota Micromouse
 * 
 * Klasa przechowująca informacje na temat myszy
 * poruszającej się w labiryncie. Pozwala na poruszanie się
 * myszy po labiryncie, dodawanie sensorów do myszy a także
 * zawiera implementację algorytmu przejścia labiryntu 
 * (aktualnie jest to algorytm prawej ręki).
 * 
 * \note Klasa może być rozszerzona o inne algorytmy.
 * 
 * \author Jakub Żurawski
 * 
 */

class Mouse {
    int positionX; ///< pozycja myszy na osi X
    int positionY; ///< pozycja myszy na osi Y
    int rotation; ///< obrót myszy
    vector<Sensor> sensors; ///< Wektor sensorów myszy
    Maze mazeBoard; ///< Instancja labiryntu
    ApplicationUI ui; ///< Instancja klasy odpowiedzialnej za wyświetlanie
    /**
     * \brief Metoda dodająca sensory
     * \param offsetX liczba reprezentująca offset sensora na osi X
     * \param offsetY liczba reprezentująca offset sensora na osi Y
     * \param mazeBoard instancja labiryntu
     * 
     * Metoda ta pozwala na dodanie sensorów do myszy,
     * równocześnie pozwalając określić kierunek w którym
     * sensory będą patrzeć poprzez offsety na osi X i Y.
     */
    void addSensor(int offsetX, int offsetY); 
    /**
     * \brief Metoda sprawdzająca wartość sensora sensora
     * \param sensorNumber numer sensora
     * \return Metoda zwraca true, gdy sensor widzi ścianę.
     * 
     * Sprawdza wartość sensora zwracając true jeżeli 
     * sensor widzi scianę.
     */
    bool checkSensor(int sensorNumber);
    void moveForward(); ///< Ruch myszy w przód
    void turnLeft(); ///< Skręt myszy w lewo
    void turnRight(); ///< Skręt myszy w prawo
    /**
     * \brief Sprawdzenie końca wyjścia z labiryntu
     * \return Metoda zwraca true gdy mysz doszła do końca labiryntu
     * 
     * Metoda ta sprawdza czy mysz doszła do końca labiryntu.
     */
    bool isOnFinish();
    public:
        /**
         * \brief Konstruktor
         * \param _mazeBoard instancja labiryntu
         * \param _ui instancja klasy odpowiadającej za wyświetlanie
         * 
         * Konstruktor tworzy instację myszy przekazując jej instancję
         * labiryntu do rozwiązania oraz klasę wyświetlającą
         */
        Mouse(Maze _mazeBoard, ApplicationUI _ui);
        /**
         * \brief Algorytm prawej ręki
         * 
         * Rozpoczyna rozwiązywanie labiryntu metodą prawej ręki
         */
        void solveRightHand();
        
}; 

