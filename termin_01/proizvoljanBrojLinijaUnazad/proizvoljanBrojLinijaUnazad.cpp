#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;

int main(int argn, char* argv[]) {

    vector<string> vectorStringova;

    string s;

    while(true) {
        cout << "Unesite string: ";
        if(!(cin >> s)) break;

        vectorStringova.push_back(s);
    }

    cout << endl << endl;

    cout << "Uneti stringovi su: ";

    for(vector<string>::iterator it = vectorStringova.end(); it != vectorStringova.begin() - 1; it--) {
        cout << *it << endl;
    }

    return 0;
}