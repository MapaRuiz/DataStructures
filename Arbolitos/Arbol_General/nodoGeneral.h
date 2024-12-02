#ifndef __NODOGENERAL_H__
#define __NODOGENERAL_H__

#include <list>

using namespace std;

template <class T>
class NodoGeneral {

  T dato;
  list< NodoGeneral<T> *> desc;
  
  NodoGeneral();
  ~NodoGeneral();
  T& obtenerDato();
  void fijarDato(T& val);
  void limpiarLista();
  void adicionarDesc(T& nval);
  bool eliminarDesc(T& val);
  bool esHoja();
  int contarHojas();
  int altura();
  NodoGeneral<T>* nodoConMenorAltura();
  void preOrden();
  void posOrden();
  bool insertarNodo(T padre, T n);
  bool insertarCond(T n, T umbral);
  bool eliminarNodo(T n);
  bool buscar (T n);
  int tamano();
  int tamanoCondicion(T umbral);
  bool encontrarRuta( T valorBuscado, std::vector<NodoGeneral<T>*>& ruta);
};

#include "nodoGeneral.hxx"

#endif