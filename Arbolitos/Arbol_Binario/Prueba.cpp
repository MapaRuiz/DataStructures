#include "arbolBinarioOrd.h"
#include <iostream>

using namespace std;

int main() {
  int op = -1;
  ArbolBinarioOrd<int> arbol;

  while (op != 0) {
    cout << "Ingrese la opcion que desee: " << endl;
    cout << "1. Agregar un nodo." << endl;
    cout << "2. Eliminar un nodo." << endl;
    cout << "3. Buscar un nodo." << endl;
    cout << "4. Altura del arbol." << endl;
    cout << "5. Tamano del arbol." << endl;
    cout << "6. Raiz del arbol." << endl;
    cout << "7. Realizar inorden." << endl;
    cout << "8. Realizar preorden." << endl;
    cout << "9. Realizar posorden." << endl;
    cout << "10. Realizar nivelorden." << endl;
    cout << "11. El arbol es vacio?." << endl;
    cout << "0. Salir." << endl;
    cin >> op;

    int val;
    switch (op) {
    case 1: // Agregar un nodo
      cout << "Ingrese el valor a insertar: ";
      cin >> val;
      if (arbol.insertar(val)) {
        cout << "Nodo insertado correctamente." << endl;
      } else {
        cout << "El nodo ya existe." << endl;
      }
      break;

    case 2: // Eliminar un nodo
      cout << "Ingrese el valor a eliminar: ";
      cin >> val;
      if (arbol.eliminar(val)) {
        cout << "Nodo eliminado correctamente." << endl;
      } else {
        cout << "El nodo no fue encontrado." << endl;
      }
      break;

    case 3: // Buscar un nodo
      cout << "Ingrese el valor a buscar: ";
      cin >> val;
      if (arbol.buscar(val)) {
        cout << "El valor " << val << " fue encontrado en el arbol." << endl;
      } else {
        cout << "El valor " << val << " no fue encontrado en el arbol." << endl;
      }
      break;

    case 4: // Altura del árbol
      cout << "La altura del arbol es: " << arbol.altura() << endl;
      break;

    case 5: // Tamaño del árbol
      cout << "El tamano del arbol es: " << arbol.tamano() << endl;
      break;

    case 6: // Raíz del árbol
      if (!arbol.esVacio()) {
        cout << "La raiz del arbol es: "
             << endl;
      } else {
        cout << "El arbol está vacio." << endl;
      }
      break;

    case 7: // Recorrido inOrden
      cout << "Recorrido inOrden: ";
      arbol.inOrden();
      cout << endl;
      break;

    case 8: // Recorrido preOrden
      cout << "Recorrido preOrden: ";
      arbol.preOrden();
      cout << endl;
      break;

    case 9: // Recorrido posOrden
      cout << "Recorrido posOrden: ";
      arbol.posOrden();
      cout << endl;
      break;

    case 10: // Recorrido nivelOrden
      cout << "Recorrido nivelOrden: ";
      arbol.nivelOrden();
      cout << endl;
      break;

    case 11: // Verificar si el árbol está vacío
      if (arbol.esVacio()) {
        cout << "El arbol está vacio." << endl;
      } else {
        cout << "El arbol no está vacio." << endl;
      }
      break;
    
    case 0: // Salir
      cout << "Saliendo del programa." << endl;
      break;

    default:
      cout << "Opción inválida. Intente nuevamente." << endl;
      break;
    }
  }

  return 0;
}
