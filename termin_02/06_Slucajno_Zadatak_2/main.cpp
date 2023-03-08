/*
    Koristeći konzolu i nasumično generisane slučajne brojeve
    po normalnoj distribuciji, vizuelizovati Gausovu krivu
    koristeći zvezdice. Gausova kriva po X osi ima moguće
    vrednosti koje su generisane, a po Y osi koliko su vrednosti
    u tom delu X ose zastupljene, procentualno, u svim
    generisanim vrednostima. Za opseg Y uzmite od 0 do
    najveće izmerene vrednosti od svih Y vrednosti,
    dok za X uzmite plus-minus 2.5 standardne devijacije
    od srednje vrednosti. Veličina uzorka slučajnih vrednosti,
    tj. koliko da generišete pre nego probate neka vam je
    8192.

    Gausova kriva za srednju vrednost 5
    i standardnu devijaciju 2 izlgeda otprilike ovako ako se
    posmatra rotirano za 90 stepeni, kao u zadatku pod A:
    0-1: *
    1-2: ****
    2-3: *********
    3-4: ***************
    4-5: ******************
    5-6: *******************
    6-7: ***************
    7-8: ********
    8-9: ****
    9-10: *
    Gausova kriva ya srednju vrednost 0 i SD 1, nacrtana
    uspravno izgleda otprilike ovako:
                                        * *
                                     *  ***
                                     * ***** *
                                  *  **********
                                  *  ********** *
                              ***************** *
                            * *******************
                            *********************
                           ************************ **
                          ****************************
                         *******************************
                       * *******************************
                      ********************************** *
                    * ********************************** *
                    ****************************************
                    ******************************************
                 * *******************************************
                ************************************************
                **************************************************
            *******************************************************
            **********************************************************
       * * ************************************************************
   *  ********************************************************************
   **************************************************************************
********************************************************************************
    Odabrati jedan:
    A) (Lakše) Prikazati Gausovu krivu rotiranu za 90 stepeni.
    B) (Teže) Prikazati je normalno
*/

#include <iostream>
#include <random>
#include <functional>
#include <chrono>

using namespace std;

chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

int main(int argn, char** argv) {

  default_random_engine generator;

  chrono::high_resolution_clock::duration duration = chrono::high_resolution_clock::now() - start;

  generator.seed(duration.count());

  normal_distribution<double> dist(5, 2);

  auto d6 = bind(dist, generator);

  vector<double> vectorOfNumbers;

  for(int i = 0; i < 8192; i++) {
    vectorOfNumbers.push_back(d6());
  }

  vector<int> podela = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  for(double& d : vectorOfNumbers) {
    if(d > 0 && d < 1) {
      podela[0]++;
    } else if(d > 1 && d < 2) {
      podela[1]++;
    } else if(d > 2 && d < 3) {
      podela[2]++;
    } else if(d > 3 && d < 4) {
      podela[3]++;
    } else if(d > 4 && d < 5) {
      podela[4]++;
    } else if(d > 5 && d < 6) {
      podela[5]++;
    } else if(d > 6 && d < 7) {
      podela[6]++;
    } else if(d > 7 && d < 8) {
      podela[7]++;
    } else if(d > 8 && d < 9) {
      podela[8]++;
    } else if(d > 9 && d < 10) {
      podela[9]++;
    } 
  }

  cout << "Vektor: ";
  for(int& v : podela) {
    v /= 150;
    v++;
    cout << v << " ";
  }
  cout << endl << endl;

  for(int i = 0; i < podela.size(); i++) {
    int br = podela[i];

    function<std::string()> functionToGetStars = [&br]() -> std::string { 
      std::string a = ""; 
      for(int i = 0; i < br; i++) a += "*"; 
      return a;
    };

    cout << i << "-" << (i+1) << "\t: " << functionToGetStars() << endl;
  }

  return 0;
}