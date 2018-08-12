// fun3.h - Klase apstraktnih i generickih funkcija.

#ifndef _fun3_h_
#define _fun3_h_

#include <iostream>
using namespace std;

namespace Izvodi {
  class GFun;  // Klasa generickih funkcija.

  class Fun {                                 // KLASA FUNKCIJA:
  public:
    ~Fun () {}                                // Virtuelan destruktor.
    virtual double operator() (double x) const =0; // Racunanje vrednosti.
    virtual GFun izvod () const =0;           // Stvaranje izvoda.
    virtual Fun* kopija () const =0;          // Stvaranje dinamicke kopije.
  private:
    virtual void pisi (ostream& it) const =0; // Pisanje.
    friend ostream& operator<< (ostream& it, const Fun& f)
      { f.pisi (it); return it; }
  }; // class Fun

  class GFun: public Fun {               // KLASA GENERICKIH FUNKCIJA:
    Fun* f;                              // Sadrzana funkcija.
    void pisi (ostream& it) const { it << *f; }  // Pisanje.
  public:
    GFun (Fun* ff) { f = ff; }           // Inicijalizacija.
    GFun (const GFun& p) { f = p.f->kopija (); } // Konstruktor kopije.
    ~GFun () { delete f; }               // Destruktor.
    GFun& operator= (const GFun& p) {    // Dodela vrednosti.
      if (this != &p) { delete f; f = p.f->kopija (); }
      return *this;
    }
    double operator() (double x) const { return (*f)(x); } // Vrednost.
    GFun izvod () const { return f->izvod (); }        // Stvaranje izvoda.
    GFun* kopija () const { return new GFun (*this); } // Dinamicka kopija.
  }; // class GFun
} // namespace Izvodi

#endif
