// tacka6.h - Klasa tacaka u prostoru.

#ifndef _tacka6_h_
#define _tacka6_h_

#include "figura2.h"
#include "vektor3.h"

class Tacka: public Figura {
  Vektor p;                                            // Vektor polozaja.
  void pisi (ostream& it) const { it << 'T' << p; }    // Pisanje.
public:
  Tacka (const Vektor& v=Vektor()): p(v) {}            // Konstruktor.
  Tacka* kopija () const { return new Tacka (*this); } // Dinamicka kopija.
  Tacka& operator+= (const Vektor& v) { p += v; return *this; } // T += v
  Vektor teziste () const { return p; }                         // Teziste.
};

#endif
