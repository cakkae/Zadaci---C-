// kvadar2.h - Definicija klase numerisanih kvadara.

#include <iostream>
using namespace std;

class Kvadar {
  static int ukId;       // Poslednje korisceni identifikator.
  int id;                // Identifikator kvadra.
  double a, b, c;        // Duzine ivica.
public:
  explicit Kvadar (double aa=1, double bb=1, double cc=1) // Novom kvadru
    { id = ++ukId; a = aa; b = bb; c = cc; }              //   nov broj.
  Kvadar (const Kvadar& k)                           // Kopiji nov broj.
    { id = ++ukId; a = k.a; b = k.b; c = k.c; }
  Kvadar& operator= (const Kvadar& k)                // Levom operandu
    { a = k.a; b = k.b; c = k.c; return *this; }     //   se ne menja broj.
  double V () const { return a * b * c; }                     // Zapremina.
  friend bool operator< (const Kvadar& k1, const Kvadar& k2)  // k1 < k2
    { return k1.V () < k2.V (); }
  friend istream& operator>> (istream& ut, Kvadar& k)         // Citanje.
    { return ut >> k.a >> k.b >> k.c; }
  friend ostream& operator<< (ostream& it, const Kvadar& k) { // Pisanje.
    return it << 'K' << k.id << '(' << k.a << ','
              << k.b << ',' << k.c << ')';
  }
};
