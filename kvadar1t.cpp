// kvadar1t.C - Ispitivanje klase kvadara.

#include "kvadar1.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main (int, char* varg[]) {
  Kvadar::postaviVmax (atof (varg[1]));

  struct Elem {                    // Element liste kvadara.
    Kvadar* kvad; Elem* sled;
    Elem (Kvadar* kv) { kvad = kv; sled = 0; }
    ~Elem () { delete kvad; }
  };

  for (char jos='d'; jos=='d' || jos=='D'; cout<<"\nJos? ", cin>>jos) {
    Elem *prvi = 0, *posl = 0;

    while (true) {           // Citanje kvadara i stvaranje liste.
      cout << "a,b,c? ";
      if (Kvadar* kv = Kvadar::citaj ())
        posl = (!prvi ? prvi : posl->sled) = new Elem (kv);
      else break;
    }
                             // Zapremine procitanih kvadara.
    cout << "Zapremine:";
    for (Elem* tek=prvi; tek; tek=tek->sled) cout << ' ' << tek->kvad->V ();
    cout << "\nUkupno: " << Kvadar::uzmiVuk () << endl;
                             // Unistavanje liste kvadara.
    while (prvi) { Elem* stari = prvi; prvi = prvi->sled; delete stari; }
    cout << "Ukupno posle brisanja: " << Kvadar::uzmiVuk () << endl;
  }
  return 0;
}
