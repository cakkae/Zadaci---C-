// sfera2.h - Klasa sfera.

#ifndef _sfera2_h_
#define _sfera2_h_

#include "proizvod.h"

namespace Fabrika {
  class Sfera: public Proizvod {
    double r;                                   // Poluprecnik sfere.
    void pisi (ostream& it) const               // Pisanje kvadra.
      { Proizvod::pisi (it); it << '(' << r << ')'; }
  public:
    enum { VR = 'S' };                           // Oznaka vrste proizvoda.
    Sfera (double rr) { r = rr; }                // Inicijalizacija.
    char vrsta () const { return VR; }           // Vrsta proizvoda.
    double V () const                    // Zapremina.
      { return 4 * r*r*r * 3.14159 / 3; }
  }; // class Sfera
} // namespace Fabrika

#endif

