/*
Uneti 5 celih brojeva sa standardnog ulaza.
Korišćenjem STL algoritma sortirati brojeve u opadajućem redosledu.
*/

#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include <array>

int main(int argn, char* argv[]) {

    std::list<int> lista;
    
    for(int i = 0; i < 5; i++) {

        int broj;

        std::cout << "Unesite broj: ";
        std::cin >> broj;
    
        lista.push_back(broj);
    }

    lista.sort(std::greater<int>());

    std::cout << "Elementi liste: ";

    for(std::list<int>::const_iterator it = lista.begin(); it != lista.end(); it++) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    return 0;
}