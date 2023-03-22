#ifndef KOORDINATOR_HPP_INCLUDED
#define KOORDINATOR_HPP_INCLUDED

using namespace std;

class Koordinator {
private:
    const int cekam_niti;     // Konstanta koja govori koliko niti se čeka na završetak pre nego što se aktivira poslednja.
    mutex m;
    bool ispisaoJedan, ispisaoDva;
public:
    Koordinator(int cn) : cekam_niti(cn), ispisaoJedan(false), ispisaoDva(false) {
        // Proširiti po potrebi ...
    }

    // Metoda koju na svom KRAJU zovu niti (a i b) koje ne čekaju (izvršavaju se odmah).
    void zavrsio() {
        // Implementirati ... 

        unique_lock<mutex> lock(m);
        if(ispisaoJedan) {
            ispisaoDva = true;
        } else ispisaoJedan = true;
    }

    // Metodu koju na svom POČETKU zovu niti (c) koje čekaju (ne izvršavaju se odmah).
    void cekam() {
        // Implementirati ...
        while(true) {
            unique_lock<mutex> lock(m);
            if(ispisaoDva) {
                break;
            }
        }
    }
};

#endif // KOORDINATOR_HPP_INCLUDED
