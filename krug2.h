// krug2.h - Klasa krugova u ravni.

#ifndef _krug2_h_
#define _krug2_h_

#include "figura1.h"

const Real PI = 3.1415926535897932;

class Krug: public Figura {
  Real r;                                  // Poluprecnik.
public:
  Krug (Real rr=1, const Tacka& tt=ORG)    // Konstruktor.
    : Figura (tt) { r = rr; }
  Real O () const { return 2 * r * PI; }   // Obim.
  Real P () const { return r * r * PI; }   // Povrsina.
  Krug* kopija () const                    // Dinamicka kopija.
    { return new Krug (*this); }
private:
  void citaj (istream& ut)                 // Citanje.
    { Figura::citaj (ut); ut >> r ; }
  void pisi  (ostream& it) const {         // Pisanje.
    it << "krug    ["; Figura::pisi (it);
    it << ", r=" << r << ", O=" << O() << ", P=" << P() << ']';
  }
};

#endif
