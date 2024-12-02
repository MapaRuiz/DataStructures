#include "arbolGeneral.h"
#include <queue>
#include <list>
#include <iostream>

using namespace std;

template <class T>
int ArbolGeneral<T>::calcularDistanciaEntreNodos(T ser1, T ser2) {
    vector<NodoGeneral<T>*> ruta1, ruta2;

    // Buscar las rutas desde la raíz hasta los dos nodos
    bool encontrado1 = (this->raiz)->encontrarRuta(ser1, ruta1);
    bool encontrado2 = (this->raiz)->encontrarRuta(ser2, ruta2);

    if (!encontrado1 || !encontrado2) {
        cout << "No se encontraron ambos seres en el árbol." << endl;
        return -1; // Alguno de los dos nodos no se encontró
    }

    // Encontrar el índice del último ancestro común en las rutas
    size_t indiceAncestroComun = 0;
    while (indiceAncestroComun < ruta1.size() && indiceAncestroComun < ruta2.size() && ruta1[indiceAncestroComun] == ruta2[indiceAncestroComun]) {
        ++indiceAncestroComun;
    }

    // Calcular las distancias
    int distancia1 = ruta1.size() - 1; // Número de saltos desde la raíz hasta ser1
    int distancia2 = ruta2.size() - 1; // Número de saltos desde la raíz hasta ser2

    // Restar la parte común para obtener la distancia
    int distanciaTotal = (distancia1 - indiceAncestroComun) + (distancia2 - indiceAncestroComun);

    return distanciaTotal;
}

template <class T>
ArbolGeneral<T>::ArbolGeneral(){
    this->raiz = nullptr;
}

template <class T>
ArbolGeneral<T>::ArbolGeneral(T val){
    NodoGeneral<T>* nodo = new NodoGeneral<T>(val);
    this->raiz = nodo;
}

template <class T>
ArbolGeneral<T>::~ArbolGeneral(){
    delete this->raiz;
    this->raiz = nullptr;
}

template <class T>
bool ArbolGeneral<T>::esVacio(){
    return this->raiz == nullptr;
}

template <class T>
NodoGeneral <T>* ArbolGeneral<T>::obtenerRaiz(){
    return this->raiz;
}

template <class T>
void ArbolGeneral<T>::fijarRaiz(NodoGeneral<T> * nraiz){
    this->raiz = nraiz;
}

template <class T>
bool ArbolGeneral<T>::insertarNodo(T padre, T n){
    if(this->esVacio())
    {
        NodoGeneral<T>* nodo = new NodoGeneral<T>(n);
        this->raiz = nodo;
    }else
    {
        return (this->raiz)->insertarNodo(padre, n);
    }

}

template <class T>
bool ArbolGeneral<T>::eliminarNodo(T n){
    if(this->esVacio())
    {
        return false;
    }else if(this->raiz.obtenerDato() == n){
        delete(this->raiz);
    }
    else{
        return (this->raiz)->eliminarNodo(n);
    }
}

template <class T>
bool ArbolGeneral<T>::buscar (T n){
    if(this->esVacio())
    {
        return false;
    }else if(this->raiz.obtenerDato() == n){
        return true;
    }else
    {
        return (this->raiz)->buscar(n);
    }
}

template <class T>
int ArbolGeneral<T>::altura(){
    if(this->esVacio())
    {
        return -1;
    } else
    {
        return (this->raiz)->altura();
    }
}

template <class T>
int ArbolGeneral<T>::tamano(){
    if(this->esVacio())
    {
        return 0;
    }else
    {
        return (this->raiz)->tamano();
    }
}

template <class T>
void ArbolGeneral<T>::preOrden(){
    if(!this->esVacio())
    {
        (this->raiz)->preOrden();
    }
}

template <class T>
void ArbolGeneral<T>::posOrden(){
    if(!this->esVacio())
    {
        (this->raiz)->posOrden();
    }
}

template <class T>
void ArbolGeneral<T>::nivelOrden(){
  queue<NodoGeneral<T>*> q;
  NodoGeneral<T>* a = new NodoGeneral<T>;
  q.push(this->raiz);
  while(!q.empty()){
     a = q.front();
     cout << a->obtenerDato() <<" "<< endl;
     q.pop();
     list<NodoGeneral<T>*>::iterator it = a->desc.begin();
     while(it != a->desc.end())
     {
         q.push((*it));
         it++;
     }
  }
}

template <class T>
void ArbolGeneral<T>::nivelConMasNodos()
{
    if (this->raiz == nullptr) return;  // Si no hay raíz, salimos

    std::queue<NodoGeneral<T>*> q;  // Cola para procesar los nodos por niveles
    q.push(this->raiz);  // Insertamos la raíz en la cola

    int nivelActual = 0;     // Nivel actual
    int maxNodos = 0;        // Máximo número de nodos en un nivel
    int nivelMaximo = 0;     // Nivel con el máximo número de nodos

    while (!q.empty())
    {
        int nodosEnEsteNivel = q.size();  // Número de nodos en el nivel actual

        // Comparar cuántos nodos tiene este nivel con el máximo encontrado
        if (nodosEnEsteNivel > maxNodos)
        {
            maxNodos = nodosEnEsteNivel;
            nivelMaximo = nivelActual;
        }

        // Procesar todos los nodos del nivel actual
        for (int i = 0; i < nodosEnEsteNivel; i++)
        {
            NodoGeneral<T>* a = q.front();
            q.pop();

            // Añadir los hijos del nodo actual a la cola (para el siguiente nivel)
            typename std::list<NodoGeneral<T>*>::iterator it = a->desc.begin();
            while (it != a->desc.end())
            {
                q.push(*it);
                it++;
            }
        }

        nivelActual++;  // Avanzamos al siguiente nivel
    }

    // Mostrar el nivel con más nodos
    std::cout << "El nivel con más nodos es: " << nivelMaximo << " con " << maxNodos << " nodos." << std::endl;
}