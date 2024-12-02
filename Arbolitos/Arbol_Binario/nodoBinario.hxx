#include "nodoBinario.h"
#include <iostream>
#include <vector>
using namespace std;

template <class T>
bool NodoBinario<T>::encontrarRuta(T valorBuscado, vector<NodoBinario<T>*>& ruta) {
    // Agregar el nodo actual al vector de ruta
    ruta.push_back(this);

    // Si encontramos el valor, retornamos verdadero
    if (this->dato == valorBuscado) {
        return true;
    }

    // Recorrer el hijo izquierdo para encontrar el valor
    if (this->hijoIzq && this->hijoIzq->encontrarRuta(valorBuscado, ruta)) {
        return true;
    }

    // Recorrer el hijo derecho para encontrar el valor
    if (this->hijoDer && this->hijoDer->encontrarRuta(valorBuscado, ruta)) {
        return true;
    }

    // Si no se encontró el valor, quitar el nodo del vector de ruta
    ruta.pop_back();
    return false;
}

template <class T>
void NodoBinario<T>::posOrden()
{
    if(this->hijoIzq != nullptr)
    {
        (this->hijoIzq)->posOrden();
    }
    if(this->hijoDer == nullptr)
    {
        (this->hijoDer)->posOrden();
    }
    cout<< this->dato << " ";
}
template <class T>
void NodoBinario<T>::preOrden()
{
    cout<< this->dato << " ";
    if(this->hijoIzq != nullptr)
    {
        (this->hijoIzq)->preOrden();
    }

    if(this->hijoDer == nullptr){
        (this->hijoDer)->preOrden();
    }

}

template <class T>
void NodoBinario<T>::inOrden()
{
    if(this->hijoIzq != nullptr)
    {
        (this->hijoIzq)->inOrden();
    }
        cout<< this->dato << " ";
    if(this->hijoDer == nullptr){
        (this->hijoDer)->inOrden();
    }

}

template <class T>
bool NodoBinario<T>::esHoja()
{
    return (this->hijoDer==nullptr && this->hijoIzq==nullptr);
}

template <class T>
int NodoBinario<T>::contarHojas() {
    // Si el nodo no tiene hijos, es una hoja
    if (this->esHoja()) {
        return 1;
    }

    int hojasIzq = 0;
    int hojasDer = 0;

    // Contar hojas en el subárbol izquierdo
    if (hijoIzq != nullptr) {
        hojasIzq = hijoIzq->contarHojas();
    }

    // Contar hojas en el subárbol derecho
    if (hijoDer != nullptr) {
        hojasDer = hijoDer->contarHojas();
    }

    // Retornar la suma de hojas en ambos subárboles
    return hojasIzq + hojasDer;
}

template <class T>
int NodoBinario<T>::altura()
{
    int alt;
    if(this->esHoja())
    {
        alt = 0;
    }else
    {
        int alti, altd = -1;
        if(this->hijoIzq != nullptr)
        {
            alti = (this->hijoIzq)->altura();
        }
        if(this->hijoDer != nullptr)
        {
            altd = (this->hijoDer)->altura();
        }
        if(alti > altd)
        {
            alt = alti + 1;
        }else
        {
            alt = altd + 1;
        }
    }

    return alt;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::nodoConAlturaMasBaja()
{
    if(this->esHoja()) {
        return this;
    } else {
        NodoBinario<T>* nodoMinAltura = this;
        int alti = -1, altd = -1;

        // Verificar el hijo izquierdo
        if(this->hijoIzq != nullptr) {
            NodoBinario<T>* nodoIzq = (this->hijoIzq)->nodoConAlturaMasBaja();
            alti = (this->hijoIzq)->altura();
            nodoMinAltura = nodoIzq; // Inicialmente considerar nodo izquierdo
        }

        // Verificar el hijo derecho
        if(this->hijoDer != nullptr) {
            NodoBinario<T>* nodoDer = (this->hijoDer)->nodoConAlturaMasBaja();
            altd = (this->hijoDer)->altura();
            if(altd < alti || alti == -1) { // Comparar si altd es más bajo o alti no fue inicializado
                nodoMinAltura = nodoDer;
            }
        }

        return nodoMinAltura;
    }
}

template <class T>
int NodoBinario<T>::tamano() {
    int tamanoIzq = 0;
    int tamanoDer = 0;

    // Si el nodo tiene hijo izquierdo, calcular el tamaño del subárbol izquierdo
    if (hijoIzq != nullptr) {
        tamanoIzq = hijoIzq->tamano();
    }

    // Si el nodo tiene hijo derecho, calcular el tamaño del subárbol derecho
    if (hijoDer != nullptr) {
        tamanoDer = hijoDer->tamano();
    }

    // El tamaño total es 1 (el nodo actual) más el tamaño de los subárboles izquierdo y derecho
    return 1 + tamanoIzq + tamanoDer;
}

template <class T>
int NodoBinario<T>::tamanoCondicion(T umbral) {
    int tamanoIzq = 0;
    int tamanoDer = 0;

    // Si el nodo tiene hijo izquierdo, calcular el tamaño del subárbol izquierdo bajo la condición
    if (hijoIzq != nullptr) {
        tamanoIzq = hijoIzq->tamanoCondicion(umbral);
    }

    // Si el nodo tiene hijo derecho, calcular el tamaño del subárbol derecho bajo la condición
    if (hijoDer != nullptr) {
        tamanoDer = hijoDer->tamanoCondicion(umbral);
    }

    // Contar el nodo actual solo si cumple con la condición
    int cumpleCondicion = (this->dato > umbral) ? 1 : 0;

    // El tamaño total será la suma del nodo actual (si cumple la condición) y los subárboles
    return cumpleCondicion + tamanoIzq + tamanoDer;
}

template <class T>
T& NodoBinario<T>::obtenerDato(){
    return this->dato;
}

template <class T>
void NodoBinario<T>::fijarDato(T& val){
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