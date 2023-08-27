#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) {
    if (other.rows_ != this->rows_) return false;
    if (other.columns_ != this->columns_) return false;

    for (int i = 0; i < this->rows_; i++) {
        for (int k = 0; k < this->columns_; k++) {
            if (this->matrix_[i][k] != other.matrix_[i][k]) return false;
        }
    }

    return true;
}