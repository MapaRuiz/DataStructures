#include "nodoBinario.h"
#include <iostream>
using namespace std;

template <class T>
NodoBinario<T>::NodoBinario(){
  this->hijoizq = NULL;
  this->hijoder = NULL;
}

template <class T>
NodoBinario<T>::NodoBinario(T val){
  this->hijoIzq = NULL;
  this->hijoDer = NULL;
  this->dato = val;
}

template <class T>
NodoBinario<T>::~NodoBinario(){
  if(this->hijoIzq != NULL){
    delete this->hijoIzq;
    this->hijoIzq = NULL;
  }
  if(this->hijoDer != NULL){
    delete this->hijoDer;
    this->hijoDer = NULL;
  }
}

template <class T>
T NodoBinario<T>::obtenerDato(){
  return this->dato;
}

template <class T>
void NodoBinario<T>::fijarDato(T val){
  this->dato = val;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq(){
  return this->hijoIzq;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer(){
  return this->hijoDer;
}

template <class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T>* izq){
  this->hijoIzq = izq;
}

template <class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T>* der){
  this->hijoDer = der;
}

template <class T>
bool NodoBinario<T>::esHoja(){
  return (this->hijoIzq==NULL && this->hijoDer==NULL);
}

template <class T>
int NodoBinario<T>::altura(){
  int valt;
  if(this->esHoja()){
    valt=0;
  }else{
    int valt_izq = -1;
    int valt_der = -1;
    if(this->hijoIzq != NULL){
      valt_izq = (this->hijoIzq)->altura();
    }
    if(this->hijoDer != NULL){
      valt_der = (this->hijoDer)->altura();
    }
    if(valt_izq>valt_der){
      valt = valt_izq + 1;
    }else{
      valt = valt_der + 1;
    }
  }
  return valt;
}

template <class T>
void NodoBinario<T>::inOrden(){
  if(this->hijoIzq != NULL)
    (this->hijoIzq)->inOrden();
  cout<< this->dato<<" ";
  if(this->hijoDer != NULL)
    (this->hijoDer)->inOrden();
}

template <class T>
void NodoBinario<T>::preOrden(){
  cout<< this->dato<<" ";
  if(this->hijoIzq != NULL)
    (this->hijoIzq)->preOrden();
  if(this->hijoDer != NULL)
    (this->hijoDer)->preOrden();
}

template <class T>
void NodoBinario<T>::posOrden(){
  if(this->hijoIzq != NULL)
    (this->hijoIzq)->posOrden();
  if(this->hijoDer != NULL)
    (this->hijoDer)->posOrden();
  cout<< this->dato<<" ";
}

template <class T>
int NodoBinario<T>::tamano(){
  int n=0;
  if(this->hijoIzq != NULL)
    n+=(this->hijoIzq)->tamano();
  if(this->hijoDer != NULL)
    n+=(this->hijoDer)->tamano();

  return n+1;
}

template <class T>
int NodoBinario<T>::factorBalance(){
  int valt_izq = -1;
  int valt_der = -1;
  if(this->hijoIzq != NULL){
    valt_izq = (this->hijoIzq)->altura();
  }
  if(this->hijoDer != NULL){
    valt_der = (this->hijoDer)->altura();
  }
  return valt_izq-valt_der;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::rotacionDer(){
  NodoBinario<T>* padre;
  padre = this->hijoIzq;
  this->hijoIzq = (this->hijoIzq)->obtenerHijoDer();
  padre->fijarHijoDer(this);
  return padre;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::rotacionIzq(){
  NodoBinario<T>* padre;
  padre = this->hijoDer;
  this->hijoDer = (this->hijoDer)->obtenerHijoIzq();
  padre->fijarHijoIzq(this);
  return padre;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::rotacionDerIzq(){
  NodoBinario<T>* aux;
  aux = (this->hijoDer)->rotacionDer();
  this->hijoDer = aux;
  return rotacionIzq();
}

template <class T>
NodoBinario<T>* NodoBinario<T>::rotacionIzqDer(){
  NodoBinario<T>* aux;
  aux = (this->hijoIzq)->rotacionIzq();
  this->hijoIzq = aux;
  return rotacionDer();
}
