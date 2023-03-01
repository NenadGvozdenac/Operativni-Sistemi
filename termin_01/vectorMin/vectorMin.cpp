/* 
Napraviti funkciju:
	
vector<int> min(const vector<int>& a, const vector<int>& b);

Ova funkcija vraća vektor koji sadrži minimume korespodentnih elemenata vektora a i b.
Npr: r[0]=min(a[0],b[0]), r[1]=...
Podrazumeva se: a.size()==b.size()
*/

#include <iostream>
#include <vector>

std::vector<int> min(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> vektor;

    for(int i = 0; i < a.size(); i++) {
        vektor.push_back(a[i] < b[i] ? a[i] : b[i]);
    }

    return vektor;
}

std::vector<int> unesiNiz() {
    int broj;
    std::vector<int> niz;

    std::cout << "Unesite brojeve niza (0 za izlazak): \n";

    while(true) {
        std::cin >> broj;
        if(broj == 0) break;
        niz.push_back(broj);
    }

    return niz;
}

void ispisiVektor(const std::vector<int>& vektor) {
    for(int i = 0; i < vektor.size(); i++) {
        std::cout << vektor[i] << " ";
    }
}

int main(int argn, char* argv[]) {

    std::vector<int> niz1 = unesiNiz();
    std::vector<int> niz2 = unesiNiz();

    if(niz1.size() != niz2.size()) {
        std::cout << "Greska pri unosu! Velicine nizova MORAJU biti isti!" << std::endl;
        return -1;
    }

    std::vector<int> finalniVektor = min(niz1, niz2);

    ispisiVektor(finalniVektor);

    return 0;
}