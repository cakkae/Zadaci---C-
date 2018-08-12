// poli1.h - Definicija klase polinoma.

#include <iostream>
using namespace std;

class Poli {
  int n; double* a;          // Red polinoma i pokazivac na koeficijente.
  typedef const Poli CP;     // Nepromenljiv polinom.
  void kopiraj (const double* a, int n);   // Kopiranje u tekuci objekat.
  void brisi () { delete[] a; a=0; n=-1; } // Pražnjenje polinoma.
public:                                             // Konstruktori:
  Poli () { a = 0; n = -1; }                        // - prazan polinom
  Poli (const double* a, int n) { kopiraj (a, n); } // - od niza
  Poli (CP& p) { kopiraj (p.a, p.n); }              // - od polinoma
  ~Poli () { brisi (); }                            // Destruktor.
  Poli& operator= (CP& p) {                         // Dodela vrednosti.
    if (this != &p) { brisi(); kopiraj(p.a, p.n); }
    return *this;
  }
  void niz (double* a, int& n) const;       // Smeštanje polinoma u niz.
  int red () const { return n; }            // Red polinoma.
  double operator() (double x) const;       // Vrendost polinoma.
  double& operator[] (int ind);             // Pristupanje koeficijentu.
  const double& operator[] (int ind) const;
  friend Poli operator+ (CP& p1, CP& p2) ;                 // p1 +  p2
  friend Poli operator- (CP& p1, CP& p2) ;                 // p1 -  p2
  friend Poli operator* (CP& p1, CP& p2) ;                 // p1 *  p2
  Poli& operator+= (CP& p2) { return *this = *this + p2; } // p1 += p2
  Poli& operator-= (CP& p2) { return *this = *this - p2; } // p1 -= p2
  Poli& operator*= (CP& p2) { return *this = *this * p2; } // p1 *= p2
  friend istream& operator>> (istream& ut, Poli& p) ; // Citanje polinoma
  friend ostream& operator<< (ostream& it, CP& p) ;   // Pisanje polinoma
private:
  enum Greska { GRED, GIND };              // Sifre grešaka.
  void greska (Greska g) const;            // Obrada greške.
};
