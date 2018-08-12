// lista1.C - Obrada jednostruko spregnute liste.

#include <iostream>
using namespace std;

struct Elem { int broj; Elem* sled; };

Elem* citaj () {          // Stvaranje liste citajuci.
  int broj; Elem *lst=0, *tek=0;
  while (true) {
    cin >> broj;
  if (broj ==9999) break;
    Elem* novi = new Elem;
    novi->broj = broj; novi->sled = 0;
    tek = (lst==0 ? lst : tek->sled) = novi;
  }
  return lst;
}

void pisi (Elem* lst) {   // Ispisivanje liste.
  while (lst) { cout << lst->broj << ' '; lst = lst -> sled; }
}

void brisi (Elem*& lst) { // Unistavanje liste.
  while (lst) { Elem* stari = lst; lst = lst->sled; delete stari; }
}

int main () {             // Ispitivanje funkcija.
  Elem* lista;
  while (true) {
    cout << "\nLista? ";
  if ((lista = citaj())==0) break;
    cout << "Procitano: "; pisi (lista); cout << endl;
    brisi (lista);
  }
  return 0;
}
