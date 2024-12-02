#ifndef __NODOBINARIO_H__
#define __NODOBINARIO_H__

#include <list>

using namespace std;

template <class T>
class NodoBinario {
  public:
  T dato;
  NodoBinario<T> *hijoIzq;
  NodoBinario<T> *hijoDer;

  NodoBinario();
  NodoBinario(T val);
  ~NodoBinario();
  T obtenerDato();
  void fijarDato(T val);
  NodoBinario<T> *obtenerHijoIzq();
  NodoBinario<T> *obtenerHijoDer();
  void fijarHijoIzq(NodoBinario<T> *izq);
  void fijarHijoDer(NodoBinario<T> *der);
  bool esHoja();
  int altura();
  void inOrden();
  void preOrden();
  void posOrden();
  int tamano();
  int factorBalance();
  NodoBinario<T>* rotacionDer();
  NodoBinario<T>* rotacionIzq();
  NodoBinario<T>* rotacionDerIzq();
  NodoBinario<T>* rotacionIzqDer();
};

#include "nodoBinario.hxx"

#endif
