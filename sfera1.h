// sfera1.h - Klasa sfera.

#ifndef _sfera1_h_
#define _sfera1_h_

#include "predmet1.h"

class Sfera: public Predmet {
  double r;
public:
  Sfera (double ss=1, double rr=1)                       // Konstruktor.
    : Predmet (ss) { r = rr; }
  double V() const { return 4./3 * r*r*r * 3.14159; }    // Zapremina.
private:
  void citaj (istream& t)                                // Citanje.
    { Predmet::citaj (t); t >> r; }
  void pisi  (ostream& t) const                          // Pisanje.
    { t << "sfera ["; Predmet::pisi (t); t << ',' << r << ']'; }
};

#endif