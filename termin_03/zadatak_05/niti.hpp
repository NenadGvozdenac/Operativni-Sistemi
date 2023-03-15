#ifndef NITI_HPP_INCLUDED
#define NITI_HPP_INCLUDED

#include <vector>
#include <thread>

#include "suma_vektora.hpp"

using namespace std;

// v - vektor A čije elemente treba sumirati
// v - vektor B čije elemente treba sumirati
// povratna vrednost - suma korespondentnih elemenata vektora A i B, izračunata pozivanjem dve niti
vector<double> sumiraj(vector<double> a, vector<double> b) {
    vector<double> rez(a.size());

    vector<double>::iterator sredinaA = a.begin() + a.size() / 2;
    vector<double>::iterator sredinaB = b.begin() + b.size() / 2;

    thread t1(f, a.begin(), sredinaA, b.begin(), rez.begin());
    thread t2(f, sredinaA, a.end(), sredinaB, rez.begin() + rez.size() / 2);

    t1.join();
    t2.join();

    return rez;
}

#endif // NITI_HPP_INCLUDED
