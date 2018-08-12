// poli1t.C - Ispitivanje klase polinoma.

#include "poli1.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main () {
  // Definisanje tri polinoma i inicijalizacija kao prazni polinomi.
  Poli p1, p2, p3;

  // Citanje polinoma, aritmeticke operacije i dodela vrednosti.
  cin >> p1;    cout << "p1    = " << p1 << endl;
  cin >> p2;    cout << "p2    = " << p2 << endl;
  p3 = p1 + p2; cout << "p1+p2 = " << p3 << endl;
  p3 = p1 - p2; cout << "p1-p2 = " << p3 << endl;
  p3 = p2 - p1; cout << "p2-p1 = " << p3 << endl;
  p3 = p1 - p1; cout << "p1-p1 = " << p3 << endl;
  p3 = p1 * p2; cout << "p1*p2 = " << p3 << endl;

  // Konverzija polinoma u niz i obrnuto.
  double* a = new double [p1.red() + 1]; int n; p1.niz (a, n);
  cout << "a     = ";
    for (int i=n;   i>=0; i--) cout << a[i] << ' '; cout << endl;
  p3 = Poli (a, n); cout << "p(a,n)= ";
    for (int i=p3.red(); i>=0; i--) cout << p3[i] << ' '; cout << endl;
  delete [] a;

  // Koriscenje pokazivaca na polinom.
  Poli* pp4 = new Poli (p1);
  cout << "*pp4  = " <<  *pp4   << endl;
  delete pp4;
 
  // Tabeliranje polinoma.
  double xmin, xmax, dx; cin >> xmin >> xmax >> dx;
  cout << "\nxmin, xmax, dx = "
       << xmin << ", " << xmax << ", " << dx << endl;
  cout << "\n   x       p1(x)\n==================\n" << fixed;
  for (double x=xmin; x<=xmax; x+=dx)
    cout << setprecision(2) << setw(6)  << x
         << setprecision(6) << setw(12) << p1 (x) << endl;
  return 0;
}
