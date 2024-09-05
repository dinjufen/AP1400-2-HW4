#pragma once

template<typename T>
struct Helper {
public:
    explicit Helper(T* p) : _p(p),_count(1) {}
    ~Helper() {
        delete _p;
        _count = 0;
    }

    size_t _count = 0;
    T* _p = nullptr;
};

template <typename T>
class SharedPtr {
public:
    explicit SharedPtr(T* p = nullptr) : m_helper(p == nullptr ? nullptr : new Helper<T>(p)) {}
    SharedPtr(const SharedPtr<T>& shared_ptr) : m_helper(shared_ptr.m_helper) {
        if (m_helper) {
            ++m_helper->_count;
        }
    }
    SharedPtr<T>& operator=(const SharedPtr<T>& shared_ptr) {
        if (this == &shared_ptr) {
            return *this;
        }

        delete m_helper;
        m_helper = shared_ptr.m_helper;
        if (m_helper) {
            m_helper->_count++;
        }
        return *this;
    }
    ~SharedPtr() {
        if (m_helper) {
            m_helper->_count--;
            if (m_helper->_count == 0) {
                delete m_helper;
            }
        }
        m_helper = nullptr;
    }

    T* get() {
        return m_helper ? m_helper->_p : nullptr;
    }

    T* operator->() const {
        return m_helper ? m_helper->_p : nullptr;
    }

    T operator*() {
        return *(m_helper->_p);
    }

    explicit operator bool() {
        return m_helper && m_helper->_p;
    }

    size_t use_count() {
        return m_helper ? m_helper->_count : 0;
    }

    void reset() {
        delete m_helper;
        m_helper = nullptr;
    }

    void reset(T* new_t) {
        delete m_helper;
        m_helper = new Helper<T>(new_t);
    }

private:
    friend class Helper<T>;
    Helper<T>* m_helper;
};
