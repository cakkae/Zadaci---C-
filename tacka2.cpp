// tacka2.C - Definicije metoda klase tacaka u ravni.

#include "tacka2.h"
#include <cmath>
#include <iostream>
using namespace std;

double Tacka::rastojanje (Tacka t) const   // Rastojanje do tacke.
  { return sqrt (pow(x-t.x,2) + pow(y-t.y,2)); }

Tacka citaj ()                             // Citanje tacke.
  { Tacka t; cin >> t.x >> t.y; return t; }

void pisi (Tacka t)                        // Pisanje tacke.
  { cout << '(' << t.x << ',' << t.y << ')'; }
