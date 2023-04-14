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
    values = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        values[i] = new int[cols_];
    }
}

matrix &matrix::operator=(const matrix& other){
    if (&other == this) {
        return *this;
    }
    for (int i = 0; i < rows_; ++i) {
        delete[] values[i];
    }
    delete[] values;


    rows_ = other.rows_;
    cols_ = other.cols_;

    values = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        values[i] = new int[cols_];
    }


    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            values[i][j] = other.values[i][j];
        }
    }

    return *this;
}



int main(){
    random_device rd;
    utec::matrix m1(10, 20);
    utec::matrix m2(30, 40);
    uniform_int_distribution<int> dis(0, 100);
    for (size_t i = 0; i < m1.rows(); ++i) {
        for (size_t j = 0; j < m1.cols(); ++j)
            m1(i, j) = dis(rd);
    }
    utec::matrix m3 = m1;
    for (size_t i = 0; i < m2.rows(); ++i) {
        for (size_t j = 0; j < m2.cols(); ++j)
            m2(i, j) = dis(rd);
    }
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    swap(m1, m2);
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
}