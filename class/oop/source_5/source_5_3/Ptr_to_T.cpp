#include "Ptr_to_T.h"
#include<stdexcept>

template <class T>
Ptr_to_T<T> &Ptr_to_T<T>::operator+(int a)
{
    p += a;
    return *this;
}

template <class T>
Ptr_to_T<T> &Ptr_to_T<T>::operator-(int a)
{
    p -= a;
    return *this;
}

template <class T>
Ptr_to_T<T> &Ptr_to_T<T>::operator=(const Ptr_to_T &a)
{
    base = a.base;
    p = a.p;
    size = a.size;
    return *this;
}

template <class T>
T* Ptr_to_T<T>::operator->()
{
    return p;
}

template <class T>
T &Ptr_to_T<T>::operator*()
{
    if (p < base || p >= base + size)
        throw std::out_of_range("out of range");
    return *p;
}

template <class T>
Ptr_to_T<T> &Ptr_to_T<T>::operator++()
{
    ++p;
    return *this;
}

template <class T>
Ptr_to_T<T> Ptr_to_T<T>::operator++(int)
{
    Ptr_to_T temp = *this;
    ++p;
    return temp;
}

template <class T>
Ptr_to_T<T> &Ptr_to_T<T>::operator--()
{
    --p;
    return *this;
}

template <class T>
Ptr_to_T<T> Ptr_to_T<T>::operator--(int)
{
    Ptr_to_T temp = *this;
    --p;
    return temp;
}
