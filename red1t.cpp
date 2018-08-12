// red1t.C - Ispitivanje paketa za obradu redova celih brojeva.

#include "red1.h"
#include <iostream>
using namespace std;

int main () {
  Red r = pravi ();
  for (bool dalje=true; dalje; ) {
    cout << "\n1. Dodaj broj        4. Pisi red\n"
              "2. Uzmi broj         5. Brisi red\n"
              "3. Uzmi duzinu       0. Zavrsi\n\n"
              "Vas izbor? ";
    int izb; cin >> izb;
    switch (izb) {
      case 1: int b; cout << "Broj? "; cin >> b; dodaj (r, b); break;
      case 2: if (!prazan(r)) cout << "Broj= " << uzmi (r) << endl;
                else cout << "Red je prazan!\n";
              break;
      case 3: cout << "Duzina= " << duz (r) << endl; break;
      case 4: cout << "Red= "; pisi (r); cout << endl; break;
      case 5: brisi (r); break;
      case 0: dalje = false; break;
      default: cout << "Nedozvoljen izbor!\n"; break;
    }
  }
  return 0;
}
