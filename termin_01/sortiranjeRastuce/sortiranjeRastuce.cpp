/*
Uneti 5 celih brojeva sa standardnog ulaza.
Korišćenjem STL algoritma sortirati brojeve u rastućem redosledu.
*/

#include <iostream>
#include <list>

int main(int argn, char* argv[]) {

    std::list<int> listaBrojeva;

    for(int i = 0; i < 5; i++) {
        int broj;

        std::cout << "Unesite broj: ";
        std::cin >> broj;
        listaBrojeva.push_front(broj);
    }

    listaBrojeva.sort();

    std::cout << "Brojevi: " << std::endl;

    for(int& broj : listaBrojeva) {
        std::cout << broj << std::endl;
    }

    return 0;
}