// izvodt.C - Ispitivanje stvaranja izvoda.

#include "fun3.h"
#include "monom.h"
#include "ekspon.h"
#include "zbirfun.h"
using namespace Izvodi;
#include <iostream>
#include <cstdlib>
#include <new>
using namespace std;

int main (int, char** varg) {
  ZbirFun zbir (atoi (varg[1]));
  try {
    while (true) {
      double a, b; char vrs;
      cout << "Vrsta (M, E, *)? "; cin >> vrs;
    if (vrs == '*') break;
      switch (vrs) {
        case 'm': case 'M':
          cout << "a,b? "; cin >> a >> b; zbir += Monom  (a, b);  break;
        case 'e': case 'E':
          cout << "a,b? "; cin >> a >> b; zbir += Ekspon (a, b);  break;
        default:
          throw "*** Nedozvoljeni izbor!\n";
      }
    }
    GFun izvod = zbir.izvod ();
    cout << "Fun= " << zbir << endl;
    cout << "Izv= " << izvod << endl;
    double xmin = atof (varg[2]), xmax = atof (varg[3]),
           dx = atof (varg[4]);
    for (double x=xmin; x<=xmax; x+=dx)
      cout << x << '\t' << zbir (x) << '\t' << izvod (x) << endl;
  } catch (GZbirFunPun) {
    cout << "*** Zbir funkcija je pun!\n";
  } catch (const char* g) {
    cout << g;
  } catch (bad_alloc) {
    cout << "*** Dodela memorije nije uspela!\n";
  }
  return 0;
}
