// sekvenca.C - Metode klase sekvenci.

#include "sekvenca.h"

namespace Naredbe {
  void Sekvenca::kopiraj (const Sekvenca& s) {    // Kopiranje u objekat.
    prva = 0; Elem *posl = 0;
    for (Elem* tek=s.prva; tek; tek=tek->sled)
      posl = (!prva ? prva : posl->sled) = new Elem (tek->nar->kopija());
  }

  void Sekvenca::pisi (ostream& it) const {       // Pisanje.
    Naredba::pisi (it); it << "{\n";
    nivo++;
    for (Elem* tek=prva; tek; tek=tek->sled) it << *tek->nar;
    nivo--;
    Naredba::pisi (it); it << "}\n";
  }

  void Sekvenca::radi () const {                  // Izvrsavanje.
    for (Elem* tek=prva; tek; tek=tek->sled) tek->nar->radi ();
  }
} // namespace Naredbe