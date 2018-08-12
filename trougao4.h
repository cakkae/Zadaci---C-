// trougao4.h - Klase obojenih trouglova u ravni.

#ifndef _trougao4_h_
#define _trougao4_h_

#include "figura3.h"

namespace Figure {
  class Trougao: public Figura {
    Tacka A, B, C;                           // Temena.
  public:                                    // Konstruktor.
    Trougao (Tacka P, Tacka Q, Tacka R, Boja b=Boja())
      : Figura (b), A(P), B(Q), C(R) {}
    Trougao* kopija () const { return new Trougao (*this); } // Kopija.
    bool pripada (const Tacka& T) const {    // Da li tacka pripada?
      return provera(T,A,B,C) && provera(T,B,C,A) && provera (T,C,A,B);
    }
  private:
    // Da li se tacke P i Q nalaze s iste strane duzi AB?
    static bool provera (Tacka P, Tacka Q, Tacka A, Tacka B) {
      double t = B.x()-A.x(), u = B.y()-A.y();
      return ((P.x()-A.x())/t - (P.y()-A.y())/u) *
             ((Q.x()-A.x())/t - (Q.y()-A.y())/u)   >= 0;
    }
  }; // class Trougao
} // namespace Figure

#endif
