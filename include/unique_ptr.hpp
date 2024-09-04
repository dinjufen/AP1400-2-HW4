#pragma once
#include <utility>

template<typename T>
class UniquePtr {
public:
    UniquePtr() : _data(nullptr) {}
    explicit UniquePtr(T* data) : _data(data) {}
    UniquePtr(UniquePtr&& ptr)  noexcept : _data(std::move(ptr.release())) {}
    UniquePtr(const UniquePtr& ptr) = delete;
    UniquePtr& operator=(const UniquePtr& ptr) = delete;

    ~UniquePtr() {
        delete _data;
        _data = nullptr;
    }

    explicit operator bool() const {
        return _data != nullptr;
    }

    inline T* operator->() {
        return _data;
    }

    inline T* get() {
        return _data;
    }

    T operator*() {
        return *_data;
    }

    void reset() {
        delete _data;
        _data = nullptr;
    }

    void reset(T* data) {
        delete _data;
        _data = data;
    }

    T* release() {
        T* ret = _data;
        _data = nullptr;
        return ret;
    }
private:
    T* _data;
};