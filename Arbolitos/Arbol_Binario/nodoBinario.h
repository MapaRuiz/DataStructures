#ifndef __NODOBINARIO_H__
#define __NODOBINARIO_H__

using namespace std;
#include <vector>

template <class T>
class NodoBinario {
  public:
  T dato;
  NodoBinario<T> *hijoIzq;
  NodoBinario<T> *hijoDer;

  T& obtenerDato();
  void fijarDato(T& val);
  NodoBinario<T> *obtenerHijoIzq();
  NodoBinario<T> *obtenerHijoDer();
  void fijarHijoIzq(NodoBinario<T> *izq);
  void fijarHijoDer(NodoBinario<T> *der);
  int altura();
  NodoBinario<T>* nodoConAlturaMasBaja();
  bool esHoja();
  int contarHojas();
  int tamano();
  int tamanoCondicion(T umbral);
  void inOrden();
  void preOrden();
  void posOrden();
  bool encontrarRuta(T valorBuscado, vector<NodoBinario<T>*>& ruta);
};

#include "nodoBinario.hxx"

#endif

