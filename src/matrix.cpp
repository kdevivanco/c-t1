//
// Created by rudri on 3/23/2022.
//
#include<iostream>
#include <random>

#include "matrix.h"
using namespace utec;
using namespace std;

matrix::matrix(int rows, int cols){
    rows_ = rows;
    cols_ = cols;
    int size = rows_ * cols_;
    values = new int[size];
}

matrix::matrix(const matrix& other){
    if(&other == this){
        return;
    }

    rows_ = other.rows_;
    cols_ = other.cols_;
    values = new int[rows_*cols_];
}


matrix &matrix::operator=(const matrix& other){
    if (&other == this) {
        return *this;
    }

    rows_ = other.rows_;
    cols_ = other.cols_;
    values = new int[rows_ * cols_];
    for (size_t i = 0; i < other.rows_; ++i)
        for (size_t j = 0; j < other.cols_; ++j)
            values[i * cols_ + j] = other(i,j);
    return *this;
}

int main(){
    matrix m(3, 3); //Esto funcona
    m(1,1) = 1; //Esto funciona
    cin >> m(1,2); //Esto funciona
    cout<<m; //esto funciona
    matrix mtestcop(3,3); //esto funciona
    mtestcop = m; //esto funciona
    cout<< "copytest\n"<<mtestcop;



    random_device rd;
    utec::matrix m1(8, 9);
    utec::matrix m2(4, 5);
    uniform_int_distribution<int> dis(0, 100);
    for (size_t i = 0; i < m1.rows(); ++i)
        for (size_t j = 0; j < m1.cols(); ++j)
            m1(i, j) = dis(rd);
    // Copia
    utec::matrix m3 = m1;
    for (size_t i = 0; i < m2.rows(); ++i)
        for (size_t j = 0; j < m2.cols(); ++j)
            m2(i, j) = dis(rd);
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    cout << m1 << endl << m2 << endl;
    // Move
    std::swap(m1, m2); // El swap es lo que malogra las matrices, deja todos los valores en 0!
    m2(0, 0) = 100;
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    cout << m1 << endl << m2 << endl << m3 <<endl;

}