#ifndef PARKING_HPP_INCLUDED
#define PARKING_HPP_INCLUDED

#include "automobil.hpp"

using namespace std;

class Parking {
private:
    Automobil& automobil;
    bool izasao;
    mutex m;
public:
    Parking(Automobil& a) : automobil(a), izasao(true) {
        // Proširiti po potrebi ...
    }

    // Metoda koju poziva nit koja simulira kretanje automobila kako bi automobil pokušao da se parkira.
    // Ako je parking zauzet, izvršenje ove metode će trajati dok se parking ne oslobodi i auto se parkira.
    //
    // rbr - Redni broj automobila
    //
    // Potrebno je pozvati metodu automobil.ceka kada je parking zauzet i auto mora da čeka.
    // Potrebno je pozvati metodu automobil.parkira kada auto uspe da se parkira.
    void udji(int rbr) {
        automobil.ceka(rbr);
        while(true) {
            unique_lock<mutex> lock(m);
            if(izasao == true) {
                izasao = false;
                automobil.parkira(rbr);
                break;
            }
        }
        // Implementirati ...
    }

    // Metoda koju poziva nit koja simulira kretanje automobila kada auto izlazi sa parkinga (nakon što je bio parkiran).
    //
    // rbr - Redni broj automobila
    //
    // Potrebno je pozvati metodu automobil.napusta kada auto napušta parking mesto.
    void izadji(int rbr) {
        // Implementirati ...
        unique_lock<mutex> lock(m);
        izasao = true;
        automobil.napusta(rbr);
    }
};

#endif // PARKING_HPP_INCLUDED
