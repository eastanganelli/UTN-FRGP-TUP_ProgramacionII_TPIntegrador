#ifndef GENERIC_ARRAY_H
#define GENERIC_ARRAY_H

#include <iostream>

using namespace std;

template <typename T>
/**
 * @brief Clase dinámica de arreglos genérica.
 *
 * Esta clase administra un arreglo dinámico de elementos de tipo T,
 * proporcionando operaciones básicas de acceso, insercion, eliminacion
 * y redimensionamiento.
 *
 * @tparam T Tipo de los elementos almacenados en el array.
 */
class GenericArray {
private:
    /** @brief Número de elementos actualmente almacenados en el arreglo. */
    unsigned int size;

    /** @brief Puntero al bloque dinámico que contiene los elementos de tipo T. */
    T* elements;

    /**
     * @brief Verifica si el índice está dentro del rango válido.
     * @param index Indice a verificar.
     * @return true si el índice es válido, false en caso contrario.
     */
    bool CheckIndex(unsigned int index);

    /**
     * @brief Crea un nuevo registro a partir de @p node (uso interno).
     * @param node Referencia al objeto que se desea crear/copiar.
     * @return true si la creacion fue exitosa, false en caso contrario.
     */
    bool CreateNode(T& node);

    /**
     * @brief Devuelve una copia del elemento ubicado en @p index.
     * @param index Indice del elemento a leer.
     * @return Copia del elemento en @p index.
     * @note La firma actual usa un marcador <T> que puede ser sintácticamente inválido;
     *       conservar según la implementacion existente.
     */
    T* ReadNode(unsigned int index);

    /**
     * @brief Actualiza el registro en la posicion @p index con los datos de @p node.
     * @param index Indice del elemento a actualizar.
     * @param node Referencia con los nuevos datos.
     * @return true si la actualizacion fue exitosa.
     */
    bool UpdateNode(unsigned int index, T& node);

    /**
     * @brief Elimina el registro en la posicion @p index.
     * @param index Indice del elemento a eliminar.
     * @return true si la eliminacion fue exitosa.
     */
    bool DeleteNode(unsigned int index);

    /**
     * @brief Redimensiona la estructura a @p newSize elementos.
     * @param newSize Nueva capacidad deseada.
     * @return true si la redimension se realizo correctamente.
     */
    bool ReSizing(unsigned int newSize);

public:
    /** @brief Constructor: inicializa un GenericArray vacío. */
    GenericArray();

    /** @brief Destructor: libera la memoria utilizada por el array. */
    ~GenericArray();

    /**
     * @brief Compara @p node con elementos del array.
     * @param node Referencia al nodo a comparar.
     * @return true si existe una coincidencia, false en caso contrario.
     */
    bool operator==(T& node);

    /**
     * @brief Inserta o combina @p node con la estructura (comportamiento según implementacion).
     * @param node Referencia al nodo a insertar o combinar.
     * @return true si la operacion tuvo éxito.
     */
    bool operator+(T& node);

    /**
     * @brief Elimina o resta @p node de la estructura (comportamiento según implementacion).
     * @param node Referencia al nodo a eliminar.
     * @return true si la operacion fue exitosa.
     */
    bool operator-(T& node);

    /**
     * @brief Acceso por índice: devuelve referencia al elemento en @p index.
     * @param index Indice del elemento.
     * @return Referencia al elemento en @p index.
     * @note La firma actual usa un marcador <T>& que puede ser sintácticamente inválido;
     *       conservar según la implementacion existente.
     */
    T* operator[](unsigned int index);

    /**
     * @brief Devuelve la cantidad de elementos actualmente almacenados.
     * @return Número de elementos en el array.
     */
    unsigned int Size(void);

    /**
     * @brief Elimina el elemento en la posicion @p index.
     * @param index Indice del elemento a eliminar.
     * @return true si se elimino correctamente.
     */
    bool RemoveAt(unsigned int index);

    /**
     * @brief Inserta @p node en la posicion @p index.
     * @param index Indice donde insertar.
     * @param node Referencia al nodo a insertar.
     * @return true si la insercion tuvo éxito.
     */
    bool InsertAt(unsigned int index, T& node);

    /**
     * @brief Agrega @p node al final del array.
     * @param node Referencia al nodo a agregar.
     * @return true si se agrego correctamente.
     */
    bool Append(T& node);

