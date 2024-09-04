#ifndef UNIQUE_PTR
#define UNIQUE_PTR
#include "unique_ptr.hpp"

template<typename T>
UniquePtr<T> make_unique(T arg) {
    UniquePtr ptr{new T(arg)};
    return ptr;
}








#endif //UNIQUE_PTR