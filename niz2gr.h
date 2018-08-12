// niz2gr.h - Klase za greske.

#ifndef _niz2gr_h_
#define _niz2gr_h_

#include <iostream>
using namespace std;

class GPun {};         // GRESKA: Niz je pun.

class GPrazno {        // GRESKA: Mesto u nizu je prazno.
public:
  friend ostream& operator<< (ostream& it, const GPrazno&)
    { return it << "*** GRESKA: Pristup praznom mestu u nizu!\n"; }
};

class GIndeks {        // GRESKA: Indeks je izvan opsega.
  int ind, duz;        // Pogresan indeks i duzina niza.
public:
  GIndeks (int i, int d) { ind = i; duz = d; }
  int uzmiInd () const { return ind; } // Dohvatanje pogresnog indeksa.
  int uzmiDuz () const { return duz; } // Dohvatanje duzine niza.
  friend ostream& operator<< (ostream& it, const GIndeks& g) {
    return it << "*** GRESKA: Nedozvoljen indeks " << g.ind
              << " u nizu duzine " << g.duz << "!\n";
  }
};

#endif
