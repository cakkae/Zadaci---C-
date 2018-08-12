// niz1.h - Klasa nizova realnih brojeva.

#ifndef _niz1_h_
#define _niz1_h_

class Niz {
  double* a; int n;                            // Niz i duzina niza.
  void kopiraj (const Niz& niz);               // Kopiranje niza.
public:
  explicit Niz (int k=10) { a = new double [n = k]; } // Stvaranje niza.
  Niz (const Niz& niz) { kopiraj (niz); }      // Inicijalizacija nizom.
  ~Niz () { delete [] a; }                     // Unistavanje.
  Niz& operator= (const Niz& niz) {            // Dodela vrednosti.
    if (this != &niz) { delete [] a; kopiraj (niz); }
    return *this;
  }
  double& operator[] (int i) {                 // Pristup elementu
    if (i<0 || i>=n) throw i;                  // - promenljivog niza,
    return a[i];
  }
  const double& operator[] (int i) const {     // - nepromenljivog niza.
    if (i<0 || i>=n) throw i;
    return a[i];
  }
  int duz () const { return n; }               // Duzina niza.
};

#endif
