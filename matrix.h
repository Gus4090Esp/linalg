//
//  matrix.h
//  linalg
//
//  Created by Gustavo Espinoza on 7/4/22.
//

#ifndef matrix_h
#define matrix_h
#include "vector.h"
#include<stdio.h>


template<class T, int N, int M>
class matrix: public vector<vector<T,N>,M>{
public:
    matrix(){};
    matrix(const vector<T,N> &u, const vector<T,N> &v){
        set(0,u);
        set(1,v);
    };
    const T& operator()(int i, int j) const{
        return (*this)[j][i];
    };
    const matrix& operator*=(const T&);
    const matrix& operator/=(const T&);
    void print(const matrix &m);
};




// ARITHMETIC OPERATORS

// multiplication by a scalar
// note this is multiplying every row by a constant
// each row of this matrix class consists of a vector
// these vectors inherit the operators defined in the
// vector object
// what we are doing is using the set function
// for the ith row we are multipying the rowth vector
// by a constant a and setting the numbers
// then returning the address;

//multiplication by scalar
template<class T, int N, int M> const matrix<T,N,M>& matrix<T,N,M>::operator*=(const T &a){
    for (int i = 0; i < M; ++i) {
        set(i, (*this)[i]*a);
    };
    return *this;
};

//division by a scalar
template<class T, int N, int M> const matrix<T,N,M>& matrix<T,N,M>::operator/=(const T &a){
    for (int i = 0; i < M; ++i) {
        set(i, (*this)[i]/a);
    };
};

// oooooo now we get to implement matrix vector multiplication
// and matrix matrix multiplication

// matrix times a scalar
template<class T, int N, int M> const matrix<T,N,M> operator*(const matrix<T,N,M> &m, const T &a){
    return matrix<T,N,M>(m) *= a;
}

// scalar times a matrix
template<class T, int N, int M> const matrix<T,N,M> operator*(const T &a, const matrix<T,N,M> &m){
    return matrix<T,N,M>(m) *= a;
};

// matrix divided by a scalar
template<class T, int N, int M> const matrix<T,N,M> operator/(const T &a, const matrix<T,N,M> &m){
    return matrix<T,N,M>(m) /= a;
};

// vector times a matrix
template<class T, int N, int M> const vector<T,M> operator*(const vector<T,N> &v, const matrix<T,N,M> &m){
    vector<T,M> result;
    for (int i = 0; i < M; ++i) {
        result.set(i, v*m[i]);
    };
    return result;
}
// matrix times a vector;
template<class T, int N, int M> const vector<T,N> operator*(const matrix<T,N,M> &m, const vector<T,N> &v){
    vector<T,N> result;
    for (int i = 0; i < M; ++i){
        result += v[i] * m[i];
    };
    return result;
};

// matrix multiplication
template<class T, int N, int M, int K> const matrix<T,N,K> operator*(const matrix<T,N,M> &m1, const matrix<T,M,K> &m2 ){
    matrix<T,N,K> result;
    for (int i = 0; i < K; ++i){
        result.set(i, m1*m2[i]);
    };
    return result; 
};

template<class T, int N, int M> void matrix<T,N,M>::print(const matrix &m){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << m[i][j] << " ";
        };
        std::cout << "" << std::endl;
    };
};
#endif /* matrix_h */
