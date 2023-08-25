#include "s21_matrix.h"

void S21Matrix::printMatrix(void) {
    for (int i = 0; i < _rows; i++) {
        for (int k = 0; k < _columns; k++) {
            std::cout << _matrix[i][k] << " ";
        }
        std::cout << std::endl;
    }
}