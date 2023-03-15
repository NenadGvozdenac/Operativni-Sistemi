#ifndef NITI_HPP_INCLUDED
#define NITI_HPP_INCLUDED

#include <vector>
#include <thread>

#include "suma_vektora.hpp"

using namespace std;

// v - vektor čije elemente treba sumirati
// n - koliko niti treba pokrenuti
// povratna vrednost - suma svih elemenata vektora, izračunata pokretanjem n niti (svaka nit treba da obradi jedan deo elemenata)
double sumiraj(vector<double> v, int n) {
    
    double zbir = 0;

    int offset = v.size() / n;

    vector<thread> vektorNiti(n);

    for(int i = 0; i < n - 1; i++) {

        ci beginI = v.begin() + (offset * i);
        ci endI = v.begin() + (offset * (i + 1));

        vektorNiti.at(i) = thread(f, beginI, endI, ref(zbir));
    }

    vektorNiti.at(n - 1) = thread(f, v.begin() + (offset * (n - 1)), v.end(), ref(zbir));

    for(thread& t : vektorNiti) {
        t.join();
    }

    return zbir;
}

#endif // NITI_HPP_INCLUDED
