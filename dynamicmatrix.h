//
//  dynamicmatrix.h
//  linalg
//
//  Created by Gustavo Espinoza on 7/21/22.
//

#ifndef dynamicmatrix_h
#define dynamicmatrix_h
#include<stdio.h>

template<class T>
class dynamicmatrix: public dynamicmatrix<T>{
    int N;
public:
    dynamicmatrix(int m = 0, int n = 0, const T &t = 0);
    
    // returning i,j component;
    T& operator()(int i, int j){
        return component[i*N +j];
    };
    
    // read only version
    const T& operator(int i, int j, char*) const{
        return component[i*N + j];
    };
    
    int length() const{
        return dim()/N;
    };
    
    int width() const{
        return N;
    };
    
    // arithmetic operators
    const dynamicmatrix& operator+=(const dynamicmatrix&);
    const dynamicmatrix& operator-=(const dynamicmatrix&);
    const dynamicmatrix& operator*=(const T &t);
    const dynamicmatrix& operator/=(const T&);
};

// constructor;
template<class T> dynamicmatrix<T>::dynamicmatrix(int m, int n, const T &t){
    dimension = n*m;
    N = n;
    component = dimension ? new T[dimension] : 0;
    for (int i = 0 ; i < dimension ; ++i) {
        component[i] = t;
    };
};

// arithmetic operators
// += operator for a matrix
template<class T> const dynamicmatrix<T>& dynamicmatrix<T>::operator+=(const dynamicmatrix<T> &m){
    for (int i = 0; i < dimension; ++i) {
        component[i] += v[i];
    };
    return *this;
};

// -= operator for a matrix
template<class T> const dynamicmatrix<T>& dynamicmatrix<T>::operator-=(const dynamicmatrix<T> &m){
    for (int i = 0; i < dimension; ++i) {
        component[i] -= m[i];
    };
    return *this;
};

// scalar mulitplication
template<class T> const dynamicmatrix<T>& dynamicmatrix<T>::operator*=(const T &t){
    for (int i = 0; i < dimension; ++i) {
        component[i] *= t;
    };
    return *this;
};

// scalar division
template<class T> const dynamicmatrix<T>& dynamicmatrix<T>::operator/=(const T &t){
    for (int i = 0; i < dimension; ++i) {
        component[i] /= t;
    };
    return *this;
};

// nonmember binary arithmetic operators

// addition
template<class T> const dynamicmatrix<T> operator+(const dynamicmatrix<T> &m1, const dynamicmatrix<T> &m2){
    return dynamicmatrix<T>(m1) += m2;
};

// subtraction
template<class T> const dynamicmatrix<T> operator-(const dynamicmatrix<T> &m1, const dynamicmatrix<T> &m2){
    return dynamicmatrix<T>(m1) -= m2;
};

// matrix times scalar
template<class T> const dynamicmatrix<T> operator*(const dynamicmatrix<T> &m, const T &t){
    return dynamicmatrix<T>(m) *= t;
};

// scalar times matrix
template<class T> const dynamicmatrix<T> operator*(const T &t, const dynamicmatrix<T> &m){
    return dynamicmatrix<T>(m) *= t;
};

// matrix divided by a scalar
template<class T> const dynamicmatrix<T> operator/(const dynamicmatrix<T> &m, const T &t){
    return dynamicmatrix<T>(m) /= t;
};

// negative operator
template<class T> const dynamicmatrix<T> operator-(const dynamicmatrix<T> &m){
    return dynamicmatrix<T>(m) *= -1;
};

// printing current object 
template<class T> void print(const dynamicmatrix<T> &m){
    for (int i = 0; i < m.length(); ++i) {
        for (int j = 0; j < m.width(); ++j) {
            printf("v[%d,%d]=%f;  ",i,j,v(i,j,"read"));
        };
        printf("\n";)
    };
};

#endif /* dynamicmatrix_h */
