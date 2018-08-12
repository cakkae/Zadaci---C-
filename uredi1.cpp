// uredi1.C - Uredjivanje dinamickog niza celih brojeva.

#include <iostream>
using namespace std;

int main () {
  while (true) {
    int n; cout << "Duzina niza?  "; cin >> n;
  if (n <= 0) break;
    int* a = new int [n];
    cout << "Pocetni niz?  ";
    for (int i=0; i<n; cin >> a[i++]);
    for (int i=0; i<n-1; i++) {
      int& b = a[i];      // b je u stvari a[i].
      for (int j=i+1; j<n; j++)
        if (a[j]<b) { int c=b; b=a[j]; a[j]=c; }
    }
    cout << "Uredjeni niz: ";
    for (int i=0; i<n; cout << a[i++] << ' ');
    cout << endl;
    delete [] a;
  }
  return 0;
}
