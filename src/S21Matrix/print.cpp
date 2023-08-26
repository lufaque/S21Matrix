#include "s21_matrix_oop.h"

void S21Matrix::print(void) {
    std::cout << "Matrix:" << std::endl;
    std::cout << "Rows: " << _rows << std::endl;
    std::cout << "Columns: " << _columns << std::endl;

    for (int i = 0; i < _rows; i++) {
        for (int k = 0; k < _columns; k++) {
            std::cout << _matrix[i][k] << " ";
        }
        std::cout << std::endl;
    }
}