// fuzijat1.C - Ispitivanje genericke funkcije za fuziju nizova.

#include <iostream>
using namespace std;
#include "fuzija.h"
#include "tacka7.h"
#include "pravoug2.h"

int main () {
  int na, nb, nc, i;

  {
    cout << "\nFuzija nizova celih brojeva:\n\n";
    cin >> na;    int *a = new int [na]; cout << "Prvi  niz:";
    for (i=0; i<na; i++) {cin >> a[i]; cout << ' ' << a[i];} cout << endl;
    cin >> nb;    int *b = new int [nb]; cout << "Drugi niz:";
    for (i=0; i<nb; i++) {cin >> b[i]; cout << ' ' << b[i];} cout << endl;
    nc = na + nb; int *c = new int [nc]; cout << "Fuzija   :";
    fuzija (a, na, b, nb, c, nc);
    for (i=0; i<nc; i++) {             cout << ' ' << c[i];} cout << endl;
    delete [] a; delete [] b; delete [] c;
  }

  {
    cout << "\nFuzija nizova tacaka:\n\n";
    cin >> na;    Tacka *a = new Tacka [na]; cout << "Prvi  niz:";
    for (i=0; i<na; i++) {cin >> a[i]; cout << ' ' << a[i];} cout << endl;
    cin >> nb;    Tacka *b = new Tacka [nb]; cout << "Drugi niz:";
    for (i=0; i<nb; i++) {cin >> b[i]; cout << ' ' << b[i];} cout << endl;
    nc = na + nb; Tacka *c = new Tacka [nc]; cout << "Fuzija   :";
    fuzija (a, na, b, nb, c, nc);
    for (i=0; i<nc; i++) {             cout << ' ' << c[i];} cout << endl;
    delete [] a; delete [] b; delete [] c;
  }

  {
    cout << "\nFuzija nizova pravougaonika:\n\n";
    cin >> na;    Pravoug *a = new Pravoug [na]; cout << "Prvi  niz:";
    for (i=0; i<na; i++) {cin >> a[i]; cout << ' ' << a[i];} cout << endl;
    cin >> nb;    Pravoug *b = new Pravoug [nb]; cout << "Drugi niz:";
    for (i=0; i<nb; i++) {cin >> b[i]; cout << ' ' << b[i];} cout << endl;
    nc = na + nb; Pravoug *c = new Pravoug [nc]; cout << "Fuzija   :";
    fuzija (a, na, b, nb, c, nc);
    for (i=0; i<nc; i++) {             cout << ' ' << c[i];} cout << endl;
    delete [] a; delete [] b; delete [] c;
  }

  return 0;
}
