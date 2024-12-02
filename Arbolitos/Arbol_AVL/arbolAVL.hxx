#include "arbolAVL.h"
#include <iostream>
#include <queue>

using namespace std;

template <class T>
ArbolAVL<T>::ArbolAVL(){
  this->raiz = NULL;
}

template <class T>
ArbolAVL<T>::~ArbolAVL(){
  if(this->raiz != NULL){
    delete this->raiz;
    this->raiz = NULL;
  }
}

template <class T>
bool ArbolAVL<T>::esVacio(){
  return this->raiz == NULL;
}

template <class T>
NodoBinario <T>* ArbolAVL<T>::obtenerRaiz(){
  return this->raiz;
}

template <class T>
int ArbolAVL<T>::altura(){
  if(this->esVacio()){
    return -1;
  }
  else{
    return (this->raiz)->altura();
  }
}

template <class T>
int ArbolAVL<T>::tamano(){
  if(this->esVacio()){
    return 0;
  }
  else{
    return (this->raiz)->tamano();
  }
}

template <class T>
bool ArbolAVL<T>::insertar(T val) {
  bool insertado = false;
  this->raiz = insertarRec(this->raiz, val, insertado);
  return insertado;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::insertarRec(NodoBinario<T>* nodo, T val, bool& insertado) {
  if (nodo == NULL) {
    insertado = true;
    return new NodoBinario<T>(val);
  }

  if (val < nodo->obtenerDato()) {
    nodo->fijarHijoIzq(insertarRec(nodo->obtenerHijoIzq(), val, insertado));
  } else if (val > nodo->obtenerDato()) {
    nodo->fijarHijoDer(insertarRec(nodo->obtenerHijoDer(), val, insertado));
  } else {
    insertado = false;
    return nodo;
  }
  return balancear(nodo);
}

template <class T>
bool ArbolAVL<T>::eliminar(T val) {
  bool eliminado = false;
  this->raiz = eliminarRec(this->raiz, val, eliminado);
  return eliminado;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::eliminarRec(NodoBinario<T>* nodo, T val, bool& eliminado) {
  if (nodo == NULL) {
    eliminado = false;
    return nodo;
  }

  if (val < nodo->obtenerDato()) {
    nodo->fijarHijoIzq(eliminarRec(nodo->obtenerHijoIzq(), val, eliminado));
  } else if (val > nodo->obtenerDato()) {
    nodo->fijarHijoDer(eliminarRec(nodo->obtenerHijoDer(), val, eliminado));
  } else {
    eliminado = true;
    NodoBinario<T>* aux;
    
    if(nodo->esHoja()){
      delete nodo;
      return NULL;
    }else if(nodo->obtenerHijoDer() == NULL){
      aux = nodo->obtenerHijoIzq();
      delete nodo;
      return aux;
    }else if(nodo->obtenerHijoIzq() == NULL){
      aux = nodo->obtenerHijoDer();
      delete nodo;
      return aux;
    }else{
      aux = nodo->obtenerHijoIzq();
      while(aux->obtenerHijoDer()!=NULL){
        aux=aux->obtenerHijoDer();
      }
      nodo->fijarDato(aux->obtenerDato());
      nodo->fijarHijoIzq(eliminarRec(nodo->obtenerHijoIzq(), aux->obtenerDato(), eliminado));
    }
  }
  return balancear(nodo);
}

template <class T>
bool ArbolAVL<T>::buscar(T val){
  NodoBinario<T>* nodo = this->raiz;
  bool encontrado = false;
  while(nodo!=NULL && !encontrado){
    if(val < nodo->obtenerDato()){
      nodo = nodo->obtenerHijoIzq();
    } else if(val > nodo->obtenerDato()){
      nodo = nodo->obtenerHijoDer();
    } else{
      encontrado = true;
    }
  }
  return encontrado;
}

template <class T>
void ArbolAVL<T>::inOrden(){
  if(!this->esVacio()){
    (this->raiz)->inOrden();
  }
}

template <class T>
void ArbolAVL<T>::preOrden(){
  if(!this->esVacio()){
    (this->raiz)->preOrden();
  }
}

template <class T>
void ArbolAVL<T>::posOrden(){
  if(!this->esVacio()){
    (this->raiz)->posOrden();
  }
}

template <class T>
void ArbolAVL<T>::nivelOrden(){
  if(!this->esVacio()){
    queue<NodoBinario<T>*> cola;
    cola.push(this->raiz);
    NodoBinario<T>* nodo;
    while(!cola.empty()){
      nodo = cola.front();
      cola.pop();
      cout<< nodo->obtenerDato()<<" ";
      if(nodo->obtenerHijoIzq() != NULL)
        cola.push(nodo->obtenerHijoIzq());
      if(nodo->obtenerHijoDer() != NULL)
        cola.push(nodo->obtenerHijoDer());
    }
  }
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::balancear(NodoBinario<T>* nodo) {

  int balance = nodo->factorBalance();
  
  if (balance > 1 && nodo->obtenerHijoIzq()->factorBalance() >= 0) {
    return nodo->rotacionDer();
  }

  if (balance > 1 && nodo->obtenerHijoIzq()->factorBalance() < 0) {
    return nodo->rotacionIzqDer();
  }

  if (balance < -1 && nodo->obtenerHijoDer()->factorBalance() <= 0) {
    return nodo->rotacionIzq();
  }

  if (balance < -1 && nodo->obtenerHijoDer()->factorBalance() > 0) {
    return nodo->rotacionDerIzq();
  }

  return nodo;
}
