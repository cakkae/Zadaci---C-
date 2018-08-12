// stek1.h - Genericka klasa stekova zadatih kapaciteta.

template <typename Pod, int kap>
  class Stek {
    Pod  stek[kap];                            // Stek u obliku niza.
    int  vrh;                                  // Indeks vrha steka.
  public:
    Stek () { vrh = 0; }                       // Inicijalizacija.
    void stavi (const Pod &pod);               // Smestanje podatka.
    void uzmi (Pod &pod);                      // Uzimanje podatka.
    int  vel () const { return vrh; }          // Broj podataka na steku.
    void brisi () { vrh = 0; }                 // Praznjenje steka.
    bool prazan () const { return vrh == 0; }  // Indikator praznog steka.
    bool pun () const { return vrh == kap; }   // Indikator punog steka.
  };

// Definicije metoda klase Stek<>.

template <typename Pod, int kap>
  void Stek<Pod,kap>::stavi (const Pod &pod) { // Smestanje podatka.
    if (vrh == kap) throw "Stek je pun!";
    stek[vrh++] = pod;
  }

template <typename Pod, int kap>
  void Stek<Pod,kap>::uzmi (Pod &pod) {         // Uzimanje podatka.
    if (vrh == 0) throw "Stek je prazan!";
    pod = stek[--vrh];
  }
