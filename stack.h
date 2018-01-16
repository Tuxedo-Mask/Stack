#ifndef STACK_ECPETION_SAFE
#define STACK_ECPETION_SAFE

#include <assert.h>

template<typename T>
T* newCopy(
            const T* src
          , size_t srcSize
          , size_t destSize
          )
{
    assert(destSize >= srcSize);
    T* dest = new T[destSize];
    try {
        for (size_t i = 0; i < srcSize; ++i) {
            dest[i] = src.v_[i];
        }
    }
    catch(...) {
        delete[] dest;
        throw;
    }

    return dest;
}

template <typename T> class Stack
{
public:
    Stack();
    Stack(const Stack&);

    ~Stack();

    Stack& operator=(const Stack&);

    /* ... */

private:
    T* v_;
    size_t vsize_;
    size_t vused_;
};

// default constructor
template <typename T>
Stack<T>::Stack()
                : v_(new T[vsize_])
                , vsize_(10)
                , vused_(0)
{
}

// copy constructor
template <typename T>
Stack<T>::Stack(const Stack& orig)
                                 : v_(newCopy (orig.v_, orig.vsize_, orig.vsize_))
                                 , vsize_(orig.vsize_)
                                 , vused_(orig.vused_)
{
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] v_;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& right)
{
    if (this != &right) {
        vsize_ = right.vsize_;
        vused_ = right.vused_;

        T* v_new = newCopy (right.v_, right.vsize_, right.vsize_);
        delete[] v_;

        v_ = v_new;

    }

    return *this;
}

#endif
