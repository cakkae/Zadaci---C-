// niz2.h - Klasa nizova apstraktnih podataka.

#ifndef _niz2_h_
#define _niz2_h_

#include "podatak.h"
#include "niz2gr.h"

class Niz: public Podatak {   // Atributi:
  Podatak** niz;              // - niz pokazivaca na podatke,
  int kap;                    // - kapacitet niza.
                                              // Pomocne metode:
  void kopiraj (const Niz& n);                // - kopiranje niza,
  void brisi () { ~*this; delete [] niz; }    // - unistavanje niza,
  void pisi  (ostream& it) const;             // - pisanje niza.
public:                                       // Konstruktori:
  explicit Niz (int k=10);                    // - praznog niza,
  Niz (const Niz& n) { kopiraj (n); }         // - kopije.
  ~Niz () { brisi (); }                       // Destruktor.
  Niz* kopija () const                        // Dinamicka kopija.
    { return new Niz (*this); }
  Niz& operator= (const Niz& n) {             // Dodela vrednosti.
    if (this != &n) { brisi (); kopiraj (n); }
    return *this;
  }
  int kapac () const { return kap; }          // Kapacitet niza.
                                              // Pristup komponenti:
  Podatak& operator[] (int ind) {             // - promenljivog niza,
    if (ind < 0 || ind >= kap) throw GIndeks (ind, kap);
    if (niz[ind] == 0)         throw GPrazno ();
    return *niz[ind];
  }
  const Podatak& operator[] (int ind) const   // - nepromenljivog niza.
    { return const_cast<Niz&>(*this)[ind]; }
  Niz& operator+= (const Podatak& pp);        // Umetanje podatka.
  Niz& operator-= (int ind) {                 // Izbacivanje podatka.
    if (ind < 0 || ind >= kap) throw GIndeks (ind, kap);
    delete niz[ind]; niz[ind] = 0;
    return *this;
  }
  Niz& operator~ ();                          // Praznjenje niza.
};

#endif
