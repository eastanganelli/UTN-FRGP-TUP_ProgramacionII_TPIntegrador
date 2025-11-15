#include "array.h"

Array<T>::Array() {
}

Array<T>::~Array() {
    if(this->elements != nullptr) {
        delete[] elements;
    }
}