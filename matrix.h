#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <ostream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

class Matrix
{
private:
    double **p;
    size_t size_n = 2;
    size_t size_m = 2;
public:
    Matrix();
    Matrix(unsigned rows, unsigned colomns);
    Matrix(double **p);
    Matrix(const Matrix & matrix);
    Matrix(Matrix && other);
    ~Matrix();

    Matrix & operator += (const Matrix & other);
    Matrix operator + (const Matrix & other);
    Matrix & operator *= (const Matrix & other);
    Matrix operator * (const Matrix & other);
    bool operator == (const Matrix & other);
    Matrix & operator = (const Matrix & other);
    Matrix & operator -= (const Matrix & other);
    Matrix operator - (const Matrix & other);

    friend std::ostream & operator << (std::ostream & out, const Matrix & obj);
    friend std::istream & operator >> (std::istream & in, const Matrix & obj);
};

#endif // MATRIX_H
