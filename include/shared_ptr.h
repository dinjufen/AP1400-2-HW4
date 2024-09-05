#ifndef SHARED_PTR
#define SHARED_PTR
#include "shared_ptr.hpp"

template <typename T>
SharedPtr<T> make_shared(T arg) {
    return SharedPtr<T>{new T(arg)};
}

#endif //SHARED_PTR