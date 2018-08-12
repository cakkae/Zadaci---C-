// kvadar1.h - Definicija klase kvadara.

#include <iostream>
using namespace std;

class Kvadar {
  static double Vmax, Vuk;       // Dozvoljena i trenutna ukupna zapremina.
  double a, b, c;                // Duzine ivica kvadra.

  Kvadar (double aa, double bb, double cc) // Konstruktor samo za interne
    { a = aa; b = bb; c = cc; }            //   potrebe.

public:
  static bool postaviVmax (double maxV) {  // Postavljanje maksimalne
    if (maxV < Vuk) return false;          //   zapremine.
    Vmax = maxV;
    return true;
  }

  static double uzmiVmax ()                // Dohvatanje maksimalne
    { return Vmax; }                       //   zapremine.

  static double uzmiVuk ()                 // Dohvatanje trenutne
    { return Vuk; }                        //   ukupne zapremine.

  static Kvadar* pravi (double a, double b, double c) { // Stvaranje
    double V = a * b * c;                  //   dinamickog kvadra.
    if (a<=0 || b<=0 || c<= 0 || Vuk+V>Vmax) return 0;
    Vuk += V;
    return new Kvadar (a, b, c);
  }

  static Kvadar* citaj () {                // Citanje kvadra.
    double a, b, c; cin >> a >> b >> c;
    return pravi (a, b, c);
  }

  ~Kvadar () { Vuk -= a * b * c; }         // Unistavanje kvadra.

  double uzmiA () const { return a; }      // Dohvatanje duzina ivica.
  double uzmiB () const { return b; }
  double uzmiC () const { return c; }

  double V () const { return a * b * c; }  // Zapremina kvadra.

  void pisi () const                       // Pisanje kvadra.
    { cout << "kvadar[" << a << ',' << b << ',' << c << ']'; }
};