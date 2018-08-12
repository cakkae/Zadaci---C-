// krug3.h - Klasa obojenih krugova u ravni.

#ifndef _krug3_h_
#define _krug3_h_

#include "figura3.h"

namespace Figure {
  class Krug: public Figura {
    Tacka  C;                              // Centar.
    double r;                              // Poluprecnik.
  public:                                  // Konstruktor.
    explicit Krug (Tacka cc=Tacka(), double rr=1, Boja bb=Boja())
      : Figura (bb), C(cc), r(rr) {}
    Krug* kopija () const { return new Krug (*this); } // Kopija.
  private:
    bool pripada (const Tacka& T) const    // Da li tacka pripada?
    { return C.rastojanje(T) <= r; }
  }; // class Krug
} // namespace Figure

#endif
