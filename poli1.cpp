// poli1.C - Definicije metoda i funkcija uz klasu polinoma.

#include "poli1.h"
#include <cstdlib>
using namespace std;

void Poli::greska (Greska g) const {           // Obrada greske.
  const char* poruke[] = { "Nedozvoljen red polinoma",
                           "Nedozvoljen indeks koeficijenta polinoma"
                         };
  cout << "*** " << poruke[g] << "! ***\n";
  exit (g+1);
}

void Poli::kopiraj (const double* aa, int nn){ // Kopiranje u tekuci objekat
  if ((n = nn) < -1) greska (GRED);
  a = new double [nn+1];
  for (int i=0; i<=nn; i++) a[i] = aa[i];
}

void Poli::niz (double* aa, int& nn) const     // Smestanje polinoma u niz.
  { for (int i=0; i<=n; i++) aa[i] = a[i]; nn = n; }

double Poli::operator() (double x) const       // Vrednost polinoma.
  { double s = 0; for (int i=n; i>=0; (s*=x)+=a[i--]); return s; }

double& Poli::operator[] (int ind) {           // Pristupanje koeficijentu.
  if (ind < 0 || ind > n) greska (GIND);
  return a[ind];
}
const double& Poli::operator[] (int ind) const {
  if (ind < 0 || ind > n) greska (GIND);
  return a[ind];
}

Poli operator+ (const Poli& p1, const Poli& p2){ // Zbir dva polinoma.
  int n;
  if (p1.n == p2.n) for (n=p1.n; n>=0 && p1.a[n]+p2.a[n]==0; n--);
    else            n = (p1.n > p2.n) ? p1.n : p2.n;
  Poli p; p.n = n; p.a = new double [n+1];
  for (int i=0; i<=n; i++)
    p.a[i] = (i > p2.n) ? p1.a[i]           :
             (i > p1.n) ?           p2.a[i] :
                          p1.a[i] + p2.a[i];
  return p;
}

Poli operator- (const Poli& p1, const Poli& p2){ // Razlika dva polinoma.
  int n;
  if (p1.n == p2.n) for (n=p1.n; n>=0 && p1.a[n]-p2.a[n]==0; n--);
    else            n = (p1.n > p2.n) ? p1.n : p2.n;
  Poli p; p.n = n; p.a = new double [n+1];
  for (int i=0; i<=n; i++)
    p.a[i] = (i > p2.n) ? p1.a[i]           :
             (i > p1.n) ?         - p2.a[i] :
                          p1.a[i] - p2.a[i];
  return p;
}

Poli operator* (const Poli& p1, const Poli& p2){ // Proizvod dva polinoma.
  int n = (p1.n>=0 && p2.n>=0) ? p1.n+p2.n : -1;
  Poli p; p.n = n; p.a = new double [n+1];
  for (int i=0; i<=n; p.a[i++]=0);
  for (int i=0; i<=p1.n; i++)
    for (int j=0; j<=p2.n; j++)
      p.a[i+j] += p1.a[i] * p2.a[j];
  return p;
}

istream& operator>> (istream& ut, Poli& p) {      // Citanje polinoma.
  p.brisi ();
  ut >> p.n;  if (p.n < -1) p.greska (Poli::GRED);
  p.a = new double [p.n+1];
  for (int i=p.n; i>=0; ut >> p.a[i--]);
  return ut;
}

ostream& operator<< (ostream& it, const Poli& p){ // Pisanje polinoma.
  it << "p[";
  for (int i=p.n; i>=0; i--) it << p.a[i] << (i ? "," : "");
  it << ']';
  return it;
}
