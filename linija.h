// linija.h - Klasa apstraktnih linija u ravni.

#ifndef _linija_h_
#define _linija_h_

#include <iostream>
using namespace std;

namespace Linije {
  class Linija {
    static int ukId;       // Poslednje korisceni identifikator.
    int id;                // Identifikator linije.
  public:
    Linija (): id(++ukId) {}              // Nova linija dobija nov broj.
    Linija (const Linija&): id(++ukId) {} // Kopija dobija nov broj.
    Linija& operator= (const Linija&)     // Levom operandu se ne menja
      { return *this; }                   //   broj.
    virtual double duzina () const =0;    // Duzina linije.
    virtual Linija* kopija () const =0;   // Dinamicka kopija.
  protected:
    virtual void pisi (ostream& it) const { it<< id; } // Pisanje.
    friend ostream& operator<< (ostream& it, const Linija& lin)
      { lin.pisi (it); return it; }
  };
}

#endif