    /**
     * @brief Limpia todos los elementos del array y libera la memoria asociada.
     * @return true si la operacion fue exitosa.
     */
    bool Clear();

    /**
     * @brief Verifica si el array está vacío.
     * @return true si no hay elementos en el array; false en caso contrario.
     */
    bool IsEmpty();
};

template <typename T>
GenericArray<T>::GenericArray() {
    this->elements = nullptr;
    this->size = 0;
}

template <typename T>
GenericArray<T>::~GenericArray() {
    if(this->elements != nullptr) {
        delete[] elements;
    }
}

template <typename T>
bool GenericArray<T>::CheckIndex(unsigned int index) {
    return index >= this->size;
}

template <typename T>
bool GenericArray<T>::CreateNode(T& node) {
    const unsigned int newSize = this->size + 1;
    if(!this->ReSizing(newSize)) {
        return false;
    }
    this->elements[this->size - 1] = node;
    return true;
}

template <typename T>
T* GenericArray<T>::ReadNode(unsigned int index) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Indice fuera de rango" << endl;
        return nullptr;
    }
    return &this->elements[index];
}

template <typename T>
bool GenericArray<T>::UpdateNode(unsigned int index, T& node) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Indice fuera de rango" << endl;
        return false;
    }
    this->elements[index] = node;
    return true;
}

template <typename T>
bool GenericArray<T>::DeleteNode(unsigned int index) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Indice fuera de rango" << endl;
        return false;
    }
    for(unsigned int i = index; i < this->size - 1; i++) {
        this->elements[i] = this->elements[i + 1];
    }
    return this->ReSizing(this->size - 1);
}

template <typename T>
bool GenericArray<T>::ReSizing(unsigned int newSize) {
    T* newElements = new T[newSize];
    if(newElements == nullptr) {
        cerr << "Error: No se pudo asignar memoria para redimensionar el array" << endl;
        return false;
    }
    if(this->elements != nullptr) {
        unsigned int elementsToCopy = (newSize < this->size) ? newSize : this->size;
        for(unsigned int i = 0; i < elementsToCopy; i++) {
            newElements[i] = this->elements[i];
        }
        delete[] this->elements;
    }
    this->elements = newElements;
    this->size = newSize;
    return true;
}

template <typename T>
bool GenericArray<T>::operator==(T& node) {
    for(unsigned int i = 0; i < this->size; i++) {
        if(this->elements[i] == node) {
            return true;
        }
    }
    return false;
}

template <typename T>
bool GenericArray<T>::operator+(T& node) {
    return this->CreateNode(node);
}

template <typename T>
bool GenericArray<T>::operator-(T& node) {
    for(unsigned int i = 0; i < this->size; i++) {
        if(this->elements[i] == node) {
            return this->DeleteNode(i);
        }
    }
    return false;
}

template <typename T>
T* GenericArray<T>::operator[](unsigned int index) {
    return this->ReadNode(index);
}

template <typename T>
unsigned int GenericArray<T>::Size() {
    return this->size;
}

template <typename T>
bool GenericArray<T>::RemoveAt(unsigned int index) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Indice fuera de rango para eliminacion" << endl;
        return false;
    }
    return this->DeleteNode(index);
}

template <typename T>
bool GenericArray<T>::InsertAt(unsigned int index, T& node) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Indice fuera de rango para insercion" << endl;
        return false;
    }
    const unsigned int newSize = this->size + 1;
    if(!this->ReSizing(newSize)) {
        return false;
    }
    for(unsigned int i = this->size - 1; i > index; i--) {
        this->elements[i] = this->elements[i - 1];
    }
    this->elements[index] = node;
    return true;
}

template <typename T>
bool GenericArray<T>::Append(T& node) {
    const unsigned int newSize = this->size + 1;
    if(!this->ReSizing(newSize)) {
        return false;
    }
    this->elements[this->size - 1] = node;
    return true;
}

template <typename T>
bool GenericArray<T>::Clear() {
    if(this->elements != nullptr) {
        delete[] this->elements;
        this->elements = nullptr;
    }
    this->size = 0;
    return true;
}

template <typename T>
bool GenericArray<T>::IsEmpty() {
    return this->elements == nullptr || this->size == 0;
}

#endif // GENERIC_ARRAY_H
