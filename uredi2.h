// uredi2.h - Genericka klasa za uredjivanje niza podataka.

#include "raste.h"

template <typename T, class U=Raste<T> >
  class Uredi {                                   // Definicija klase.
  public:
    static void uredi (T *a, int n) ;
  };

template <typename T, class U>
  void Uredi<T,U>::uredi (T *a, int n) {          // Definicija metode.
    for (int i=0; i<n-1; i++)
      for (int j=i+1; j<n; j++)
        if (U::ispred(a[j],a[i]))
          { T b = a[i]; a[i] = a[j]; a[j] = b; }
  }
  