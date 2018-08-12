// tekst1.C - Definicije metoda i funkcija uz klasu tekstova.

#include "tekst1.h"

void Tekst::kopiraj (const char* n) {                // Kopiranje teksta.
  if (n && strlen(n)) {
    niz = new char [strlen(n)+1]; strcpy (niz, n);
  } else niz = 0;
}

Tekst operator+ (const Tekst& t1, const Tekst& t2) { // Spajanje tekstova.
  if (!t1.niz) return t2;
  if (!t2.niz) return t1;
  Tekst t; t.niz = new char [len(t1) + len(t2) + 1];
  strcpy (t.niz, t1.niz); strcat (t.niz, t2.niz);
  return t;
}

Tekst Tekst::operator() (int i, int j) const {       // Podniz teksta.
  if (i<0 || j<i || len(*this)<=j) exit(1);
  Tekst t; int d = j - i + 1;
  t.niz = new char [d+1]; strncpy (t.niz, niz+i, d); t.niz[d] = 0;
  return t;
}

int operator% (const Tekst& t1, const Tekst& t2) {   // Mesto podniza.
  int d1 = len (t1), d2 = len (t2);
  if (!d1 || !d2) return -1;
  for (int i=0; i<d1-d2+1; i++) {
    int j;
    for (j=0; j<d2 && t1.niz[i+j]==t2.niz[j]; j++);
    if  (j == d2) return i;
  }
  return -1;
}

istream& operator>> (istream& it, Tekst& t) {        // Citanje teksta.
  char* n = new char [81]; it >> n; t = n; delete [] n;
  return it;
}
