//
//  vector.h
//  linalg
//
//  Created by Gustavo Espinoza on 7/3/22.
//

#ifndef vector_h
#define vector_h
#include<stdio.h>

// here class T refers to the type of
// of array, N refers to the number of
// of elements
template<class T, int N> class vector {
    T elements[N];
public:
    // declarations
    vector(const T &a = 0); // constructor
    vector(const vector&); // copy constructor
    const vector& operator=(const T&); // assignment operator by scalar
    const vector& operator=(const vector&); // assignment operator by vector
    
    // destructor
    ~vector(){
    };
    
    // return ith element of a vector
    const T& operator[](int i) const{
        return elements[i];
    };
    
    // function that can manipulate elements of a vector
    void set(int i, const T &a = 0){
        elements[i] = a;
    };
    
    // defining some arithmetic operators
    const vector& operator+=(const vector&);
    const vector& operator-=(const vector&);
    const vector& operator*=(const T &a);
    const vector& operator/=(const T &a);
    void print(const vector<T,N>&);
};

// constructor via constant
template<class T, int N> vector<T,N>::vector(const T &a){
    for (int i = 0; i < N; ++i) {
        elements[i] = a;
    };
};

// copy constructor
template<class T, int N> vector<T,N>::vector(const vector &v){
    for (int i = 0; i < N; ++i) {
        elements[i] = v.elements[i];
    };
};

// assignment operator using a vector
template<class T, int N> const vector<T,N>& vector<T,N>::operator=(const vector<T,N> &v){
    if (this != &v) {
        for (int i = 0; i < N; ++i) {
            elements[i] = v.elements[i];
        };
    };
    return *this;
};

//assignment operator using a scalar
template<class T, int N> const vector<T,N>& vector<T,N>::operator=(const T &a){
    for (int i = 0; i < N; ++i) {
        elements[i] = a;
    };
    return *this;
};

// addition of vector to current vector
template<class T, int N> const vector<T,N>& vector<T,N>::operator+=(const vector &v){
    for (int i = 0; i < N; ++i) {
        elements[i] += v.elements[i];
    };
    return *this;
};

// addition of two vectors
template<class T, int N> const vector<T,N> operator+(const vector<T,N> &u, const vector<T,N> &v){
    return vector<T,N>(u) += v;
};

// return positive of a vector
template<class T, int N> const vector<T,N>& operator+(const vector<T,N> &u){
    return u;
};

// negative of a vector
template<class T, int N> const vector<T,N> operator-(const vector<T,N> &u){
    return vector<T,N>(u) *= -1;
};

// dot product
template<class T, int N> const T operator*(const vector<T,N> &u, const vector<T,N> &v){
    T sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += v[i]*u[i];
    };
    return sum;
};

//  subtracting a vector from the current vector
template<class T, int N> const vector<T,N>& vector<T,N>::operator-=(const vector<T,N>&v){
    for(int i = 0; i < N; i++){
        elements[i] -= v[i];
    };
    return *this;
};

//  multiplying the current vector by a scalar
template<class T, int N> const vector<T,N>& vector<T,N>::operator*=(const T &a ){
    for (int i = 0; i < N; ++i) {
        elements[i] *= a;
    };
    return *this;
};

// scalar division
template<class T, int N> const vector<T,N>& vector<T,N>::operator/=(const T &a ){
    for (int i = 0; i < N; ++i) {
        elements[i] /= a;
    };
    return *this;
};

//vector minus vector
template<class T, int N> const vector<T,N> operator-(const vector<T,N> &u, const vector<T,N> &v){
    return vector<T,N>(u) -= v;
};

// vector times scalar
template<class T, int N> const vector<T,N> operator*(const vector<T,N> &u, const T &a){
    return vector<T,N>(u) *= a;
};

// scalar times a vector
template<class T, int N> const vector<T,N> operator*(const T &a, const vector<T,N> &u){
    return vector<T,N>(u) *= a;
};

// division by scalar 
template<class T, int N> const vector<T,N> operator/(const vector<T,N> &u, const T &a){
    return vector<T,N>(u) /= a;
};

template<class T, int N> void vector<T,N>::print(const vector<T,N> &v){
    std::cout << "(";
    for (int i = 0; i < N; ++i) {
        std::cout << v[i] << " ";
    };
    std::cout << ")" << std::endl; 
}


#endif /* vector_h */
