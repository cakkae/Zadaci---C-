// fuzija.h - Genericka funkcija za fuziju nizova objekata.

template <typename T>
  void fuzija (const T a[], int na, const T b[], int nb, T c[], int &nc) {
    nc = 0;
    for (int ia=0, ib=0; ia<na || ib<nb; nc++)
      c[nc] = ia==na      ? b[ib++] :
              ib==nb      ? a[ia++] :
              a[ia]<b[ib] ? a[ia++] : b[ib++];
  }
