#ifndef __ARBOLAVL_H__
#define __ARBOLAVL_H__

#include "nodoBinario.h"

template <class T>
class ArbolAVL {
  public:
  NodoBinario<T> *raiz;

  ArbolAVL();
  ~ArbolAVL();
  bool esVacio();
  NodoBinario<T> *obtenerRaiz();
  int altura();
  int tamano();
  bool insertar(T val);
  NodoBinario<T>* insertarRec(NodoBinario<T>* nodo, T val, bool& insertado);
  bool eliminar(T val);
  NodoBinario<T>* eliminarRec(NodoBinario<T>* nodo, T val, bool& eliminado);
  bool buscar(T val);
  void inOrden();
  void preOrden();
  void posOrden();
  void nivelOrden();
  NodoBinario<T>* balancear(NodoBinario<T>* nodo);
};

#include "arbolAVL.hxx"

#endif
