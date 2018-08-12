// tacka5.h - Klasa tacaka u ravni.

#ifndef _tacka5_h_
#define _tacka5_h_

#include <iostream>
using namespace std;

namespace Linije {
  class Tacka {
    double x, y;                                             // Koordinate.
  public:
    Tacka (double xx=0, double yy=0) { x = xx; y = yy; }     // Konstruktor.
    double aps () const { return x; }                        // Apscisa.
    double ord () const { return y; }                        // Ordinata.
    friend ostream& operator<< (ostream& it, const Tacka& t) // Pisanje.
      { return it << '(' << t.x << ',' << t.y << ')'; }
    static void pisiNiz (ostream& it, const Tacka* niz, int duz);
                                                    // Pisanje niza tacaka.
  };
}

#endif
