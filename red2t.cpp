// red2t.C - Ispitivanje klase redova ogranicenih kapacieta.

#include "red2.h"
#include <iostream>
using namespace std;

int main () {
  Red* rd = new Red (5); bool kraj = false;
  while (! kraj) {
    cout << "\n1. Stavaranje reda\n"
              "2. Stavljanje podatka u red\n"
              "3. Uzimanje podatka iz reda\n"
              "4. Ispisivanje sadrzaja reda\n"
              "5. Praznjenje reda\n"
              "0. Zavrsetak rada\n\n"
              "Vas izbor? ";
    int izbor; cin >> izbor;
    switch (izbor) {
    case 1: // Stvaranje novog reda:
      cout << "Kapacitet? "; int k; cin >> k;
      if (k > 0) { delete rd; rd = new Red (k); }
        else cout << "*** Nedozvoljeni kapacitet! ***\a\n";
      break;
    case 2: // Stavljanje podatka u red:
      if (! rd->pun ()) {
        cout << "Broj?      "; int b; cin >> b; rd->stavi (b);
      } else cout << "*** Red je pun! ***\a\n";
      break;
    case 3: // Uzimanje podatka iz reda:
      if (! rd->prazan ())
        cout << "Broj=      " << rd->uzmi () << endl;
      else cout << "*** Red je prazan! ***\a\n";
      break;

    case 4: // Ispisivanje sadrzaja reda:
      cout << "Red=       "; rd->pisi (); cout << endl;
      break;
    case 5: // Praznjenje reda:
      rd->prazni (); break;
    case 0: // Zavrsetak rada:
      kraj = true; break;
    default: // Pogresan izbor:
      cout << "*** Nedozvoljen izbor! ***\a\n"; break;
    }
  }
  return 0;
}
