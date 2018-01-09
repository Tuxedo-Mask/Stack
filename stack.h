#ifndef STACK_ECPETION_SAFE
#define STACK_ECPETION_SAFE

template <typename T> class Stack
{
public:
    Stack();
    ~Stack();

    /* ... */
private:
    T* v_;
    size_t vsize_;
    size_t vused_;
};

#endif
