#include "example.h"

S21Matrix::S21Matrix() {
    rows_ = 3;
    _cols = 3;
    // that is how memory allocation works in C++
    _p = new double[rows_ * _cols]();
}

/* : <attribute_name>(value) syntax helps to automatically fill attributes with 
values */
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), _cols(cols) {
    _p = new double[rows_ * _cols]();
}

S21Matrix::S21Matrix(const S21Matrix &o) : rows_(o.rows_), _cols(o._cols) {
    _p = new double[o.rows_ * o._cols]();
    /* standard cpp function: copies memory of o.rows_ * o._cols * sizeof(double)
    from o.p pointer to _p pointer */
    std::memcpy(_p, o._p, o.rows_ * o._cols * sizeof(double));
}

S21Matrix::S21Matrix(CMatrix &&o) {
    if (rows_ * _cols == o.rows_ * o._cols) {
        std::memcpy(_p, o._p, o._cols * o.rows_ * sizeof(double));
    } else {
        delete[] m_ptValues;
        _p = new double[o.rows_ * o._cols]();
        std::memcpy(_p, o._p, o._cols * o.rows_ * sizeof(double));
    }
    rows_ = o.rows_;
    _cols = o._cols;
    delete o._p;
    o.rows_ = 0;
    o._cpls = 0;
}

S21Matrix::~S21Matrix() {
    if (_p) {
        // free
        delete[] _p;
    }
}

S21Matrix::sum_matrix(const S21Matrix &o) {
    // exception throwing example
    if (rows_ != o.rows_ || _cols != o._cols) {
        throw std::out_of_range(
                "Incorrect input, matrices should have the same size");
    }
    for (auto i = 0; i < rows_ + _cols; i++) {
        _p[i] = _p[i] + o._p[i];
    }
}

// operator overload example
S21Matrix S21Matrix::operator+(const S21Matrix &o) {
    // creating result matrix
    S21Matrix res(rows_, _cols);
    res.sum_matrix(o);
    return res;
}

// index operator overload
int &CMatrix::operator()(int row, int col) {
    if (row >= rows_ || col >= _cols) {
        throw std::out_of_range("Incorrect input, index is out of range");
    }
    return _p[row * _cols + col];
}
