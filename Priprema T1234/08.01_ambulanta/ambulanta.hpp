#ifndef AMBULANTA_HPP_INCLUDED
#define AMBULANTA_HPP_INCLUDED

#include "student.hpp"

using namespace std;

class Studentska_ambulanta {
private:
    Student& student;
    int brojMuskih, brojZenskih;
    enum StanjeAmbulantneProstorije { ZAUZETA = 0, SLOBODNA } stanjeAmbulantneProstorije[2];
    mutex m;
public:
    Studentska_ambulanta(Student& st, int muskih, int zenskih) : student(st), brojMuskih(muskih), brojZenskih(zenskih) {
        // Prosiriti po potrebi ...
        stanjeAmbulantneProstorije[0] = SLOBODNA;
        stanjeAmbulantneProstorije[1] = SLOBODNA;
    }

    // Metoda koju poziva nit koja simulira studenta u ambulanti kada student pokusava da udje u nju.
    // Ukoliko je ambulanta zauzeta, izvrsenje ove metode ce cekati da se ona oslobodi.
    //
    // rbr - Redni broj studenta
    // p   - Pol studenta
    //
    // Potrebno je pozvati metodu student.ceka kada student ne moze da stupi u ambulantu.
    // Potrebno je pozvati metodu student.ulazi kada student udje u ambulantu.
    void udji(int rbr, Pol p) {
        // Implementirati ...
        student.ceka(rbr, p);
        while(true) {
            unique_lock<mutex> lock(m);
            if(p == MUSKI) {
                if(stanjeAmbulantneProstorije[0] == SLOBODNA) {
                    stanjeAmbulantneProstorije[0] = ZAUZETA;
                    student.ulazi(rbr, p);
                    break;
                }
            } else if(p == ZENSKI) {
                if(stanjeAmbulantneProstorije[1] == SLOBODNA) {
                    stanjeAmbulantneProstorije[1] = ZAUZETA;
                    student.ulazi(rbr, p);
                    break;
                }
            }
        }
    }

    // Metoda koju poziva nit koja simulira studenta u ambulanti nakon sto je student pregledan i izlazi iz nje.
    //
    // rbr - Redni broj studenta
    // p   - Pol studenta
    void izadji(int rbr, Pol p) {
        // Implementirati ...
        unique_lock<mutex> lock(m);
        if(p == MUSKI) {
            stanjeAmbulantneProstorije[0] = SLOBODNA;
            brojMuskih--;
            student.izadji(rbr, p);
        } else if(p == ZENSKI) {
            stanjeAmbulantneProstorije[1] = SLOBODNA;
            brojZenskih--;
            student.izadji(rbr, p);
        }
    }
};

#endif // AMBULANTA_HPP_INCLUDED
