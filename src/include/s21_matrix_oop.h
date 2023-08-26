#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <iostream>
#include <stdlib.h>


class S21Matrix {
private:
    int _rows = 0;
    int _columns = 0;
    double **_matrix = NULL;

    void resizeMatrix(const int rows);

public:
    S21Matrix();

    S21Matrix(const int rows, const int columns);

    S21Matrix(const S21Matrix &other) noexcept;

    S21Matrix(S21Matrix &&other) noexcept;

    ~S21Matrix();

    bool EqMatrix(const S21Matrix &other);

    void SumMatrix(const S21Matrix &other);

    void print(void);

    void setRows(const int rows);

//    void setColumns(const int columns);

    int getRows(void);

    int getColumns(void);
};

#endif // S21_MATRIX_OOP_H