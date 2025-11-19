#include "generic_array.h"

template <typename T>
GenericArray<T>::GenericArray() {
    this->elements = nullptr;
    this->sizing = 0;
}

template <typename T>
GenericArray<T>::~GenericArray() {
    if(this->elements != nullptr) {
        delete[] elements;
    }
}

template <typename T>
bool GenericArray<T>::CheckIndex(unsigned int index) {
    return index >= this->count;
}

template <typename T>
bool GenericArray<T>::CreateNode(T& node) {
    const unsigned int newSize = this->count + 1;
    if(!this->ReSizing(newSize)) {
        return false;
    }
    this->elements[this->count - 1] = *node;
    this->count++;
    return true;
}

template <typename T>
T* GenericArray<T>::ReadNode(unsigned int index) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Índice fuera de rango" << endl;
        return nullptr;
    }
    return this->elements[index];
}

template <typename T>
bool GenericArray<T>::UpdateNode(unsigned int index, T& node) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Índice fuera de rango" << endl;
        return false;
    }
    this->elements[index] = node;
    return true;
}

template <typename T>
bool GenericArray<T>::DeleteNode(unsigned int index) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Índice fuera de rango" << endl;
        return false;
    }
    for(unsigned int i = index; i < this->count - 1; i++) {
        this->elements[i] = this->elements[i + 1];
    }
    return this->ReSizing(this->count - 1);
}

template <typename T>
bool GenericArray<T>::ReSizing(unsigned int newSize) {
    T* newElements = new T[newSize];
    if(newElements == nullptr) {
        cerr << "Error: No se pudo asignar memoria para redimensionar el array" << endl;
        return false;
    }
    if(this->elements != nullptr) {
        unsigned int elementsToCopy = (newSize < this->count) ? newSize : this->count;
        for(unsigned int i = 0; i < elementsToCopy; i++) {
            newElements[i] = this->elements[i];
        }
        delete[] this->elements;
    }
    this->elements = newElements;
    this->count = newSize;
    return true;
}

template <typename T>
bool GenericArray<T>::operator==(T& node) {
    for(unsigned int i = 0; i < this->count; i++) {
        if(this->elements[i] == *node) {
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
    for(unsigned int i = 0; i < this->count; i++) {
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
unsigned int GenericArray<T>::ElementsCount() {
    return this->sizing;
}

template <typename T>
bool GenericArray<T>::RemoveAt(unsigned int index) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Índice fuera de rango para eliminación" << endl;
        return false;
    }
    return this->DeleteNode(index);
}

template <typename T>
bool GenericArray<T>::InsertAt(unsigned int index, T& node) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Índice fuera de rango para inserción" << endl;
        return false;
    }
    const unsigned int newSize = this->count + 1;
    if(!this->ReSizing(newSize)) {
        return false;
    }
    for(unsigned int i = this->count - 1; i > index; i--) {
        this->elements[i] = this->elements[i - 1];
    }
    this->elements[index] = *node;
    this->count++;
    return true;
}

template <typename T>
bool GenericArray<T>::Append(T& node) {
    const unsigned int newSize = this->count + 1;
    if(!this->ReSizing(newSize)) {
        return false;
    }
    this->elements[this->count - 1] = *node;
    this->count++;
    return true;
}

template <typename T>
bool GenericArray<T>::Clear() {
    delete[] this->elements;
    this->elements = nullptr;
    this->count = 0;
    return true;
}

template <typename T>
bool GenericArray<T>::IsEmpty() {
    return  this->elements == nullptr;
}
