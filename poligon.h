// poligon.h - Klasa poligona u ravni.

#ifndef _poligon_h_
#define _poligon_h_

#include "izlomljena.h"

namespace Linije {
  class Poligon: public Izlomljena {
  public:
    Poligon (const Tacka* niz, int k)     // Inicijalizacija nizom tacaka.
      : Izlomljena (niz, k) {}
    double duzina () const                            // Duzina.
      { return Izlomljena::duzina() + Duz(tem[0], tem[n-1]).duzina(); }
    Poligon* kopija () const                          // Dinamicka kopija.
      { return new Poligon (*this); }
  private:
    virtual void pisi (ostream& it) const {           // Pisanje.
      Linija::pisi (it); it << "[poligon: ";
      Tacka::pisiNiz (it, tem, n); it <<']';
    }
  };
}

#endif
