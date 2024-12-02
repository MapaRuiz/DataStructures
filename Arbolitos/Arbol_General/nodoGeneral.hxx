#include <iostream>
#include <ostream>

#include "nodoGeneral.h"
using namespace std;
/*
template <class T>
bool NodoGeneral<T>::encontrarRuta( T valorBuscado, std::vector<NodoGeneral<T>*>& ruta) {
    // Agregar el nodo actual al vector de ruta
    ruta.push_back(this);

    // Si encontramos el valor, retornamos verdadero
    if (this->dato == valorBuscado) {
        return true;
    }

    // Recorrer los hijos para encontrar el valor
    list<NodoGeneral<T>*>::iterator it = desc.begin();
    for (; it != desc.end(); it++) {
        if ((*it)->encontrarRuta(valorBuscado, ruta)) {
            return true;
        }
    }

    // Si no se encontró el valor, quitar el nodo del vector de ruta
    ruta.pop_back();
    return false;
}
*/
/*
template <class T>
int NodoGeneral<T>::tamano()
{
    if (this == nullptr) {
        return 0; // Árbol vacío o nodo nulo
    }
    int tamano = 1;
    list<nodoGeneral<T> *>::iterator it = this->desc.begin();
    for(; it != desc.end(); it++)
    {
        tamano += (*it)->tamano();
    }
    return tamano;
}
*//*
template <class T>
int NodoGeneral<T>::tamanoCondicion(T umbral)
{
    int tamano = 0;
    if (this == nullptr) {
        return 0; // Árbol vacío o nodo nulo
    }
    if(this->dato > umbral)
    {
        tamano = 1;
    }

    list<nodoGeneral<T> *>::iterator it = this->desc.begin();
    for(; it != desc.end(); it++)
    {
        tamano += (*it)->tamanoCondicion(umbral);
    }
    return tamano;
}*/
/*
template <class T>
bool NodoGeneral<T>::buscar (T n)
{
    bool found = false;
    list<NodoGeneral<T>*> ::iterator it = desc.begin();
    while (it != desc.end()) {
        if ((*it)->obtenerDato() == n) {
            found = true;
            break;
        } else {
            found = (*it)->buscar(n);
            if (found) {
                break;
            }
            ++it;
        }
    }
    return found;
}
*/
/*
template <class T>
bool NodoGeneral<T>::eliminarNodo(T n) {
    bool eliminado = false;
    list<NodoGeneral<T>*> ::iterator it = desc.begin();
    while (it != desc.end()) {
        if ((*it)->obtenerDato() == n) {
            // Eliminamos el nodo encontrado (cuidado con la memoria)
            delete *it;
            desc.erase(it);
            eliminado = true;
            break;
        } else {
            eliminado = (*it)->eliminarNodo(n);
            if (eliminado) {
                break;
            }
            ++it;
        }
    }
    return eliminado;
}
*//*
template <class T>
bool NodoGeneral<T>::insertarNodo(T padre, T n)
{
    bool insertado = false;
    if(this->dato == padre)
    {
        this->adicionarDesc(n);
        insertado = true;
    }else
    {
        list<NodoGeneral<T> *>::iterator it = desc.begin();
        for(; it != desc.end(); it++)
        {
            (*it)->insertarNodo(padre, n);
        }
    }
    return insertado;
}

template <class T>
bool NodoGeneral<T>::insertarCond(T n, T umbral) {
    if (this == nullptr) {
        return false; // No se encontró un nodo que cumpla la condición
    }

    if (this->obtenerDato() > umbral) {
        // Inserta el nuevo nodo como descendiente de este nodo
        this->adicionarDesc(n);
        return true;
    }else
    {
        list<NodoGeneraL<T> *>::iterator it = desc.begin();
        for(; it != desc.end(); it++)
        {
            if(insertarCond(dato, umbral)){
                return true;
            }
        }
    }

    return false; // No se encontró un nodo que cumpla la condición
}
*/
/*
template <class T>
void NodoGeneral<T>::preOrden()
{
    cout<<this->dato<<" ";
    list<NodoGeneral<T> *>::iterator it = desc.begin();
    for(; it!=desc.end(); it++)
    {
        (*it)->preOrden();
    }
}

template <class T>
void NodoGeneral<T>::posOrden()
{
    list<NodoGeneral<T> *>::iterator it = desc.begin();
    for(; it!=desc.end(); it++)
    {
        (*it)->preOrden();
    }
    cout<<this->dato<<" ";
}*/
/*
template <class T>
int NodoGeneral<T>::altura()
{
    int alt = -1;
    if(this->esHoja())
    {
        alt = 0;
    }else
    {
        int alth;
        list<NodoGeneral<T> *>::iterator it = desc.begin();
        for(; it != desc.end(); it++)
        {
            alth = (*it)->altura();
            if(alt < alth +1)
            {
                alt = alth +1;
            }
        }
    }

    return alt;
}
*//*
template <class T>
NodoGeneral<T>* NodoGeneral<T>::nodoConMenorAltura()
{
    NodoGeneral<T> *menorNodo = this; // Inicialmente, el nodo actual es el de menor altura
    int alt = -1;  // Para calcular la altura del nodo actual

    if(this->esHoja())
    {
        alt = 0;  // Si es una hoja, su altura es 0
    }
    else
    {
        int alth;
        list<NodoGeneral<T> *>::iterator it = desc.begin();
        for(; it != desc.end(); it++)
        {
            alth = (*it)->altura();  // Calcula la altura de cada hijo

            if (alt < alth + 1)  // Actualiza la altura del nodo actual
            {
                alt = alth + 1;
            }

            // Ahora revisamos cuál nodo tiene la menor altura
            NodoGeneral<T>* menorHijo = (*it)->nodoConMenorAltura();
            if (menorHijo->altura() < menorNodo->altura())
            {
                menorNodo = menorHijo;  // Actualiza el nodo con la menor altura
            }
        }
    }

    return menorNodo;  // Devuelve el nodo con la menor altura
}*/

