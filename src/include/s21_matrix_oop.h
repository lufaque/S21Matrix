#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <iostream>
#include <stdlib.h>


class S21Matrix {
private:
    int rows_ = 0;
    int columns_ = 0;
    double **_matrix = NULL;
    void copy(const S21Matrix *other);
    void swap(S21Matrix &other) noexcept;

public:
    S21Matrix() noexcept;

    S21Matrix(const int rows, const int columns);

    S21Matrix(const S21Matrix &other) noexcept;

    S21Matrix(S21Matrix &&other) noexcept;

    ~S21Matrix() noexcept;

    bool EqMatrix(const S21Matrix &other);

    void SumMatrix(const S21Matrix &other);

    void print(void);

    void setRows(const int rows);

    void setColumns(const int columns);

    int getRows(void);

    int getColumns(void);
};

#endif // S21_MATRIX_OOP_H