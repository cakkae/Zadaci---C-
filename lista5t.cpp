// lista5t.C - Ispitivanje klasa neuredjenih i uredjenih listi.

#include "lista4.h"
#include "lista5.h"
#include <iostream>
using namespace std;

int main () {
  NLista lst1; ULista lst2; cout << "Niz? ";
  do { int b; cin >> b; lst1 += b; lst2 += b; } while (cin.get() != '\n');
  cout << "Neuredjeno= " << lst1 << endl;
  cout << "Uredjeno  = " << lst2 << endl;
  NLista lst3; cout << "Niz? ";
  do { int b; cin >> b; lst3 += b; } while (cin.get() != '\n');
  cout << "Neuredjeno= " << (lst1+=lst3) << endl;
  cout << "Uredjeno  = " << (lst2+=lst3) << endl;
  cout << "Neuredjeno= " << (lst1+=lst1) << endl;
  cout << "Uredjeno  = " << (lst2+=lst2) << endl;
  return 0;
}
