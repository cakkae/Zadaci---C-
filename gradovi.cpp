// gradovi.C - Uredjivanje imena gradova smestenih u dinamicku matricu.

#include <string.h>
#include <iostream>
using namespace std;

const int MAX_GRAD = 100;
const int MAX_DUZ  = 30;

int main () {

  // Citanje i obrada pojedinacnih imena:
  cout << "\nNeuredjeni niz imena gradova:\n\n";
  char** gradovi = new char* [MAX_GRAD];
  int  br_grad=0;
  do {

    char* grad = new char [MAX_DUZ];
    cin.getline (grad, MAX_DUZ);    // Citanje sledeceg imena.
    int duz = strlen (grad);

  // Kraj ako je duzina imena nula.
  if (!duz) { delete [] grad; break; }

    char* pom = new char [duz+1];    // Skracivanje niza.
    strcpy (pom, grad);
    delete [] grad; grad = pom;
    cout << grad << endl;            // Ispisivanje imena.

    // Uvrstavanje novog imena u uredjeni niz starih imena:
    int i;
    for (i=br_grad-1; i>=0; i--)
      if (strcmp (gradovi[i], grad) > 0)
        gradovi[i+1] = gradovi[i];
      else break;
    gradovi[i+1] = grad;

    // Nastavak rada ako ima jos slobodnih vrsta u matrici.
  } while (++br_grad < MAX_GRAD);
  
  char** pom = new char* [br_grad];  // Skracivanje niza.
  for (int i=0; i<br_grad; i++) pom[i] = gradovi[i];
  delete [] gradovi; gradovi = pom;

  // Ispisivanje uredjenog niza imena:
  cout << "\nUredjeni niz imena gradova:\n\n";
  for (int i=0; i<br_grad; cout<<gradovi[i++]<<endl);
  return 0;
}
