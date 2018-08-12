// predmet3t.C - Ispitivanje klasa predmeta.

#include "sfera3.h"
#include "kvadar5.h"
#include "sklop.h"
using namespace Predmeti;
#include <iostream>
#include <string>
using namespace std;

Predmet* citaj (istream& ut) { // Citanje jednog predmeta.
  string vrs; ut >> vrs;
  if        (vrs == "Sfera") {
    double s, r; ut >> s >> r;
    return new Sfera (r, s);
  } else if (vrs == "Kvadar") {
    double s, a, b, c; ut >> s >> a >> b >> c;
    return new Kvadar (a, b, c, s);
  } else if (vrs == "Sklop") {
    Sklop* s = new Sklop;
    while (Predmet* p = citaj (ut)) *s += p;
    return s;
  } else return 0;
}

int main () {                 // Glavna funkcija.
  vector<Predmet*> niz;
  cout << "\nProcitano:\n\n";
  while (Predmet* p = citaj (cin)) {
    cout << *p << " V=" << p->V() << " Q=" << p->Q() << "\n\n";
    niz.push_back (p);
  }
  vector<Predmet*>::iterator i = niz.begin (), iVmax = i, iQmax = i;
  double Vmax = 0, Qmax = 0;
  for (; i!=niz.end(); i++) {
    if ((*i)->V() > Vmax) { Vmax = (*i)->V (); iVmax = i; }
    if ((*i)->Q() > Qmax) { Qmax = (*i)->Q (); iQmax = i; }
  }
  cout << "\nNajvecu zapreminu ima:\n\n" << **iVmax << "\n\n";
  cout << "Najvecu tezinu ima:\n\n" << **iQmax << "\n";
  return 0;
}
