#include "Grafo.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

template <typename T, typename U>
Grafo<T,U>::Grafo() : aristas(nullptr) {}

template <typename T, typename U>
Grafo<T,U>::~Grafo() { liberarMatriz();}

template <typename T, typename U>
void Grafo<T,U>::liberarMatriz() {
    if (aristas) {
        for (int i = 0; i < vertices.size(); ++i) {
            delete[] aristas[i];
        }
        delete[] aristas;
        aristas = nullptr;
    }
}

template <typename T, typename U>
int Grafo<T,U>::cantidadVertices() const {
    return vertices.size();
}

template <typename T, typename U>
int Grafo<T,U>::cantidadAristas() const {
    int conteo = 0;
    for (int i = 0; i < cantidadVertices(); ++i) {
        for (int j = 0; j < cantidadVertices(); ++j) {
            if (aristas[i][j] != U()) {
                conteo++;
            }
        }
    }
    return conteo;
}

template <typename T, typename U>
void Grafo<T,U>::agregarVertice(const T& vert) {
    if (indiceVertice(vert) == -1) {
        vertices.push_back(vert);
        int n = vertices.size();

        // Crear una nueva matriz de tamaño (n) x (n)
        U** nmatriz = new U*[n];
        for (int i = 0; i < n; i++) {
            nmatriz[i] = new U[n];
            for (int j = 0; j < n; j++) {
                if (i < n - 1 && j < n - 1 && aristas != nullptr) {
                    nmatriz[i][j] = aristas[i][j];  // Copiar los valores de la antigua matriz a la nueva
                } else {
                    nmatriz[i][j] = U();  // Inicializar los nuevos valores con el valor predeterminado
                }
            }
        }

        // Asignar la nueva matriz a la variable aristas
        aristas = nmatriz;
    }
}


template <typename T, typename U>
void Grafo<T,U>::agregarArista(const T& origen, const T& destino, U peso) {
    int i = indiceVertice(origen);
    int j = indiceVertice(destino);
    if (i != -1 && j != -1) {
        aristas[i][j] = peso;
        //aristas[j][i] = peso; // si es no dirigido descomentar
    }
}

template <typename T, typename U>
bool Grafo<T,U>::buscarVertice(const T& vertice) const {
    bool encontrado = false;
    for (int i = 0; i < vertices.size(); ++i) {
        if (vertices[i] == vertice) {
            encontrado = true;
            break;
        }
    }
    return encontrado;
}

template <typename T, typename U>
int Grafo<T,U>::indiceVertice(const T& vertice) const {
    for (int i = 0; i < vertices.size(); ++i) {
        if (vertices[i] == vertice) {
            return i;
        }
    }
    return -1;
}

template <typename T, typename U>
bool Grafo<T,U>::buscarArista(const T& origen, const T& destino) const {
    int i = indiceVertice(origen);
    int j = indiceVertice(destino);
    return (i != -1 && j != -1 && aristas[i][j] != U());
    //return (i != -1 && j != -1 && (aristas[i][j] != U() || aristas[j][i] != U()));
    //descomentar si es no dirigido
}

template <typename T, typename U>
U Grafo<T,U>::pesoArista(const T& origen, const T& destino) const {
    int i = indiceVertice(origen);
    int j = indiceVertice(destino);
    return (i != -1 && j != -1) ? aristas[i][j] : U();
}

template <typename T, typename U>
void Grafo<T,U>::eliminarVertice(const T& vertice) {
    int index = indiceVertice(vertice);
    if (index == -1) {
        std::cout << "Vértice no encontrado." << std::endl;
        return;
    }

    // Eliminamos el vértice de la lista de vértices.
    vertices.erase(vertices.begin() + index);

    // Creamos una nueva matriz con un tamaño reducido.
    U** nuevaMatriz = new U*[vertices.size()];
    for (int i = 0; i < vertices.size(); ++i) {
        nuevaMatriz[i] = new U[vertices.size()];
    }

    // Copiamos los datos de la antigua matriz a la nueva, omitiendo la fila y columna del vértice eliminado.
    for (int i = 0, new_i = 0; i < vertices.size() + 1; ++i) {
        if (i == index) continue; // Saltar la fila del vértice eliminado.

        for (int j = 0, new_j = 0; j < vertices.size() + 1; ++j) {
            if (j == index) continue; // Saltar la columna del vértice eliminado.

            nuevaMatriz[new_i][new_j] = aristas[i][j];
            new_j++;
        }
        new_i++;
    }

    // Liberamos la antigua matriz de adyacencia.
    liberarMatriz();

    // Asignamos la nueva matriz.
    aristas = nuevaMatriz;
}

template <typename T, typename U>
void Grafo<T,U>::eliminarArista(const T& origen, const T& destino) {
    int i = indiceVertice(origen);
    int j = indiceVertice(destino);
    if (i != -1 && j != -1) {
        aristas[i][j] = U();
        //aristas[j][i] = U(); //Si es no dirigido, descomentar
    }
}

template <typename T, typename U>
void Grafo<T,U>::recorridoPlano() const {
    for (typename std::vector<T>::const_iterator it = vertices.begin(); it != vertices.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T, typename U>
void Grafo<T,U>::recorridoDFS(const T& inicio) const {
    std::stack<int> pila;
    std::vector<bool> visitados(cantidadVertices(), false);
    int idxInicio = indiceVertice(inicio);

    if (idxInicio == -1) return;

    pila.push(idxInicio);
    while (!pila.empty()) {
        int idx = pila.top();
        pila.pop();
        if (!visitados[idx]) {
            std::cout << vertices[idx] << " ";
            visitados[idx] = true;
            for (int j = cantidadVertices() - 1; j >= 0; --j) {
                if (aristas[idx][j] != U() && !visitados[j]) {
                    pila.push(j);
                }
            }
        }
    }
    std::cout << std::endl;
}

template <typename T, typename U>
void Grafo<T,U>::recorridoBFS(const T& inicio) const {
    std::queue<int> cola;
    std::vector<bool> visitados(cantidadVertices(), false);
    int idxInicio = indiceVertice(inicio);

    if (idxInicio == -1) return;

    cola.push(idxInicio);
    visitados[idxInicio] = true;

    while (!cola.empty()) {
        int idx = cola.front();
        cola.pop();
        std::cout << vertices[idx] << " ";
        for (int j = 0; j < cantidadVertices(); ++j) {
            if (aristas[idx][j] != U() && !visitados[j]) {
                visitados[j] = true;
                cola.push(j);
            }
        }
    }
    std::cout << std::endl;
}

template <typename T, typename U>
void Grafo<T,U>::mostrarMatriz() const {
    std::cout << "   ";
    for (typename std::vector<T>::const_iterator it = vertices.begin(); it != vertices.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < cantidadVertices(); ++i) {
        std::cout << vertices[i] << " ";
        for (int j = 0; j < cantidadVertices(); ++j) {
            std::cout << (aristas[i][j] == U() ? 0 : aristas[i][j]) << " ";
        }
        std::cout << std::endl;
    }
}
