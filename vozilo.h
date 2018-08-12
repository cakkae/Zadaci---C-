// vozilo.h - Apstraktna klasa vozila.

#ifndef _vozilo_h_
#define _vozilo_h_

#include <iostream>
using namespace std;

class Vozilo {
  double sopTez;                                      // Sopstvena tezina.
public:
  Vozilo (double st) { sopTez = st; }                 // Konstruktor.
  virtual char vrsta () const =0;                     // Vrsta vozila.
  virtual double tezina () const { return sopTez; }   // Ukupna tezina.
protected:
  virtual void pisi (ostream& it) const               // Pisanje.
    { it << vrsta() << '(' << sopTez << ','; }
  friend ostream& operator<< (ostream& it, const Vozilo& v)
    { v.pisi (it); return it; }
};

#endif
