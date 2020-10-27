//*****************************************************************
// File:   BoundedQueue.cpp
// Author: PSCD-Unizar
// Date:   Octubre 2018
// Coms:   Especificación de la clase
//*****************************************************************

#include "BoundedQueue.hpp"
#include <cassert>
#include <cstring>

//-----------------------------------------------------
template <class T>
BoundedQueue<T>::BoundedQueue(const int N) {

    this->N = N;
    data = new T[N];
    empty();
}
//-----------------------------------------------------
template <class T>
void BoundedQueue<T>::empty() {

    pri = 0;
    sig = 0;
    nEl = 0;
}
//-----------------------------------------------------
template <class T>
BoundedQueue<T>::~BoundedQueue() {

    delete[] data;
}
//-----------------------------------------------------
template <class T>
void BoundedQueue<T>::enqueue(const T d) {

    assert(nEl<N);
    data[sig] = d;
    sig = (sig+1) % N;
    nEl++;
}
//-----------------------------------------------------
template <class T>
void BoundedQueue<T>::dequeue() {

    assert(nEl>0);
    pri = (pri+1) % N;
    nEl--;
}
//-----------------------------------------------------
template <class T>
T BoundedQueue<T>::first() {

    assert(nEl>0);
    T f = data[pri];
    return f;
}
//-----------------------------------------------------
template <class T>
int BoundedQueue<T>::length() {
    
    return nEl;
}
//-----------------------------------------------------
template <class T>
int BoundedQueue<T>::size() {
    
    return N;
}
//-----------------------------------------------------
template <class T>
void BoundedQueue<T>::print() {

    if (nEl > 0) {
        for (int i=0; i<nEl-1; i++) {
            cout << data[(pri+i)%N] << ",";
        }
        cout << data[(pri+nEl-1)%N];
    }
    cout << endl;
}
//-----------------------------------------------------
template <class T>
void BoundedQueue<T>::clone(BoundedQueue<T> &copy) {
    
    assert(N == copy.N);

    // compañeros de la misma clase pueden acceder a elementos privados
    copy.nEl = nEl;
    copy.pri = pri;
    copy.sig = sig;
    for (int i=0; i<N; i++) {
        copy.data[i] = data[i];
    }
}
//-----------------------------------------------------