// kvadar5.h - Klasa kvadara.

#ifndef _kvadar_h_
#define _kvadar_h_

#include "telo.h"

namespace Predmeti {
  class Kvadar: public Telo {
    double a, b, c;                                // Ivice.
  public:
    Kvadar (double aa=1, double bb=1, double cc=1, // Stvaranje.
      double ss=1): Telo (ss) { a = aa; b = bb; c = cc; }
    Kvadar* kopija () const                        // Dinamicka kopija.
      { return new Kvadar (*this); }
    double V () const                              // Zapremina.
      { return a * b * c; }
  private:
    void pisi (ostream& it) const                   // Pisanje.
      { Telo::pisi (it); it << a << ',' << b << ',' << c << ')'; }
  }; // class Kvadar
} // namespace Predmeti

#endif