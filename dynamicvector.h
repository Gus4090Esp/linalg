//
//  dynamicvector.h
//  linalg
//
//  Created by Gustavo Espinoza on 7/7/22.
//

#ifndef dynamicvector_h
#define dynamicvector_h
#include<stdio.h>

template<class T> class dynamicvector{
protected:
    int dimension;
    T* component;
public:
    // constructor
    dynamicvector(int dim = 0, const T &a = 0);
    // copy constructor
    dynamicvector(const dynamicvector&);
    //asignment operators
    const dynamicvector& operator=(const dynamicvector&);
    const dynamicvector& operator=(const T&);
    ~dynamicvector(){
        delete [] component;
    };
    
    // we will define some common low cost functions
    // these shouldn't take up too much memory and their
    // cost will be less than their utility
    
    // get the dimensions
    int dim() const{
        return dimension;
    };
    // read/write the ith component
    T& operator()(int i){
        return component[i];
    };
    // read the ith component
    const T& operator[](int i) const{
        return component[i];
    };
    const dynamicvector& operator+=(const dynamicvector&);
    const dynamicvector& operator-=(const dynamicvector&);
    const dynamicvector& operator*=(const T&);
    const dynamicvector& operator/=(const T&);
};

// constructor
template<class T> dynamicvector<T>::dynamicvector(int dim, const T &a):dimension(dim), component(dim ? new T[dim] : 0) {
    for (int i = 0; i < dim; ++i) {
        component[i] = a;
    };
};

// copy constructor
template<class T> dynamicvector<T>::dynamicvector(const dynamicvector<T> &v):dimension(v.dimension),component(v.dimension ? new T[v.dimension]:0){
    for (int i = 0; i < v.dimension; ++i) {
        component[i] = v.component[i];
    };
};

// assignment operator
template<class T> const dynamicvector<T>& dynamicvector<T>::operator=(const dynamicvector<T> &v){
    if (this != &v) {
        if (dimension > v.dimension) {
            delete [] (component + v.dimension);
        };
        if (dimension < v.dimension) {
            delete [] component;
            component = new T[v.dimension];
        };
        for (int i = 0; i < v.dimension; ++i) {
            component[i] = v.component[i];
        };
        dimension = v.dimension;
    };
    return *this;
};

// assignment with scalar
template<class T> const dynamicvector<T>& dynamicvector<T>::operator=(const T &a){
    for (int i = 0; i < dimension; ++i) {
        component[i] =a;
    };
    return *this;
};

// adding a dynamicvector to current one
template<class T> const dynamicvector<T>& dynamicvector<T>::operator+=(const dynamicvector<T> &v){
    for (int i = 0; i < dimension; ++i) {
        component[i] += v[i];
    };
    return *this;
};

// dynamicvector + dynamic vector
template<class T> const dynamicvector<T> operator+(const dynamicvector<T> &u, const dynamicvector<T> &v){
    return dynamicvector<T>(u) += v;
};

// negative vector
template<class T> const dynamicvector<T> operator-(const dynamicvector<T> &u){
    return dynamicvector<T>(u) *= - 1.;
};

// function print out the vector
template<class T> void print(const dynamicvector<T> &v){
    std::cout << "(";
    for (int i = 0; i < v.dim(); ++i) {
        std::cout << v[i] << " ";
    };
    std::cout << "" << std::endl; 
};

// subtraction operator from current object
template<class T> const dynamicvector<T>& dynamicvector<T>::operator-=(const dynamicvector<T> &v){
    for (int i = 0; i < dimension; ++i) {
        component[i] -= v[i];
    };
    return *this;
};

// scalar multiplication
template<class T> const dynamicvector<T>& dynamicvector<T>::operator*=(const T &a){
    for (int i = 0; i < dimension; ++i) {
        component[i] *= a;
    };
    return *this;
};

// scalar division
template<class T> const dynamicvector<T>& dynamicvector<T>::operator/=(const T &a){
    for (int i = 0; i < dimension; ++i) {
        component[i] /= a;
    };
    return *this;
};

// u - v
template<class T> const dynamicvector<T> operator-(const dynamicvector<T> &u, const dynamicvector<T> &v){
    return dynamicvector<T>(u) -= v;
};

// scalar times dynamicvector
template<class T> const dynamicvector<T> operator*(const T &a, const dynamicvector<T> &u){
    return dynamicvector<T>(u) *= a;
};

// dynamicvector times a scalar
template<class T> const dynamicvector<T> operator*(const dynamicvector<T> &u, const T &a){
    return dynamicvector<T>(u) *= a;
};

// dynamicvector / scalar
template<class T> const dynamicvector<T> operator/(const dynamicvector<T> &u, const T &a){
    return dynamicvector<T>(u) /= a;
};

// inner product here we have to assume equal dimensions
// however if one dimension is longer than the other it should still work
template<class T> T operator*(const dynamicvector<T> &u, const dynamicvector<T> &v){
    T sum = 0;
    for (int i = 0; i < u.dim(); ++i){
        sum += u[i]*v[i];
    };
    return sum; 
};


#endif /* dynamicvector_h */
