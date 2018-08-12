// stablot.C - Ispitivanje klase uredjenih binarnih stabala.

#include "stablo.h"
#include <iostream>
using namespace std;

// Primena operacije na stablo za svaki procitani broj:
void radi (Stablo& stb, void (Stablo::*pf)(int)) {
  int b; cout << "Brojevi?   ";
  do { cin >> b; (stb.*pf)(b); } while (cin.get() != '\n');
}                                       // do kraja reda

int main () {
  Stablo stb; bool kraj = false;
  while (!kraj) {
    cout << endl <<
      "a) Dodavanje brojeva         Pisanje stabla:\n"
      "b) Izostavljanje brojeva       1. koren-levo-desno\n"
      "c) Citanje stabla              2. levo-koren-desno (uredjeno)\n"
      "d) Najmanji element            3. levo-desno-koren\n"
      "e) Najveci element             4. crtanje\n"
      "f) Pretrazivanje             i) Velicina stabla\n"
      "g) Balansiranje              j) Zbir elemenata\n"
      "h) Praznjenje stabla         k) Broj pojavljivanja\n"
      "                             z) Zavrsetak rada\n\n"
      "Vas izbor? ";
    char izbor; cin >> izbor;
    switch (izbor) {
      int broj;
    case 'a': case 'A': // Dodavanje brojeva u stablo:
      radi (stb, &Stablo::dodaj); break;
    case 'b': case 'B': // Izostavljanje brojeva iz stabla:
      radi (stb, &Stablo::izost); break;
    case 'c': case 'C': // Citanje stabla:
      cout << "Duzina?    "; int n; cin >> n;
      cout << "Brojevi?   "; stb.citaj (n);
      break;
    case 'd': case 'D': case 'e': case 'E':
      if (!stb.prazno()) switch (izbor) {
        case 'd': case 'D': // Najmanji element stabla:
          cout << "min=       " << stb.min (); break;
        case 'e': case 'E': // Najveci element stabla:
          cout << "max=       " << stb.max (); break;
      } else cout << "*** Stablo je parzno! ***\a\n";
      break;
    case 'f': case 'F': // Pretrazivanje stabla:
      cout << "Broj?      "; cin >> broj;
      cout << "Broj se" << (stb.nadji (broj) ? "" : " NE")
           << " nalazi u stablu.\n";
      break;
    case 'g': case 'G': // Balansiranje stabla:
      stb.balans (); break;
    case 'h': case 'H': // Praznjenje stabla:
      stb.brisi (); break;
    case 'i': case 'I': // Velicina stabla:
      cout << "Vel=       " << stb.vel ()  << endl; break;
    case 'j': case 'J': // Zbir elemenata stabla:
      cout << "Zbir=      " << stb.zbir () << endl; break;
    case 'k': case 'K': // Broj pojavljivanja datog broja:
      cout << "Broj?      "; cin >> broj;
      cout << "Broj se pojavljuje " << stb.pojav(broj) << " puta.\n";
      break;
    case '1':           // Pisanje stabla koren-levo-desno:
      cout << "Stablo=    "; stb.pisiKLD (); cout << endl;  break;
    case '2':           // Pisanje stabla levo-koren-desno:
      cout << "Stablo=    "; stb.pisiLKD (); cout << endl;  break;
    case '3':           // Pisanje stabla levo-desno-koren:
      cout << "Stablo=    "; stb.pisiLKD (); cout << endl;  break;
    case '4':           // Crtanje stabla:
      stb.crtaj (); break;
    case 'z': case 'Z': // Zavrsetak rada:
      kraj = true; break;
    default: // Pogresan izbor:
      cout << "*** Nedozvoljen izbor! ***\a\n"; break;
    }
  }
  return 0;
}
