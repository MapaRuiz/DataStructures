#ifndef __ARBOLBINARIOORD_H__
#define __ARBOLBINARIOORD_H__

#include "nodoBinario.h"

template <class T>
class ArbolBinarioOrd {
  public:
  NodoBinario<T> *raiz;

  ArbolBinarioOrd();
  ~ArbolBinarioOrd();
  bool esVacio();
  T& datoRaiz();
  int altura();
  int tamano();
  bool insertar(T& val);
  bool insertarCond(T& val);
  bool eliminar(T val);
  bool buscar(T& val);
  void preOrden();
  void inOrden();
  void posOrden();
  void nivelOrden();
  int nivelConMasNodos();
  int nivelConMasNodosQueCumplanUmbral(T umbral);
  int calcularDistanciaEntreNodos(T ser1, T ser2);
};
#include "arbolBinarioOrd.hxx"

#endif

