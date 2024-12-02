#ifndef __ARBOLGENERAL_H__
#define __ARBOLGENERAL_H__

#include "nodoGeneral.h"

template <class T>
class ArbolGeneral
{
  NodoGeneral<T> * raiz;

  ArbolGeneral();
  ArbolGeneral(T val);
  ~ArbolGeneral();
  bool esVacio();
  NodoGeneral <T>* obtenerRaiz();
  void fijarRaiz(NodoGeneral<T> * nraiz);
  bool insertarNodo(T padre, T n);
  bool eliminarNodo(T n);
  bool buscar (T n);
  int altura();
  int tamano();
  void preOrden();
  void posOrden();
  void nivelOrden();
  void nivelConMasNodos();
  int calcularDistanciaEntreNodos(T ser1, T ser2);
};

#include "arbolGeneral.hxx"

#endif

