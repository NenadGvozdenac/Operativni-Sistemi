/*
    Uz zadatke ide fajl koji se zove ulaz.txt
    U njemu se nalaze bodovi studenata u formi:
    Ime,Prezime,V=70&P=30,Beleska
    Napraviti program koji na osnovu fajla sračuna prosek za V (vežbe) i prosek za 
    P(ispit). 
*/

#include <iostream>
#include <regex>
#include <fstream>
#include <list>

using namespace std;

int main(int argn, char** argv) {

    ifstream ifile;
    ifile.open("ulaz.txt", ios::in);

    auto r1 = regex("^[A-Za-z]+,[A-Za-z]+,V=(\\d+)&P=(\\d+),[A-Za-z\\s]+$");

    string data;

    list<string> listOfStrings;

    while(ifile >> data) {
        listOfStrings.push_back(data);
    }

    for(string& s : listOfStrings) {
        if(regex_match(s, r1)) {
            cout << "Nasao string: " << s << endl;
        }
    }

    double brojBodovaVezbi = 0.0;
    double brojBodovaIspita = 0.0;
    int brojac = 0;

    for(string& s : listOfStrings) {
        smatch sm;
        while(regex_search(s, sm ,r1)) {

            brojBodovaVezbi += stoi(sm[1]);
            brojBodovaIspita += stoi(sm[2]);

            brojac++;

            s = sm.suffix();
        }
    }

    cout << "Prosek broja bodova vezbi: " << brojBodovaVezbi / brojac << endl;
    cout << "Prosek broja bodova ispita: " << brojBodovaIspita / brojac << endl;

    ifile.close();

    return 0;
}