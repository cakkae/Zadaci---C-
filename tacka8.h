// tacka8.h - Klasa tacaka u ravni.

#ifndef _tacka8_h_
#define _tacka8_h_

#include <cmath>
using namespace std;

namespace Figure {
  class Tacka {
    double xx, yy;                                   // Koordinate tacke.
  public:
    Tacka (double x=0, double y=0)                   // Konstruktor.
      { xx = x; yy = y; }
    double x () const { return xx; }                 // Apscisa tacke.
    double y () const { return yy; }                 // Ordinata tacke.
    double rastojanje (Tacka t=Tacka()) const {      // Rastojanje do
      return sqrt (pow(xx-t.xx,2) + pow(yy-t.yy,2)); //   zadate tacke.
    }
  }; // class Tacka
} // namespace Figure

#endif
