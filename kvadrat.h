// kvadrat.h - Klasa kvadrata u ravni.

#ifndef _kvadrat_h_
#define _kvadrat_h_

#include "figura1.h"

class Kvadrat: public Figura {
  Real a;                                  // Stranica.
public:
  Kvadrat (Real aa=1, const Tacka& tt=ORG) // Konstruktor.
    : Figura(tt) { a = aa; }
  Real O () const { return 4 * a; }        // Obim.
  Real P () const { return a * a; }        // Povrsina.
  Kvadrat* kopija () const                 // Stvaranje kopije.
    { return new Kvadrat (*this); }
private:
  void citaj (istream& ut)                 // Citanje.
   { Figura::citaj (ut); ut >> a ; }
  void pisi  (ostream& it) const {         // Pisanje.
    it << "kvadrat ["; Figura::pisi (it);
    it << ", a=" << a << ", O=" << O () << ", P=" << P () << ']';
  }
};

#endif
