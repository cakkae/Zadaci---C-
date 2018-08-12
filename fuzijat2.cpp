// fuzijat2.C - Ispitivanje genericke funkcije za fuziju nizova.

#include <iostream>
using namespace std;
#include "fuzija.h"
#include "tacka7.h"
#include "pravoug2.h"

template <typename T>
  void radi (const char* naslov) {
    cout << naslov; int na, nb, nc, i;
    cin >> na;    T *a = new T [na]; cout << "Prvi  niz:";
    for (i=0; i<na; i++) {cin >> a[i]; cout << ' ' << a[i];} cout << endl;
    cin >> nb;    T *b = new T [nb]; cout << "Drugi niz:";
    for (i=0; i<nb; i++) {cin >> b[i]; cout << ' ' << b[i];} cout << endl;
    nc = na + nb; T *c = new T [nc]; cout << "Fuzija   :";
    fuzija (a, na, b, nb, c, nc);
    for (i=0; i<nc; i++) {             cout << ' ' << c[i];} cout << endl;
    delete [] a; delete [] b; delete [] c;
  }

int main () {
  radi<int>     ("\nFuzija nizova celih brojeva:\n\n");
  radi<Tacka>   ("\nFuzija nizova tacaka:\n\n");
  radi<Pravoug> ("\nFuzija nizova pravougaonika:\n\n");
  return 0;
}
