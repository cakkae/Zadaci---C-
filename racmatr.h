// racmatr.h - Klasa matrica racionalnih brojeva.

#ifndef _racmatr_h_
#define _racmatr_h_

#include "racbroj.h"
#include <iostream>
using namespace std;

namespace Aritmetika {
  class GRacMatInd {}; // Klasa za gresku: Indeks izvan opsega.
  class GRacMatDim {}; // Klasa za gresku: Neusaglasene dimenzije.
  class GRacMatInv {}; // Klasa za gresku: Ne postoji inverzna matrica.
  class GRacMatKvd {}; // Klasa za gresku: Matrica nije kvadratna.

  class RacMatr {
    typedef const RacBroj CRB;             // Nepromenljiv racionalan broj.
    typedef const RacMatr CRM;             // Nepromenljiva matrica.
    RacBroj **niz; int m, n;               // Elementi i dimenzije matrice.
    void pravi (int v, int k, CRB& r);     // Dodela memorije.
    void kopiraj (CRM& a);                 // Kopiranje.
    void brisi ();                         // Oslobadjanje memorije.
    RacMatr inv_det (RacBroj& det) const;  // Inverzna matrica i determ.
  public:                                  // Inicijalizacija:
    RacMatr (int v, int k, RacBroj r=0)    // - pravougaona matr.,
      { pravi (v, k, r); }
    explicit RacMatr (int v=5, RacBroj r=0)// - kvadratna matrica,
      { pravi (v, v, r); }
    RacMatr (CRM& a) { kopiraj (a); }      // - kopija matrice.
    ~RacMatr () { brisi (); }              // Unistavanje.
    RacMatr& operator= (CRM& b) {          // A = B
      if (this != &b) { brisi (); kopiraj (b); }
      return *this;
    }
    int vrs () const { return m; }                  // Broj vrsta.
    int kol () const { return n; }                  // Broj kolona.
    const RacBroj*const& operator[] (int i) const { // A[i] (pok. na vrstu):
      if (i<0 || i>=m) throw GRacMatInd ();         // - nepromenljiva matr,
      return niz[i];
    }
    RacBroj*const& operator[] (int i)               // - promenljiva matr.
      { return (RacBroj*const&) (*this)[i]; }

    RacMatr operator+ () const { return *this; }  // +A
    RacMatr operator- () const;                   // -A
    friend RacMatr T   (CRM& a);                  // Transponovana matrica.
    friend RacMatr inv (CRM& a)                   // Invrezna matrica.
      { RacBroj det; return a.inv_det (det); }
    friend RacBroj det (CRM& a)                   // Determinanta.
      { RacBroj det; a.inv_det (det); return det; }

    RacMatr& operator+= (CRM& b);                                 // A += B
    RacMatr& operator-= (CRM& b);                                 // A -= B
    RacMatr operator+ (CRM& b) const { return RacMatr(*this)+=b; }// A +  B
    RacMatr operator- (CRM& b) const { return RacMatr(*this)-=b; }// A -  B

    RacMatr operator* (CRM& b) const;                             // A *  B
    RacMatr operator/ (CRM& b) const { return *this * inv(b); }   // A /  B
    RacMatr& operator*= (CRM& b) { return *this = *this * b; }    // A *= B
    RacMatr& operator/= (CRM& b) { return *this = *this / b; }    // A /= B

    RacMatr& operator+= (CRB& r);                                 // A += r
    RacMatr& operator-= (CRB& r) { return *this += -r; }          // A -= r
    RacMatr& operator*= (CRB& r);                                 // A *= r
    RacMatr& operator/= (CRB& r) { return *this *= !r; }          // A /= r

    friend RacMatr operator+ (CRB& r, CRM& a)                     // r +  A
      { return RacMatr (a) += r; }
    friend RacMatr operator- (CRB& r, CRM& a)                     // r -  A
      { return RacMatr (-a) += r; }
    friend RacMatr operator* (CRB& r, CRM& a)                     // r *  A
      { return RacMatr (a) *= r; }
    friend RacMatr operator/ (CRB& r, CRM& a)                     // r /  A
      { return inv(a) *= r; }

    RacMatr operator+ (CRB& r) const { return  r + *this; }       // A +  r
    RacMatr operator- (CRB& r) const { return  r - *this; }       // A -  r
    RacMatr operator* (CRB& r) const { return  r * *this; }       // A *  r
    RacMatr operator/ (CRB& r) const { return  r / *this; }       // A /  r

    bool operator== (CRM& b) const;                               // A == B
    bool operator!= (CRM& b) const { return ! (*this == b); }     // A != B

    friend istream& operator>> (istream& ut, RacMatr& a);         // Citanje.
    friend ostream& operator<< (ostream& it, CRM& a);             // Pisanje.
  };
}

#endif
