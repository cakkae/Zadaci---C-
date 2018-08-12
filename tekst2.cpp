// tekst2.C - Definicije metoda, funkcija i zajednickih atributa
//            uz stedljivu klasu tekstova.

#include "tekst2.h"

void Tekst::brisi () {                // Unistavanje teksta.
  if (tks && --tks->kor==0) {
    (tks->pret ? tks->pret->sled : prvi) = tks->sled;
    (tks->sled ? tks->sled->pret : posl) = tks->pret;
    delete [] tks->niz;
    delete tks;
    broj--;
  }
}

Tekst::Tekst (const char *n) {        // Inicijalizacija niskom.
  if (n && strlen (n)) {
    int f; Tks* tek;
    for (tek=prvi; tek && ((f=strcmp(tek->niz,n))<0); tek=tek->sled);
    if (tek && f == 0)     // Tekst vec postoji u memoriji.
      (tks = tek)->kor++;
    else {                 // Tekst jos ne postoji u memoriji.
      tks = new Tks; tks->kor = 1;
      tks->niz = new char [strlen(n)+1]; strcpy (tks->niz, n);
      if (! prvi) {                                   // Jedini u listi.
        prvi = posl = tks; tks->sled = tks->pret = 0;
      } else if (! tek) {                             // Iza poslednjeg.
        tks->sled = 0;               tks->pret = posl;
        if (posl) posl->sled = tks;  posl = tks;
      } else if (! tek->pret) {                       // Ispred prvog.
        tks->pret = 0;              tks->sled = prvi;
        if (prvi) prvi->pret = tks; prvi = tks;
      } else {                                        // Usred liste.
        tks->sled  = tek->pret->sled; tek->pret->sled = tks;
        tks->pret = tek->pret;       tek->pret = tks;
      }
      broj++;
    }
  } else tks = 0;   // Prazan tekst.
}

Tekst operator+ (const Tekst& t1, const Tekst& t2) { // Spajanje tekstova.
  if (!t1.tks) return t2;
  if (!t2.tks) return t1;
  Tekst t; t.tks->niz = new char [len(t1) + len(t2) + 1];
  strcpy (t.tks->niz, t1.tks->niz); strcat (t.tks->niz, t2.tks->niz);
  return t;
}

Tekst Tekst::operator() (int i, int j) const {       // Podniz teksta.
  if (i<0 || j<i || len(*this)<=j) exit(1);
  Tekst t; int d = j - i + 1;
  t.tks->niz = new char [d+1]; strncpy (t.tks->niz, tks->niz+i, d);
  t.tks->niz[d] = 0;
  return t;
}

int operator% (const Tekst& t1, const Tekst& t2) {   // Mesto podniza.
  int d1 = len (t1), d2 = len (t2);
  if (!d1 || !d2) return -1;
  for (int i=0; i<d1-d2+1; i++) {
    int j;
    for (j=0; j<d2 && t1.tks->niz[i+j]==t2.tks->niz[j]; j++);
    if  (j == d2) return i;
  }
  return -1;
}

istream& operator>> (istream& it, Tekst& t) {        // Citanje teksta.
  char* n = new char [81]; it >> n; if (it) t = n; delete [] n;
  return it;
}

void Tekst::spisak () {                      // Spisak svih tekstova.
  int poz = 0, duz;
  for (Tks *tek=prvi; tek; tek=tek->sled) { 
    if (poz + (duz = strlen (tek->niz) + 2) < 72) poz += duz;
      else  { cout << endl; poz = duz; }
    cout << "  " << tek->niz;
  }
  cout << endl;
}

Tekst::Tks *Tekst::prvi=0, *Tekst::posl=0;   // Inicijalizacija zajednickih
int Tekst::broj = 0;                         //   atributa.
