// tacka5.C - Metode klase tacaka u ravni.

#include "tacka5.h"

                                                // Pisanje niza tacaka.
void Linije::Tacka::pisiNiz (ostream& it, const Tacka* niz, int duz) {
  it << '(';
  for (int i=0; i<duz; i++) {
    if (i) it << ',';
    it << niz[i];
  }
  it << ')';
}
