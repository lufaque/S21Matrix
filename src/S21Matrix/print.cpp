#include "s21_matrix_oop.h"

void S21Matrix::print(void) {
  std::cout << "Matrix:" << std::endl;
  std::cout << "Rows: " << rows_ << std::endl;
  std::cout << "Columns: " << columns_ << std::endl;

  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < columns_; k++) {
      std::cout << matrix_[i][k] << " ";
    }
    std::cout << std::endl;
  }
}