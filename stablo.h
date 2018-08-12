// stablo.h - Definicija klase uredjenih binarnih stabala.

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Stablo {
  struct Cvor {                            // CVOR STABLA:
    int broj;                              // - sadrzaj cvora,
    Cvor *levo, *desno;                    // - levo i desno podstablo,
    Cvor (int b, Cvor* l=0, Cvor* d=0)     // - konstruktor.
      { broj = b; levo = l; desno = d; }
  };
  Cvor *stb;                               // Pokazivac na koren stabla.
public:
  Stablo () {stb = 0; }                      // Prazno stablo.
  Stablo (int b) { stb = new Cvor (b); }     // Konverzija.
  Stablo (const Stablo& stablo) { stb = kopiraj (stablo.stb); } // Kopija.
  ~Stablo () { brisi (stb); }                // Destruktor.
  bool prazno() const { return stb == 0; }   // Da li je stablo prazno?
  int vel () const { return vel (stb); }     // Broj cvorova u stablu.
  int zbir () const { return zbir (stb); }   // Zbir brojeva u stablu.
  void pisiKLD () const { pisiKLD (stb); }   // Prefiksno pisanje.
  void pisiLKD () const { pisiLKD (stb); }   // Infiksno pisanje.
  void pisiLDK () const { pisiLDK (stb); }   // Postfiksno pisanje.
  void crtaj () const { crtaj (stb, 0); }    // Graficki prikaz stabla.
  int pojav (int b) const                    // Broj pojavljivanja.
    { return pojav (stb, b); }
  int min () const {                         // Najmanji u stablu.
    if (!stb) exit (1);                      //   (ne sme biti prazno)
    return min (stb);
  }
  int max () const {                         // Najveci u stablu.
    if (!stb) exit (1);                      //   (ne sme biti prazno)
    return min (stb);
  }
  Cvor *nadji (int b) const                  // Trazenje u stablu.
    { return nadji (stb, b); }
  void dodaj (int b) { dodaj (stb, b); }     // Dodavanje u stablo.
  void citaj (int n);                        // Citanje stabla.
  void brisi () { brisi (stb); }             // Brisanje celog stabla.
  void izost (int b) { izost (stb, b); }     // Izostavljanje iz stabla.
  void balans () { balans (stb); }           // Balansiranje stabla.
private:                                     // POMOCNE REKURZIVNE METODE:
  static Cvor* kopiraj (Cvor* stb) {         // Kopiranje stabla.
    return stb ?
      new Cvor (stb->broj,kopiraj(stb->levo),kopiraj(stb->desno)) : 0;
  }
  static int vel (Cvor* stb)                 // Broj cvorova u stablu.
    { return stb ? 1 + vel (stb->levo) + vel (stb->desno) : 0; }
  static int zbir (Cvor* stb)                // Zbir brojeva u stablu.
    { return stb ? stb->broj + zbir (stb->levo) + zbir (stb->desno) : 0; }
  static void pisiKLD (Cvor* stb) {          // Prefiksno ispisivanje.
    if (stb) {
      cout << stb->broj << ' '; pisiKLD(stb->levo); pisiKLD(stb->desno);
    }
  }
  static void pisiLKD (Cvor* stb) {          // Infiksno ispisivanje.
    if (stb) {
      pisiLKD(stb->levo); cout << stb->broj << ' '; pisiLKD(stb->desno);
    }
  }
  static void pisiLDK (Cvor* stb) {          // Postfiksno ispisivanje.
    if (stb) {
      pisiLDK(stb->levo); pisiLDK(stb->desno); cout << stb->broj << ' ';
    }
  }
  static void crtaj (Cvor* stb, int nivo) {  // Graficki prikaz stabla.
    if (stb) {
      crtaj (stb->desno, nivo+1);
      cout << setw(4*nivo) << "" << stb->broj << endl;
      crtaj (stb->levo,  nivo+1);
    }
  }
  static int pojav (Cvor* stb, int b) {      // Broj pojavljivanja u stablu.
    return stb ? (stb->broj==b)+pojav(stb->levo,b)+pojav(stb->desno,b)
               : 0;
  }
  static int min (Cvor* stb)                 // Najmanji u stablu.
    { return stb->levo ? min (stb->levo) : stb->broj; }
  static int max (Cvor* stb)                 // Najveci u stablu.
    { return stb->desno ? max (stb->desno) : stb->broj; }
  static Cvor *nadji (Cvor* stb, int b){     // Trazenje u stablu.
    if (! stb)          return 0;
    if (stb->broj == b) return stb;
    if (stb->broj >  b) return nadji (stb->levo,  b);
                        return nadji (stb->desno, b);
  }
  static void dodaj (Cvor*& stb, int b) {    // Dodavanje u stablo.
    if (! stb)                           stb = new Cvor (b);
    else if (stb->broj > b)              dodaj (stb->levo,  b);
    else if (stb->broj < b)              dodaj (stb->desno, b);
    else if (rand()/(RAND_MAX+1.) < 0.5) dodaj (stb->levo,  b);
    else                                 dodaj (stb->desno, b);
  }

  static void brisi (Cvor*& stb) {           // Brisanje celog stabla.
    if (stb) {
      brisi (stb->levo); brisi (stb->desno); delete stb; stb = 0;
    }
  }
  static void izost (Cvor*& stb, int b) {    // Izostavljanje iz stabla.
    if (stb) {
      if      (stb->broj > b) izost (stb->levo,  b);
      else if (stb->broj < b) izost (stb->desno, b);
      else if (stb->levo) {
        int m = max (stb->levo);
        stb->broj = m; izost (stb->levo,  m);
      } else if (stb->desno) {
        int m = min (stb->desno);
        stb->broj = m; izost (stb->desno, m);
      } else {
        delete stb; stb = 0;
      }
    }
  }
  static void balans (Cvor*& stb);           // Balansiranje stabla.
};
