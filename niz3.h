// niz3.h - Klasa nizova apstraktnih predmeta.

#ifndef _niz3_h_
#define _niz3_h_

#include "zbirka.h"
#include "predmet2.h"

namespace Zbirke {
  class Niz: public Zbirka {                     // Atributi:
    Predmet** niz;                               // - niz predmeta,
    int duz, kap;                                // - duzina i kapacitet.
                                                 // Pomocne metode:
    void kopiraj (const Niz &n);                 // - kopiranje u niz,
    void brisi ()                                // - unistavanje niza.
      { ~*this; delete[] niz; }
  public:                                        // Konstruktori:
    explicit Niz (int k=5)                       // - praznog niza,
      { niz = new Predmet* [kap = k]; duz = 0; }
    Niz (const Niz& n) { kopiraj (n); }          // - kopije.
    ~Niz () { brisi (); }                        // Destruktor.
    Niz& operator= (const Niz& n) {              // Dodela vrednosti.
      if (this != &n){ brisi (); kopiraj (n); }
      return *this;
    }
    const char* vrsta () const { return "Niz"; } // Ime vrste zbirke.
    Niz& operator+= (const Predmet& p);          // Dodavanje predmeta.
    Predmet*& operator[] (int i) {               // Dohvatanje elementa:
      if (i<0 || i>=duz) throw GIndeks ();       // - promenljivog niza,
      return niz[i];
    }
    const Predmet* operator[] (int i) const {    // - nepromenljivog niza.
      if (i<0 || i>=duz) throw GIndeks ();
      return niz[i];
    }
    int vel () const { return duz; }             // Duzina niza.
    Niz& operator~ ();                           // Praznjenje niza.
  };
} // namespace

#endif
