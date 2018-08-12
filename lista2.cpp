// lista2.C - Definicije metoda lista celih brojeva (iterativno).

#include "lista2.h"
#include <iostream>
using namespace std;

int Lista::duz () const {          // Broj elemenata liste.
  int n = 0;
  for (Elem* tek=prvi; tek; tek=tek->sled) n++;
  return n;
}

void Lista::pisi () const {        // Pisanje liste.
  for (Elem* tek=prvi; tek; tek=tek->sled)
    cout << tek->broj << ' ';
}

void Lista::naKraj (int b) {       // Dodavanje na kraj.
  Elem *novi = new Elem (b);
  if (!prvi) prvi = novi;
  else {
    Elem *tek = prvi;
    while (tek->sled) tek = tek->sled;
    tek->sled = novi;
  }
}

void Lista::citaj1 (int n) { // Citanje stavljajuci brojeve na pocetak.
  brisi ();
  for (int i=0; i<n; i++)
    { int b; cin >> b; prvi = new Elem (b, prvi); }
}

void Lista::citaj2 (int n) { // Citanje stavljajuci brojeve na kraj.
  brisi (); Elem* posl = 0;
  for (int i=0; i<n; i++) {
    int b; cin >> b;
    Elem *novi = new Elem (b);
    if (!prvi) prvi = novi; else posl->sled = novi;
    posl = novi;
  }
}

Lista::Lista (const Lista& lst) {  // Konstruktor kopije.
  prvi = 0;
  for (Elem *tek=lst.prvi, *posl=0; tek; tek=tek->sled) {
    Elem* novi = new Elem (tek->broj);
    if (!prvi) prvi = novi; else posl->sled = novi;
    posl = novi;
  }
}

void Lista::umetni (int b) {       // Umetanje u uredjenu listu.
  Elem *tek=prvi, *pret=0;
  while (tek && tek->broj < b) { pret = tek; tek = tek->sled; }
  Elem* novi = new Elem (b, tek);
  if (!pret) prvi = novi; else pret->sled = novi;
}

void Lista::brisi () {             // Brisanje svih elemenata liste.
  while (prvi) { Elem *stari = prvi; prvi = prvi->sled; delete stari; }
}

void Lista::izostavi (int b) {      // Izostavljanje svakog pojavljivanja.
  Elem *tek = prvi, *pret = 0;
  while (tek)
    if (tek->broj != b) {
      pret = tek; tek = tek->sled;
    } else {
      Elem *stari = tek;
      tek = tek->sled;
      if (!pret) prvi = tek; else pret->sled = tek;
      delete stari;
    }
}
