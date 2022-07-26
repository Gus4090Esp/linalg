//
//  list.h
//  linalg
//
//  Created by Gustavo Espinoza on 7/15/22.
//

#ifndef list_h
#define list_h
#include<stdio.h>

template<class T> class list{
protected:
    int number;
    T** item;
public:
    // constructor
    list(int n = 0):number(n), item(n ? new T*[n]:0){
    };
    // constructor with some object type T
    list(int n, const T &t):number(n), item(n ? new T*[n] : 0){
        for (int i = 0; i < number; ++i) {
            item[i] = new T(t);
        };
    };
    // copy constructor
    list(const list<T>&);
    
    // assignment operator
    const list<T>& operator=(const list<T>&);
    
    //destructor
    ~list(){
        for (int i = 0; i < number; ++i) {
            delete item[i];
        };
        delete [] item;
    };
    
    // function to return size of list
    int size() const{ return number; };
    
    // need a method to read and write
    
    //read/rwite ith item
    T& operator() (int i){
        if (item[i]) {
            return *(item[i]);
        };
    };
    
    // read ith item
    const T& operator[](int i) const {
        if (item[i]) {
            return *(item[i]);
        };
    };
};

// copy constructor
template<class T> list<T>::list(const list<T> &L):number(L.number), item(L.number ? new T*[L.number]:0){
    for (int i = 0; i < L.number; ++i) {
        if (L.item[i]) {
            item[i] = new T(*L.item[i]);
        };
    };
};


// assignment operator
template<class T> const list<T>& list<T>::operator=(const list<T> &L){
    if (this != &L) {
        if (number > L.number) {
            delete [] (item + L.number);
        };
        if (number < L.number) {
            delete [] item;
            item = new T*[L.number];
        };
        for (int i = 0; i < L.number ; ++i) {
            if (L.item[i]) {
                item[i] = new T(*L.item[i]);
            };
        };
    };
    return *this;
};

// I'm probably going to have to come back and change this to
// match what print function is in the list 
template<class T> void print(const list<T> &L){
    for (int i = 0; i < L.size(); ++i) {
        std::cout << L[i] << " ";
    };
    std::endl; 
}

#endif /* list_h */
