//
// Created by rudri on 3/23/2022.
//

#include "matrix.h"
using namespace utec;
using namespace std;

Matrix::Matrix(int rows, int cols){
    // Asignar memoria dinámica para la matriz
    values = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        values[i] = new int[cols_];
    }
}

int main(){
    
}