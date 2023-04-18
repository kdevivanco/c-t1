//
// Kayla de Vivanco Briceno
//
#include<iostream>
typedef size_t SIZE_TYPE;
#include <random>

#include "matrix.h"
using namespace utec;
using namespace std;

//Constructor por parametros
matrix::matrix(int rows, int cols){
    rows_ = rows;
    cols_ = cols;
    int size = rows_ * cols_;
    values = new int[size]; // Array unidimensional almacenado en memoria dinamica que contiene todos los valores de la matriz
}

//Sobrecarga () para indexar la matriz y asingar valores
int& matrix::operator()(int row, int col) const{
    return values[row * cols_ + col];
}
//Sobre la formula rows * cols_ + col
//Leer -> La formula row * cols_ + col es la formula de indexacion de la matriz, en lugar de poner (i,j) ya que values es unidimensional
// "row": índice de fila del elemento indexado (parametro - valor)
// "cols_" numero total de columnas (variable miembro)
// "col"  índice de columna del elemento indexado (parametro - valor)
// row * cols_ = desplazamiento para la fila, + cols = desplazamiento en fila y columna -> ubicacion del indice


// Constructor copia
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


//Sobre carga =
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

//Sobrecarga al booleano ==
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

//Sobrecarga al booleano !=
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
matrix matrix::operator*(int scalar) const {
    matrix result(rows_, cols_);

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result(i, j) = values[i * cols_ + j] * scalar;
        }
    }

    return result;
}

//Sobre carga multiplicacion de matrices
matrix matrix::operator*(const matrix& other) const {
   //Si son de diferente dimensiones
    if (cols_ != other.rows_) {
        return other;
    }

    //Creamos matriz para almacenar los resultados
    matrix result(rows_, other.cols_);

    //Se multiplican los valores
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < other.cols_; ++j) {
            int sum = 0;
            for (int k = 0; k < cols_; ++k) {
                sum += values[i * cols_ + k] * other.values[k * other.cols_ + j];
            }
            result(i, j) = sum;
        }
    }

    return result;
}

//Sobre carga *=
matrix &matrix::operator*=(int scalar) {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            values[i * cols_ + j] *= scalar;
        }
    }

    return *this;
}

//Sobrecarga a multiplicacion en orden contrario - no es member function
//Esto es en caso la operacion tenga como lhs el int, es decir -> m1 = 5 * m2
//Esta sobrecarga redirecciona a la sobre carga de clase matriz donde se multiplica matriz * int escalar
//Sin esta sobre carga, la multiplicacion no funcionaria para casos donde lhs es int
utec::matrix operator*(int scalar, utec::matrix m) {
    return m * scalar;
}

