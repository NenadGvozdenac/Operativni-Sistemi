/*
    Napraviti funkciju koja sortira dati vektor int-ova koristeći
    za određivanje da li je neki element manji ili veći od drugog
    prosleđenu funkciju. Demonstrirati ovo kroz lambda izraz.

    Bonus zadaci:
    1. Implementirati ovo da radi sa bilo kojim tipom kroz
    šablone.
    2. Implementirati ovo kroz quicksort algoritam.
*/

#include <iostream>
#include <functional>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argn, char** argv) {

    vector<int> vektorBrojeva = {1, 2, 5, 4, 2, 6, 7, 5, 3, 7, 8};

    function<bool(int, int)> sortiranjeNavise = [](int a, int b) -> bool { return a < b; };
    function<bool(int, int)> sortiranjeNanize = [](int a, int b) -> bool { return a > b; };

    sort(vektorBrojeva.begin(), vektorBrojeva.end(), sortiranjeNanize);

    function<void()> functionToOutputVector = [vektorBrojeva]() -> void {
        cout << "Vektor: ";

        for(vector<int>::const_iterator it = vektorBrojeva.begin(); it != vektorBrojeva.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    };

    functionToOutputVector();

    return 0;
}