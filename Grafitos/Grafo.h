#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <vector>

template <typename T, typename U>
class Grafo {
public:
    std::vector<T> vertices;
    U** aristas;

    Grafo();
    ~Grafo();
    void liberarMatriz();
    int cantidadVertices() const;
    int cantidadAristas() const;
    void agregarVertice(const T& vert);
    void agregarArista(const T& origen, const T& destino, U peso);
    bool buscarVertice(const T& vertice) const;
    int indiceVertice(const T& vertice) const;
    bool buscarArista(const T& origen, const T& destino) const;
    U pesoArista(const T& origen, const T& destino) const;
    void eliminarVertice(const T& vertice);
    void eliminarArista(const T& origen, const T& destino);
    void recorridoPlano() const;
    void recorridoDFS(const T& inicio) const;
    void recorridoBFS(const T& inicio) const;
    void mostrarMatriz() const;
};

#include "Grafo.hxx"

#endif
