/*
Korisnik treba da unese 5 celih brojeva koristeći tastaturu (standardni ulaz).
Korišćenjem STL algoritma, među tih 5 brojeva potrebno je pronaći najveći.
*/

#include <iostream>
#include <vector>
#include<algorithm>

int main(int argn, char* argv[]) {

    std::vector<int> vektor;
    int broj;

    std::cout << "Unesite brojeve za vektor: \n";

    while(std::cin >> broj) {
        vektor.push_back(broj);
    }

    int najveciElement = *std::max_element(vektor.begin(), vektor.end());

    std::cout << "Najveci element: " << najveciElement << std::endl;

    return 0;
}