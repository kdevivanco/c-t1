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
        int** values; // Puntero a puntero para representar la matriz dinámica
        int rows_; // Número de filas de la matriz
        int cols_; // Número de columnas de la matriz

    public:
        // Constructor por parámetros
        matrix(int rows, int cols);

        // Destructor
        ~matrix() {
            // Liberar la memoria dinámica de la matriz
            for (int i = 0; i < rows_; ++i) {
                delete[] values[i];
            }
            delete[] values;
        }

        int getRows(){
            return this->rows_;
        }

        // Sobrecarga de operador para acceder a los elementos de la matriz
        int& operator()(int row, int col) {
            return values[row][col];
        }

        matrix& operator=(const matrix& other);


        // Sobrecarga de operador para imprimir la matriz
        friend ostream& operator<<(ostream& out, const matrix& m) {
            for (int i = 0; i < m.rows_; ++i) {
                for (int j = 0; j < m.cols_; ++j) {
                    out << setw(4) << m.values[i][j] << " "; // Espacio de 4 caracteres para cada elemento
                }
                out << endl;
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
}
#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
