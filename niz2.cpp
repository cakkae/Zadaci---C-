// niz2.C - Metode klase nizova apstraktnih podataka.

#include "niz2.h"

Niz::Niz (int k) {                          // Stvaranje praznog niza.
  niz = new Podatak* [kap = k];
  for (int i=0; i<kap; niz[i++]=0);
}

void Niz::kopiraj (const Niz& n) {          // Inicijalizacija nizom.
  niz = new Podatak* [kap = n.kap];
  for (int i=0; i<kap; i++)
    niz[i] = n.niz[i] ? n.niz[i]->kopija() : 0;
}

void Niz::pisi (ostream& it) const {        // Pisanje.
  it << '[';
  for (int i=0; i<kap; i++) {
    if (niz[i]) it << *niz[i];
    if (i < kap-1) it << ',';
  }
  it << ']';
}

Niz& Niz::operator+= (const Podatak& p) {   // Umetanje podatka.
  int i = 0; while (i<kap && niz[i]) i++;
  if (i == kap) throw GPun ();
  niz[i] = p.kopija ();
  return *this;
}

Niz& Niz::operator~ () {                    // Praznjenje niza.
  for (int i=0; i<kap; i++) { delete niz[i]; niz[i] = 0; }
  return *this;
}