/*
template <class T>
bool NodoGeneral<T>::esHoja()
{
    return this->desc.size() == 0;
}
*/
template <class T>
NodoGeneral<T>::NodoGeneral(){
    this->desc.clear();
}
/*
template <class T>
NodoGeneral<T>::~NodoGeneral(){
    list<NodoGeneral<T>*>::iterator it = this->desc.begin();
    for(;it != this->desc.end(); it ++)
    {
        delete (*it);
    }
    this->desc.clear();
}
*/
template <class T>
T& NodoGeneral<T>::obtenerDato(){
    return this->dato;
}

template <class T>
void NodoGeneral<T>::fijarDato(T& val){
    this->dato = val;
}

template <class T>
void NodoGeneral<T>::limpiarLista(){
    this->desc.clear();
}
/*
template <class T>
void NodoGeneral<T>::adicionarDesc(T& nval){
    NodoGeneral<T> *nodo = new NodoGeneral<T>;
    nodo->fijarDato(nval);
    this->desc.push_back(nodo);
}
*//*
template <class T>
bool NodoGeneral<T>::eliminarDesc(T& val){
    list<NodoGeneral<T>>::iterator it = this->desc.begin();
    NodoGeneral<T> *aux;
    bool eliminado = false;
    for(;it != this->desc.end(); it ++)
    {
        aux = *it;
        if(aux->obtenerDato() == val)
        {
            break;
        }
    }
    if(it != this->desc.end())
    {
        delete *it;
        this->desc.erase(it);
        eliminado = true;
    }

    return eliminado;
}
*//*
template <class T>
int NodoGeneral<T>::contarHojas()
{
    // Si el nodo no tiene hijos, es una hoja
    if (this->desc.empty())
    {
        return 1;
    }

    // Si tiene hijos, recorremos cada uno de ellos recursivamente
    int numHojas = 0;
    for (auto it = this->desc.begin(); it != this->desc.end(); ++it)
    {
        numHojas += (*it)->contarHojas();
    }

    return numHojas;  // Devolver el total de hojas
}
*/