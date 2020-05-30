#pragma once

template <class T>
class Ptr_to_T
{
private:
    T *base;
    T *p;
    int size;

public:
    Ptr_to_T(T *b, T *_p, int s) : base(b), p(_p), size(s) {}

    Ptr_to_T() {}

    Ptr_to_T &operator+(int);

    Ptr_to_T &operator-(int);

    Ptr_to_T &operator=(const Ptr_to_T &);

    T *operator->();

    T &operator*();

    Ptr_to_T &operator++();

    Ptr_to_T operator++(int);

    Ptr_to_T &operator--();

    Ptr_to_T operator--(int);

    T *begin();

    T *end();
};