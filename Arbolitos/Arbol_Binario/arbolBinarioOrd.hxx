#include <queue>

#include "arbolBinarioOrd.h"

using namespace std;

template <class T>
int ArbolBinarioOrd<T>::calcularDistanciaEntreNodos(T ser1, T ser2) {
    std::vector<NodoBinario<T>*> ruta1, ruta2;

    // Buscar las rutas desde la raíz hasta los dos nodos
    bool encontrado1 = (this->raiz)->encontrarRuta(ser1, ruta1);
    bool encontrado2 = (this->raiz)->encontrarRuta(ser2, ruta2);

    if (!encontrado1 || !encontrado2) {
        std::cout << "No se encontraron ambos seres en el árbol." << std::endl;
        return -1; // Alguno de los dos nodos no se encontró
    }

    // Encontrar el índice del último ancestro común en las rutas
    size_t indiceAncestroComun = 0;
    while (indiceAncestroComun < ruta1.size() && indiceAncestroComun < ruta2.size() &&
           ruta1[indiceAncestroComun] == ruta2[indiceAncestroComun]) {
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
ArbolBinarioOrd<T>::ArbolBinarioOrd()
{
    this->raiz = nullptr;
}

template <class T>
ArbolBinarioOrd<T>::~ArbolBinarioOrd()
{
    if (this->raiz != nullptr)
    {
        delete this->raiz;
        this->raiz = nullptr;
    }
}
/*

template <class T>
bool ArbolBinarioOrd<T>::esVacio(){
    return this->raiz == nullptr;
}*/

template <class T>
T& ArbolBinarioOrd<T>::datoRaiz(){
    return (this->raiz)->obtenerDato();
}
/*
template <class T>
int ArbolBinarioOrd<T>::altura(){
    if(this->esVacio())
    {
        return -1;
    }else
    {
        return (this->raiz)->altura();
    }
}

template <class T>
int ArbolBinarioOrd<T>::tamano(){
    if(this->esVacio())
    {
        return -1;
    }else
    {
        return (this->raiz)->tamano();
    }
}
*//*
template <class T>
bool ArbolBinarioOrd<T>::insertar(T& val) {
    NodoBinario<T>* nodo = this->raiz;
    NodoBinario<T>* padre = this->raiz;
    bool insertado = false;
    bool duplicado = false;

    while(nodo != nullptr)
    {
        padre = nodo;
        if(val < nodo->obtenerDato())
        {
            nodo = nodo->obtenerHijoIzq();
        }else if ( val > nodo->obtenerDato() )
        {
            nodo = nodo->obtenerHijoDer();
        }else
        {
            duplicado = true;
            break;
        }
    }

    if (!duplicado)
    {
        NodoBinario<T>* nuevo = new NodoBinario<T>(val);
        if(nuevo != nullptr)
        {
            if(val < padre->obtenerDato())
            {
                padre->fijarHijoIzq(nuevo);
            }else
            {
                padre->fijarHijoDer(nuevo);
            }
        }
        insertado = true;
    }
    return insertado;
}*//*

template <class T>
bool ArbolBinarioOrd<T>::insertarCond(T& val) {
    // Si el árbol está vacío, inserta el valor en la raíz
    if (this->esVacio()) {
        this->raiz = new NodoBinario<T>(val);
        return true;
    }

    NodoBinario<T>* nodo = this->raiz;
    NodoBinario<T>* padre = nullptr; // Padre será utilizado para insertar
    bool insertado = false;
    bool duplicado = false;

    // Recorrer el árbol para encontrar la posición de inserción
    while (nodo != nullptr) {
        padre = nodo; // Actualizar el nodo padre

        // Verificar si el valor ya está en el árbol (no se permiten duplicados)
        if (val == nodo->obtenerDato()) {
            duplicado = true;
            break;
        }

        // El valor es menor que el nodo actual, seguir por el subárbol izquierdo
        if (val < nodo->obtenerDato()) {
            nodo = nodo->obtenerHijoIzq();
        }
        // El valor es mayor que el nodo actual, seguir por el subárbol derecho
        else if (val > nodo->obtenerDato()) {
            nodo = nodo->obtenerHijoDer();
        }
    }

    // Si el valor ya existe, no insertar
    if (duplicado) {
        cout << "El valor " << val << " ya existe en el árbol." << endl;
        return false;
    }

    // Crear un nuevo nodo con el valor a insertar
    NodoBinario<T>* nuevo = new NodoBinario<T>(val);
    if (nuevo != nullptr) {
        // Insertar el nuevo nodo en el subárbol izquierdo o derecho, dependiendo del valor
        if (val < padre->obtenerDato()) {
            padre->fijarHijoIzq(nuevo);
        } else {
            padre->fijarHijoDer(nuevo);
        }
        insertado = true;
    }

    return insertado;
}
*/
/*
template <class T>
bool ArbolBinarioOrd<T>::eliminar(T val) {
    NodoBinario<T>* nodo = this->raiz;
    NodoBinario<T>* padre = nullptr;  // No necesitamos inicializar a raíz
    bool encontrado = false;

    // Buscar el nodo a eliminar
    while (nodo != nullptr && !encontrado) {
        if (val < nodo->obtenerDato()) {
            padre = nodo;
            nodo = nodo->obtenerHijoIzq();
        } else if (val > nodo->obtenerDato()) {
            padre = nodo;
            nodo = nodo->obtenerHijoDer();
        } else {
            encontrado = true; // Nodo encontrado
        }
    }

    if (encontrado) {
        if (nodo->esHoja()) {
            // Caso 1: El nodo es una hoja
            if (padre->obtenerHijoIzq() == nodo) {
                padre->fijarHijoIzq(nullptr);
            } else {
                padre->fijarHijoDer(nullptr);
            }
        } else if (nodo->obtenerHijoIzq() == nullptr || nodo->obtenerHijoDer() == nullptr) {
            // Caso 2: Nodo con un solo hijo
            NodoBinario<T>* hijo = nullptr;
            if (nodo->obtenerHijoIzq() != nullptr) {
                hijo = nodo->obtenerHijoIzq();
            } else {
                hijo = nodo->obtenerHijoDer();
            }

            if (padre == nullptr) { // Si es la raíz
                this->raiz = hijo;
            } else if (padre->obtenerHijoIzq() == nodo) {
                padre->fijarHijoIzq(hijo);
            } else {
                padre->fijarHijoDer(hijo);
            }
        } else {
            // Caso 3: Nodo con dos hijos
            NodoBinario<T>* predecesor = nodo->obtenerHijoIzq();
            NodoBinario<T>* padrePredecesor = nodo;
            while (predecesor->obtenerHijoDer() != nullptr) {
                padrePredecesor = predecesor;
                predecesor = predecesor->obtenerHijoDer();
            }
            // Reemplazar dato y eliminar el predecesor
            nodo->fijarDato(predecesor->obtenerDato());
            if (padrePredecesor->obtenerHijoDer() == predecesor) {
                padrePredecesor->fijarHijoDer(predecesor->obtenerHijoIzq());
            } else {
                padrePredecesor->fijarHijoIzq(predecesor->obtenerHijoIzq());
            }
            delete predecesor;
        }
        delete nodo; // Eliminar el nodo que ya no se necesita
        return true; // El nodo ha sido eliminado
    }
    return false; // El nodo no se encontró
}
*//*
template <class T>
bool ArbolBinarioOrd<T>::buscar(T& val){
    NodoBinario<T>* nodo = this->raiz;
    bool encontrado = false;

    while((nodo != nullptr) && !encontrado)
    {
        if(val < nodo->obtenerDato())
        {
            nodo = nodo->obtenerHijoIzq();
        }else if ( val > nodo->obtenerDato() )
        {
            nodo = nodo->obtenerHijoDer();
        }else
        {
            encontrado = true;
        }
    }
    return encontrado;
}*//*

template <class T>
void ArbolBinarioOrd<T>::inOrden(){
    if(!this->esVacio())
    {
       (this->raiz)->inOrden();
    }
}

template <class T>
void ArbolBinarioOrd<T>::preOrden(){
    if(!this->esVacio())
    {
        (this->raiz)->preOrden();
    }
}

template <class T>
void ArbolBinarioOrd<T>::posOrden(){
    if(!this->esVacio())
    {
        (this->raiz)->posOrden();
    }
}
*//*
template <class T>
void ArbolBinarioOrd<T>::nivelOrden(){
    if(!this->esVacio())
    {
        queue<NodoBinario<T>* > q;
        q.push(this->raiz);
        NodoBinario<T>* nodo;
        while(!q.empty())
        {
            nodo = q.front();
            q.pop();
            cout<<nodo->obtenerDato()<<" ";
            if(nodo->obtenerHijoIzq() != nullptr)
            {
                q.push(nodo->obtenerHijoIzq());
            }
            if(nodo->obtenerHijoDer() != nullptr)
            {
                q.push(nodo->obtenerHijoDer());
            }
        }
    }
}
*//*
template <class T>
int ArbolBinarioOrd<T>::nivelConMasNodos() {
    if (this->esVacio()) {
        return -1;  // Árbol vacío
    }

    queue<NodoBinario<T>*> q;
    q.push(this->raiz);

    int nivelMaxNodos = 0;  // Nivel con más nodos
    int maxNodos = 0;       // Máximo número de nodos en un nivel
    int nivelActual = 0;

    // Mientras haya nodos por procesar
    while (!q.empty()) {
        int numNodosNivel = q.size();  // Número de nodos en el nivel actual

        // Actualizar si el nivel actual tiene más nodos que los anteriores
        if (numNodosNivel > maxNodos) {
            maxNodos = numNodosNivel;
            nivelMaxNodos = nivelActual;
        }

        // Procesar todos los nodos de este nivel
        for (int i = 0; i < numNodosNivel; ++i) {
            NodoBinario<T>* nodo = q.front();
            q.pop();

            // Agregar hijos del nodo actual a la cola (para el siguiente nivel)
            if (nodo->obtenerHijoIzq() != nullptr) {
                q.push(nodo->obtenerHijoIzq());
            }
            if (nodo->obtenerHijoDer() != nullptr) {
                q.push(nodo->obtenerHijoDer());
            }
        }

        // Incrementar el nivel
        nivelActual++;
    }

    return nivelMaxNodos;
}
*//*
template <class T>
int ArbolBinarioOrd<T>::nivelConMasNodosQueCumplanUmbral(T umbral) {
    if (this->esVacio()) {
        return -1;  // Árbol vacío
    }

    queue<NodoBinario<T>*> q;
    q.push(this->raiz);

    int nivelMaxNodos = 0;  // Nivel con más nodos que cumplen el umbral
    int maxNodos = 0;       // Máximo número de nodos que cumplen el umbral en un nivel
    int nivelActual = 0;

    // Mientras haya nodos por procesar
    while (!q.empty()) {
        int numNodosCumplen = 0;  // Contador de nodos que cumplen el umbral en este nivel
        int numNodosNivel = q.size();  // Número total de nodos en el nivel actual

        // Procesar todos los nodos de este nivel
        for (int i = 0; i < numNodosNivel; ++i) {
            NodoBinario<T>* nodo = q.front();
            q.pop();

            // Comprobar si el nodo cumple con el umbral
            if (nodo->obtenerDato() >= umbral) {
                numNodosCumplen++;
            }

            // Agregar los hijos del nodo actual a la cola (para el siguiente nivel)
            if (nodo->obtenerHijoIzq() != nullptr) {
                q.push(nodo->obtenerHijoIzq());
            }
            if (nodo->obtenerHijoDer() != nullptr) {
                q.push(nodo->obtenerHijoDer());
            }
        }

        // Actualizar si el nivel actual tiene más nodos que cumplen el umbral que los anteriores
        if (numNodosCumplen > maxNodos) {
            maxNodos = numNodosCumplen;
            nivelMaxNodos = nivelActual;
        }

        // Incrementar el nivel
        nivelActual++;
    }

    return nivelMaxNodos;
}
*/

//------------------------------------------------

//MORSE

// Función 1: Insertar nuevo símbolo en el árbol según la codificación Morse
bool insertarSimbolo(T simbolo, const std::string& codigoMorse) {
    if (raiz == nullptr) {
        raiz = new NodoBinario<T>('*'); // Nodo raíz vacío representado por '*'
    }

    NodoBinario<T>* actual = raiz;
    for (char c : codigoMorse) {
        if (c == '.') {
            if (actual->obtenerHijoIzq() == nullptr) {
                actual->fijarHijoIzq(new NodoBinario<T>('*'));
            }
            actual = actual->obtenerHijoIzq();
        } else if (c == '-') {
            if (actual->obtenerHijoDer() == nullptr) {
                actual->fijarHijoDer(new NodoBinario<T>('*'));
            }
            actual = actual->obtenerHijoDer();
        }
    }
    if (actual->obtenerDato() == '*') {
        actual->fijarHijoIzq(nullptr);  // Evitar repeticiones
        actual->fijarHijoDer(nullptr);
        actual = new NodoBinario<T>(simbolo);
        return true;
    }
    return false; // Ya existe un símbolo en esa ruta
}

// Función 2: Codificar palabras en Morse
bool buscarSimbolo(NodoBinario<T>* nodo, T simbolo, std::string& codigoMorse, std::string camino) {
    if (nodo == nullptr) return false;
    if (nodo->obtenerDato() == simbolo) {
        codigoMorse = camino;
        return true;
    }

    if (buscarSimbolo(nodo->obtenerHijoIzq(), simbolo, codigoMorse, camino + ".")) {
        return true;
    }
    if (buscarSimbolo(nodo->obtenerHijoDer(), simbolo, codigoMorse, camino + "-")) {
        return true;
    }

    return false;
}

std::string codificar(const std::string& palabra) {
    std::string resultado;
    for (char simbolo : palabra) {
        std::string codigoMorse;
        if (buscarSimbolo(raiz, simbolo, codigoMorse, "")) {
            resultado += codigoMorse + " ";
        } else {
            resultado += "? ";  // Carácter no encontrado
        }
    }
    return resultado;
}

// Función 3: Decodificar cadenas en Morse
T decodificarSimbolo(const std::string& codigoMorse) {
    NodoBinario<T>* actual = raiz;
    for (char c : codigoMorse) {
        if (c == '.') {
            actual = actual->obtenerHijoIzq();
        } else if (c == '-') {
            actual = actual->obtenerHijoDer();
        }
        if (actual == nullptr) return '?';  // Código inválido
    }
    return actual->obtenerDato();
}

std::string decodificar(const std::vector<std::string>& codigosMorse) {
    std::string resultado;
    for (const std::string& codigo : codigosMorse) {
        resultado += decodificarSimbolo(codigo);
    }
    return resultado;
}

//------------------------------------------------

//VERDURAS

void inicializar(const std::vector<Verdura>& verduras) {
    for (const Verdura& verdura : verduras) {
        insertar(raiz, verdura, 0);
    }
}

void insertar(Nodo*& nodo, const Verdura& verdura, int nivel) {
    if (!nodo) {
        nodo = new Nodo();
    }

    // Determinar la dimensión a comparar
    int dimension = nivel % 2; // 0 para peso, 1 para color

    if (dimension == 0) { // Comparar por peso
        if (verdura.peso < nodo->verduras[0].peso) {
            insertar(nodo->izquierdo, verdura, nivel + 1);
        } else {
            insertar(nodo->derecho, verdura, nivel + 1);
        }
    } else { // Comparar por color
        if (verdura.color < nodo->verduras[0].color) {
            insertar(nodo->izquierdo, verdura, nivel + 1);
        } else {
            insertar(nodo->derecho, verdura, nivel + 1);
        }
    }

    // Agregar la verdura al nodo
    nodo->verduras.push_back(verdura);
}

std::string clasificarNuevaVerdura(float peso, int color) {
    std::map<std::string, int> contador;
    clasificar(raiz, peso, color, contador, 0);

    // Encontrar la etiqueta más repetida
    std::string etiquetaSugerida;
    int maxConteo = 0;
    for (std::map<std::string, int>::iterator it = contador.begin(); it != contador.end(); ++it) {
        if (it->second > maxConteo) {
            maxConteo = it->second;
            etiquetaSugerida = it->first;
        }
    }

    if (etiquetaSugerida.empty()) {
        return "Etiqueta no encontrada";
    } else {
        return etiquetaSugerida;
    }
}

void clasificar(Nodo* nodo, float peso, int color, std::map<std::string, int>& contador, int nivel) {
    if (!nodo) return;

    // Recorrer el árbol hasta encontrar un nodo hoja
    if (!nodo->izquierdo && !nodo->derecho) {
        // Contar las etiquetas de las verduras en este nodo
        for (std::vector<Verdura>::iterator it = nodo->verduras.begin(); it != nodo->verduras.end(); ++it) {
            contador[it->etiqueta]++;
        }
        return;
    }

    // Determinar la dimensión a comparar utilizando el nivel del nodo
    int dimension = nivel % 2; // 0 para peso, 1 para color

    if (dimension == 0) { // Comparar por peso
        if (peso < nodo->verduras.front().peso) {
            clasificar(nodo->izquierdo, peso, color, contador, nivel + 1);
        } else {
            clasificar(nodo->derecho, peso, color, contador, nivel + 1);
        }
    } else { // Comparar por color
        if (color < nodo->verduras.front().color) {
            clasificar(nodo->izquierdo, peso, color, contador, nivel + 1);
        } else {
            clasificar(nodo->derecho, peso, color, contador, nivel + 1);
        }
    }
}
