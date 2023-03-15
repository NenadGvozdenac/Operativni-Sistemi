#ifndef NITI_HPP_INCLUDED
#define NITI_HPP_INCLUDED

#include <vector>
#include <thread>

#include "suma_vektora.hpp"

using namespace std;

// v - vektor čije elemente treba sumirati
// povratna vrednost - suma svih elemenata vektora, izračunata pokretanjem 2 niti (svaka treba da obradi jednu polovinu elemenata)
double sumiraj(vector<double> v) {
    double zbir;

    ci polovina = v.begin() + v.size() / 2;
    thread t1(f, v.begin(), polovina, ref(zbir));
    thread t2(f, polovina, v.end(), ref(zbir));

    t1.join();
    t2.join();
    return zbir;
}

#endif // NITI_HPP_INCLUDED
