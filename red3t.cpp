// red3t.C - Ispitivanje klase redova neogranicenog kapaciteta.

#include "red3.h"
#include <iostream>
using namespace std;

Red citaj (const char* nasl) {
  Red r; int n, a, i; cin >> n;
  cout << nasl << " :";
  for (i=0; i<n; i++) {cin >> a; cout << ' ' << a; r += a;} cout << endl;
  return r;
}

void pisi (const char* nasl, const Red& red) {
  Red r = red;
  cout << nasl << " :";
  while (r.duzina()) cout << ' ' << r.uzmi(); cout << endl;
}

int main () {
  Red r1 = citaj ("niz1  ");
  pisi  ("r1    ", r1   );
  Red r2 = citaj ("niz2  ");
  pisi  ("r2    ", r2   );
  pisi  ("r1+r2 ", r1+r2);
  pisi  ("r1+=r2", r1+=r2);
  pisi  ("vodeci", r1.vodeci()); // Konverzija int u Red.
  pisi  ("uzmi  ", r1.uzmi());   // Konverzija int u Red.
  pisi  ("r1    ", r1);
  int a; cin  >> a;
  pisi  ("a     ", a);           // Konverzija int u Red.
  pisi  ("r1-a  ", r1-a );
  pisi  ("r1-=a ", r1-=a);
  pisi  ("~r1   ", ~r1   );
  return 0;
}
