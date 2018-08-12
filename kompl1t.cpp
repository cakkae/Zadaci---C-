// kompl1t.cpp - Ispitivanje klase kompleksnih brojeva
//              (tabeliranje kompleksnog polinoma).

#include "kompl1.h"
#include <iostream>
using namespace std;

Kompl poli (const Kompl p[], int n, Kompl z) {
  Kompl s = p[n];
  for (int i=n-1; i>=0; (s*=z)+=p[i--]);
  return s;
}

int main () {
  cout << "Red polinoma? "; int n; cin >> n;
  Kompl* p = new Kompl [n+1];
  cout << "Koeficijenti? "; for (int i=n; i>=0; cin>>p[i--]);
  cout << "z0, dz, k? ";
  Kompl z, dz; int k; cin >> z >> dz >> k; cout << endl;
  for (int i=0; i<k; i++, z+=dz)
    cout << z << '\t' << poli(p,n,z) << endl;
  delete [] p;
  return 0;
}
