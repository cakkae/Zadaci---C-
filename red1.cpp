// red1.C - Definicije paketa za obradu redova celih brojeva.

#include "red1.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void dodaj (Red& r, int b) {            // Dodavanje reda na kraju reda.
  Elem* novi = new Elem;
  novi->broj = b; novi->sled = 0;
  if (!r.prvi) r.prvi = novi; else r.posl->sled = novi;
  r.posl = novi;
}

int uzmi (Red& r) {                     // Uzimanje broja s pocetka reda.
  if (!r.prvi) exit (1);
  int b = r.prvi->broj;
  Elem* stari = r.prvi;
  r.prvi = r.prvi->sled;
  if (!r.prvi) r.posl = 0;
  delete stari;
  return b;
}

int duz (const Red& r) {                // Odredjivanje duzine reda.
  int d = 0;
  for (Elem* tek=r.prvi; tek; tek=tek->sled) d++;
  return d;
}

void pisi (const Red& r) {              // Ispisivanje reda.
  for (Elem* tek=r.prvi; tek; tek=tek->sled)
    cout << tek->broj << ' ';
}

void brisi (Red& r) {                   // Praznjenje reda.
  while (r.prvi) {
    Elem* stari = r.prvi; r.prvi=r.prvi->sled; delete stari;
  }
  r.posl = 0;
}
