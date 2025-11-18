#include "array.h"

Array<T>::Array() {
}

Array<T>::~Array() {
    if(this->elements != nullptr) {
        delete[] elements;
    }
}

bool Array<T>::CheckIndex(unsigned int index) {
    return index >= this->count;
}

bool Array<T>::CreateNode(T* node) {
    const unsigned int newSize = this->count + 1;
    if(!this->ReSizing(newSize)) {
        return false;
    }
    this->elements[this->count - 1] = *node;
    this->count++;
    return true;
}

<T>* Array<T>::ReadNode(unsigned int index) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Índice fuera de rango" << endl;
        return nullptr;
    }
    return this->elements[index];
}

bool Array<T>::UpdateNode(unsigned int index, T* node) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Índice fuera de rango" << endl;
        return false;
    }
    this->elements[index] = node;
    return true;
}

bool Array<T>::DeleteNode(unsigned int index) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Índice fuera de rango" << endl;
        return false;
    }
    for(unsigned int i = index; i < this->count - 1; i++) {
        this->elements[i] = this->elements[i + 1];
    }
    return this->ReSizing(this->count - 1);
}

bool Array<T>::ReSizing(unsigned int newSize) {
    T* newElements = new T[newSize];
    if(newElements == nullptr) {
        cerr << "Error: No se pudo asignar memoria para redimensionar el array" << endl;
        return false;
    }
    unsigned int elementsToCopy = (newSize < this->count) ? newSize : this->count;
    for(unsigned int i = 0; i < elementsToCopy; i++) {
        newElements[i] = this->elements[i];
    }
    delete[] this->elements;
    this->elements = newElements;
    this->count = newSize;
    return true;
}

bool Array<T>::operator==(T* node) {
    if(node == nullptr) {
        cerr << "Error: Nodo nulo proporcionado para comparación" << endl;
        return false;
    }
    for(unsigned int i = 0; i < this->count; i++) {
        if(this->elements[i] == *node) {
            return true;
        }
    }
    return false;
}

bool Array<T>::operator+(T* node) {
    if(node == nullptr) {
        cerr << "Error: Nodo nulo proporcionado para agregar" << endl;
        return false;
    }
    return this->CreateNode(node);
}

bool Array<T>::operator-(T* node) {
    if(node == nullptr) {
        cerr << "Error: Nodo nulo proporcionado para eliminar" << endl;
        return false;
    }
    for(unsigned int i = 0; i < this->count; i++) {
        if(this->elements[i] == node) {
            return this->DeleteNode(i);
        }
    }
    return false;
}

<T>* Array<T>::operator[](unsigned int index) {
    return this->ReadNode(index);
}

bool Array<T>::operator=(T* node) {

}

unsigned int Array<T>::Count() {
    return this->count;
}

bool Array<T>::RemoveAt(unsigned int index) {
    if(this->CheckIndex(index)) {
        cerr << "Error: Índice fuera de rango para eliminación" << endl;
        return false;
    }
    return this->DeleteNode(index);
}

bool Array<T>::InsertAt(unsigned int index, T* node) {
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

bool Array<T>::Append(T* node) {
    if(node == nullptr) {
        cerr << "Error: Nodo nulo proporcionado para agregar al final" << endl;
        return false;
    }
    const unsigned int newSize = this->count + 1;
    if(!this->ReSizing(newSize)) {
        return false;
    }
    this->elements[this->count - 1] = *node;
    this->count++;
    return true;
}

bool Array<T>::Clear() {
    delete[] this->elements;
    this->elements = nullptr;
    this->count = 0;
    return true;
}

bool Array<T>::IsEmpty() {
    return this->count < 1;
}