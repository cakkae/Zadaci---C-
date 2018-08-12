// tacka3.h - Klasa tacaka u ravni.

#ifndef _tacka3_h_
#define _tacka3_h_

typedef double Real;           // Tip za realne vrednosti.

#include <iostream>
using namespace std;

class Tacka {
  Real x, y;                                              // Koordinate.
public:
  Tacka (Real xx=0, Real yy=0) { x = xx; y = yy; }        // Konstruktor.
  Real aps () const { return x; }                         // Apscisa.
  Real ord () const { return y; }                         // Ordinata.
  friend istream& operator>> (istream& d, Tacka& t)       // Citanje.
    { return d >> t.x >> t.y; }
  friend ostream& operator<< (ostream& d, const Tacka& t) // Pisanje.
    { return d << '(' << t.x << ',' << t.y << ')'; }
};

const Tacka ORG;               // Koordinatni pocetak.

#endif
