// predmet3.h - Klasa apstraktnih predmeta.

#ifndef _predmet_h_
#define _predmet_h_

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <cstring>
using namespace std;

namespace Predmeti {
  class Predmet {
    static int ukId;           // Poslednje korisceni identifikator.
    int id;                    // Identifikator predmeta.
  public:
    Predmet (): id(++ukId) {}             // Nov predmet dobija nov broj.
    Predmet (const Predmet&):id(++ukId){} // Kopija dobija nov broj.
    virtual ~Predmet () {}                // Virtuelan destruktor.
    Predmet& operator= (const Predmet&)   // Levom operandu se ne menja
      { return *this; }                   //   broj.
    virtual Predmet* kopija () const =0;  // Dinamicka kopija.
    virtual double V () const =0;         // Zapremina.
    virtual double Q () const =0;         // Tezina.
    const char* vrsta () const            // Ime klase.
      { return strrchr (typeid(*this).name(), ':') + 1; }
  protected:
    static int nivo;                      // Nivo pisanja predmeta.
    virtual void pisi (ostream& it) const // Pisanje.
      { it << setw(nivo*2) << "" << vrsta() << '/' << id << ' '; }
    friend ostream& operator<< (ostream& it, const Predmet& p)
      { p.pisi (it); return it; }
  }; // class Predmet
  } // namespace Predmeti

#endif