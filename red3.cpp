// red3.C - Definicije metoda i funkcija uz klasu redova.

#include "red3.h"

void Red::kopiraj (const Red& r) {    // Kopiranje reda.
  prvi = posl = 0; duz = r.duz;
  for (Elem* tek=r.prvi; tek; tek=tek->sled)
    posl = (posl ? posl->sled : prvi) = new  Elem (tek->pod);
}

void Red::brisi () {                  // Brisanje svih elemenata reda.
  while (prvi) { Elem* stari = prvi; prvi = prvi->sled; delete stari; }
  posl = 0; duz = 0;
}

Red& Red::operator+= (const Red& r) { // Dodavanje reda.
  if (r.prvi) {
    Red s (r);
    (posl ? posl->sled : prvi) = s.prvi;
    posl = s.posl; duz += s.duz;
    s.prvi = s.posl = 0;
    s.duz = 0;
  }
  return *this;
}

int Red::uzmi () {                    // Uzimanje podatka s pocetka.
  if (! prvi) exit (1);
  int pod = prvi->pod;
  Elem* stari = prvi;
  prvi = prvi->sled;
  delete stari;
  if (! prvi) posl = 0;
  duz--;
  return pod;
}

Red Red::operator-(int k) const{      // Red bez elemenata jednakih k.
  Red r;
  for (Elem *tek=prvi; tek;
       tek=tek->sled)
    if (tek->pod != k)
      r += tek->pod;
  return r;
}
