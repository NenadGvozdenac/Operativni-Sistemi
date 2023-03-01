#include <iostream>
#include <map>

using std::string;
using std::map;
using std::cout;
using std::cin;
using std::endl;

int main(int argn, char* argv[]) {

    map<string, string> mapa;

    for(int i = 0; i < 3; i++) {

        string srpskaRec, engleskaRec;

        cout << "Unesite srpsku rec: ";
        cin >> srpskaRec;

        cout << "Unesite englesku rec: ";
        cin >> engleskaRec;

        mapa.insert(std::pair<string, string>(srpskaRec, engleskaRec));
    }

    cout << endl;

    for(const std::pair<string, string> par : mapa) {
        std::cout << par.first << " = " << par.second << endl;
    }

    return 0;
}