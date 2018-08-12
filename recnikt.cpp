// recnikt.C - Ispitivanje klase recnika.

#include "recnik.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main () {
  Recnik r;
  string rec, prevod;
  ifstream ulaz ("recnikt.pod");
  while (ulaz >> rec >> prevod) r.dodaj (rec, prevod);
  cout << "Pocetni sadrzaj recnika:\n\n" << r;
  while (true) {
    cout << "\n1. Trazenje prevoda\n"
              "2. Dodavanje prevoda\n"
              "3. Brisanje prevoda\n"
              "4. Brisanje svih prevoda\n"
              "5. Prikazivanje recnika\n"
              "0. Zavrsetak rada\n\n"
              "Vas izbor? ";
    char izb; cin >> izb;
  if (izb == '0') break;
    switch (izb) {
    case '1': // Trazenje prevoda:
      cout << "Rec?       "; cin >> rec;
      cout << "Prevodi:   "; r.pisiPrevode (cout, rec); cout << endl;
      break;
    case '2': // Dodavanje prevoda:
      cout << "Rec?       "; cin >> rec;
      cout << "Prevod?    "; cin >> prevod;
      if (prevod != "?") r.dodaj (rec, prevod);
      break;
    case '3': // Brisanje prevoda:
      cout << "Rec?       "; cin >> rec;
      cout << "Prevod?    "; cin >> prevod;
      r.brisi (rec, prevod);
      break;
    case '4': // Brisanje svih prevoda:
      cout << "Rec?       "; cin >> rec;
      cout << "Prevodi:   "; r.pisiPrevode (cout, rec); cout << endl;
      cout << "Brisati?   ";
      { string odg; cin >> odg;
        if (toupper (odg[0] == 'D')) r.brisi (rec);
      }
      break;
    case '5': // Prikazivanje recnika:
      cout << endl << r;
      break;
    }
  }
  return 0;
}