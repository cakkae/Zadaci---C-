// red2.h - Definicija klase redova ogranicenih kapaciteta.

class Red {
  int *niz, kap, duz, prvi, posl;
public:
  explicit Red (int k=10);      // Stvaranje praznog reda (nije konverzija).
  Red (const Red& rd);          // Stvaranje reda od kopije drugog.
  ~Red () { delete [] niz; }                // Unistavanje reda.
  void stavi (int b);                       // Stavljanje broja u red.
  int uzmi ();                              // Uzimanje broja iz reda.
  bool prazan () const { return duz == 0; } // Da li je red prazan?
  bool pun () const { return duz == kap; }  // Da li je red pun?
  void pisi () const ;                      // Pisanje sadrzaja reda.
  void prazni () { duz = prvi = posl = 0; } // Praznjenje reda.
};
