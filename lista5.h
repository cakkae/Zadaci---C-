// lista5.h - Klasa uredjenih listi celih brojeva.

#ifndef _lista5_h_
#define _lista5_h_

#include "lista4.h"

class ULista: public NLista {
public:                                            // Konstruktori:
  ULista () {}                                     // - prazna lista,
  ULista (int b): NLista (b) {}                    // - konverzija.
  ULista& operator+= (int b);                      // Dodavanje broja.
  ULista& operator+= (const NLista& lst)           // Dodavanje liste.
    { NLista::operator+= (lst); return *this; }
};

#endif
