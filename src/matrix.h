//
// Created by rudri on 3/23/2022.
//

#ifndef PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
#define PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H

#include <iostream>
#include <iomanip>
using namespace std;
namespace utec {

    class matrix {
    private:
        int* values; // Puntero a puntero para representar la matriz dinámica
        int rows_; // Número de filas de la matriz
        int cols_; // Número de columnas de la matriz

    public:
        matrix() = default;
        // Constructor por parámetros
        matrix(int rows, int cols);

        //Constructor copia
        matrix(const matrix& other);

        //Asignacion copia Sobre carga =
        matrix& operator=(const matrix& other);

        //Sobrecarga operador ==;
        bool operator==(const matrix& other) const;

        bool operator!=(const matrix& other) const;
        //suma de matrices
        matrix operator+(const matrix& other) const;

        //multiplicacion de matrices
        matrix operator*(const matrix& other) const;

        // multiplicacion con escalar
        matrix operator*(const int scalar) const;


        // multiplicacion = con escalar
        matrix& operator*=(const int scalar);


        // Destructor
        ~matrix() {
            //Liberar la memoria dinámica de la matriz
            delete[] values;
        }

        int getRows(){
            return this->rows_;
        }


        // Sobrecarga de operador para asignar los elementos de la matriz
        int& operator()(int row, int col) const;

        // Sobrecarga de operador para imprimir la matriz
        //Por alguna razon el programa se cae si lo pongo fuera del .h
        friend ostream& operator<<(ostream& out, const matrix& m) {
            for (int i = 0; i < m.rows_; ++i) {
                for (int j = 0; j < m.cols_; ++j) {
                    out << setw(3) <<  m(i, j) << " ";

                }
                std::cout << std::endl;
            }
            return out;
        }

        // Método para obtener el número de filas de la matriz
        int rows() const {
            return rows_;
        }

        // Método para obtener el número de columnas de la matriz
        int cols() const {
            return cols_;
        }
    };
    istream &operator>> (istream &in, matrix& m);
}
#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
