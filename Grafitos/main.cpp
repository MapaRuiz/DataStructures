#include <iostream>
#include "Grafo.h"
using namespace std;

int main() {
    // Crear un grafo con vértices de tipo char y pesos de tipo int
    Grafo<char, int> grafo;

    // Probar agregar vértices
    std::cout << "Agregando vértices A, B, C...\n";
    grafo.agregarVertice('A');
    grafo.agregarVertice('B');
    grafo.agregarVertice('C');
    grafo.agregarVertice('D');
    grafo.agregarVertice('E');
    grafo.agregarVertice('F');
    grafo.agregarVertice('G');
    grafo.agregarVertice('H');
    grafo.agregarVertice('I');
    grafo.mostrarMatriz();

    // Probar cantidad de vértices
    std::cout << "Cantidad de vértices: " << grafo.cantidadVertices() << "\n";

    // Probar agregar aristas
    std::cout << "Agregando aristas...\n";
    grafo.agregarArista('A', 'I', 1);
    grafo.agregarArista('A', 'E', 1);
    grafo.agregarArista('B', 'G', 1);
    grafo.agregarArista('B', 'D', 1);
    grafo.agregarArista('C', 'A', 1);
    grafo.agregarArista('C', 'I', 1);
    grafo.agregarArista('D', 'H', 1);
    grafo.agregarArista('D', 'G', 1);
    grafo.agregarArista('D', 'E', 1);
    grafo.agregarArista('E', 'I', 1);
    grafo.agregarArista('E', 'F', 1);
    grafo.agregarArista('F', 'C', 1);
    grafo.agregarArista('F', 'B', 1);
    grafo.agregarArista('G', 'F', 1);
    grafo.agregarArista('G', 'E', 1);
    grafo.agregarArista('H', 'B', 1);
    grafo.agregarArista('I', 'F', 1);
    grafo.mostrarMatriz();

    // Probar cantidad de aristas
    std::cout << "Cantidad de aristas: " << grafo.cantidadAristas() << "\n";

    // Probar buscar vértice
    std::cout << "Buscando vértice 'A': " << (grafo.buscarVertice('A') ? "Encontrado" : "No encontrado") << "\n";
    std::cout << "Buscando vértice 'J': " << (grafo.buscarVertice('J') ? "Encontrado" : "No encontrado") << "\n";

    // Probar buscar arista
    std::cout << "Buscando arista entre A y B: " << (grafo.buscarArista('A', 'B') ? "Existe" : "No existe") << "\n";
    std::cout << "Buscando arista entre A y I: " << (grafo.buscarArista('A', 'I') ? "Existe" : "No existe") << "\n";

    // Probar peso de arista
    std::cout << "Peso de la arista entre B y D: " << grafo.pesoArista('B', 'D') << "\n";

    /*
    // Probar eliminar arista
    std::cout << "Eliminando arista entre B y C...\n";
    grafo.eliminarArista('B', 'C');
    grafo.mostrarMatriz();

    // Probar eliminar vértice
    std::cout << "Eliminando vértice 'B'...\n";
    grafo.eliminarVertice('B');
    grafo.mostrarMatriz();

*/
    // Probar recorrido plano
    std::cout << "Recorrido plano de los vértices:\n";
    grafo.recorridoPlano();

    // Probar recorrido DFS
    std::cout << "Recorrido DFS (PROFUNDIDAD) desde el vértice 'H':\n";
    grafo.recorridoDFS('H');

    // Probar recorrido BFS
    std::cout << "Recorrido BFS (ANCHURA) desde el vértice 'D':\n";
    grafo.recorridoBFS('D');

    /*
    // Agregar más vértices y aristas para probar recorridos
    std::cout << "\nAgregando vértices D, E y aristas adicionales...\n";

    grafo.agregarVertice('D');
    grafo.agregarVertice('E');

    grafo.agregarArista('A', 'D', 2);
    grafo.agregarArista('D', 'E', 4);
    grafo.agregarArista('E', 'A', 6);
    grafo.mostrarMatriz();

    // Recorridos con los nuevos vértices
    std::cout << "Recorrido DFS desde 'A' con nuevos vértices:\n";
    grafo.recorridoDFS('A');
    std::cout << "Recorrido BFS desde 'A' con nuevos vértices:\n";
    grafo.recorridoBFS('A');
*/
    return 0;
}
