// lista2.h - Definicija klase lista celih brojeva (iterativno).

class Lista {
  struct Elem {                 // ELEMENT LISTE:
    int broj;                   // - sadrzaj,
    Elem* sled;                 // - pokazivac na sledeci element,
    Elem (int b, Elem* s=0)     // - konstruktor.
      { broj=b; sled = s; }
  };
  Elem* prvi;                   // Pokazivac na pocetak liste.
public:                         // Konstruktori:
  Lista () { prvi = 0; }        // - podrazumevani,
  Lista (int b)                 // - konverzije,
    { prvi = new Elem (b); }
  Lista (const Lista& lst);     // - kopije.
  ~Lista () { brisi (); }       // Destruktor.
  int duz () const;             // Broj elemenata liste.
  void pisi () const;           // Pisanje liste.
  void naPocetak (int b)        // Dodavanje na pocetak.
    { prvi = new Elem (b, prvi); }
  void naKraj (int b);          // Dodavanje na kraj.
  void citaj1 (int n); // Citanje liste stavljajuci brojeve na pocetak.
  void citaj2 (int n); // Citanje liste stavljajuci brojeve na kraj.
  void umetni (int b);          // Umetanje u uredjenu listu.
  void brisi ();                // Brisanje svih elemenata liste.
  void izostavi (int b);        // Izostavljanje svakog pojavljivanja.
};
