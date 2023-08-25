#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <iostream>

class S21Matrix {
private:
    int _rows = 0;
    int _columns = 0;
    double **_matrix = NULL;

public:
    S21Matrix();

    S21Matrix(const int rows, const int columns);

    ~S21Matrix();

    bool EqMatrix(const S21Matrix &other);

    void print(void);
};

#endif // S21_MATRIX_H