// lista4.C - Metode i funkcije uz klasu neuredjenih listi.

#include "lista4.h"

void NLista::kopiraj (const NLista& lst) {       // Kopiranje druge liste.
  prvi = posl = 0; duz = 0;
  for (Elem* tek=lst.prvi; tek; tek=tek->sled) *this += tek->broj;
}

void NLista::brisi () {                          // Praznjenje liste.
  while (prvi) { Elem* stari = prvi; prvi = prvi->sled; delete stari; }
  posl = 0; duz = 0;
}

NLista& NLista::operator+= (const NLista& lst) { // Dodavanje liste.
  if (this != &lst)
    for (Elem* tek=lst.prvi; tek; tek=tek->sled) *this += tek->broj;
  else
    *this += NLista (lst);   // lst += lst
  return *this;
}

ostream& operator<< (ostream& it, const NLista& lst) { // Pisanje.
  it << '(';
  for (NLista::Elem* tek=lst.prvi; tek; tek=tek->sled)
    { it << tek->broj; if (tek->sled) it << ','; }
  return it << ')';
}
