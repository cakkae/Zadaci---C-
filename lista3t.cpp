// lista3t.C - Ispitivanje klase lista celih brojeva.

#include "lista3.h"

int main () {
  Lista lst; bool kraj = false;
  while (!kraj) {
    cout << "\n1. Dodavanje broja na pocetak liste\n"
              "2. Dodavanje broja na kraj liste\n"
              "3. Umetanje broja u uredjenu listu\n"
              "4. Izostavljanje broja iz liste\n"
              "5. Brisanje svih elemenata liste\n"
              "6. Citanje uz obrtanje redosleda brojeva\n"
              "7. Citanje uz cuvanje redosleda brojeva\n"
              "8. Odredjivanje duzine liste\n"
              "9. Ispisivanje liste\n"
              "0. Zavrsetak rada\n\n"
              "Vas izbor? ";
    int izbor; cin >> izbor;
    switch (izbor) {
    case 1: case 2: case 3: case 4:
      cout << "Broj?      "; int broj; cin >> broj;
      switch (izbor) {
      case 1: // Dodavanje broja na pocetak liste:
        lst.naPocetak (broj); break;
      case 2: // Dodavanje broja na kraj liste:
        lst.naKraj (broj);    break;
      case 3: // Umetanje broja u uredjenu listu:
        lst.umetni (broj);     break;
      case 4: // Izostavljanje broja iz liste:
        lst.izostavi (broj);   break;
      } break;
    case 5: // Brisanje svih elemenata liste:
      lst.brisi (); break;
    case 6: case 7: // Citanje liste:
      cout << "Duzina?    "; int n; cin >> n;
      cout << "Elementi?  ";
      switch (izbor) {
      case 6: // uz obrtanje redosleda brojeva:
        lst.citaj1 (n); break;
      case 7: // uz cuvanje redosleda brojeva:
        lst.citaj2 (n); break;
      } break;
    case 8: // Odredjivanje duzine liste:
      cout << "Duzina=    " << lst.duz() << endl; break;
    case 9: // Ispisivanje liste:
      cout << "Lista=     "; lst.pisi (); cout << endl; break;
    case 0: // Zavrsetak rada:
      kraj = true; break;
    default: // Pogresan izbor:
      cout << "*** Neozvoljen izbor! ***\a\n"; break;
    }
  }
  return 0;
}
