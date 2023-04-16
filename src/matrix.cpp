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
    for (size_t i = 0; i < other.rows_; ++i)
        for (size_t j = 0; j < other.cols_; ++j)
            values[i * cols_ + j] = other(i,j);
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

bool matrix::operator==(const matrix& other) const{
    //Si son de diferentes dimensiones
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        return false;
    }

    //Si tienen diferente valor por fila
    for (int i = 0; i < rows_ * cols_; ++i) {
        if (values[i] != other.values[i]) {
            return false;
        }
    }
    return true;
}

bool matrix::operator!=(const matrix& other) const {
    return !(*this == other); //Como el == ya esta sobre cargado puedo llamarlo en esta
}


//Sobre carga suma, funciona
matrix matrix::operator+(const matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        return other; //por mientras ponemos esto, luego habra que implementar el error
    }

    matrix result(rows_, cols_);

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result(i, j) = values[i * cols_ + j] + other.values[i * cols_ + j];
        }
    }

    return result;
}
//Sobre carga * -> multiplicacion por escalar FUNCIONA!
matrix matrix::operator*(const int scalar) const {
    matrix result(rows_, cols_);

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result(i, j) = values[i * cols_ + j] * scalar;
        }
    }

    return result;
}

matrix &matrix::operator*=(const int scalar) {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            values[i * cols_ + j] *= scalar;
        }
    }

    return *this;
}

matrix operator*(const int scalar, const matrix& m) {
    return m * scalar;
}

