#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <ostream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>

class Matrix
{
private:
    double **p;
    size_t size_n;
    size_t size_m;
public:
    Matrix();
    Matrix(std::initializer_list<double> list);
    Matrix(unsigned rows, unsigned colomns);
    Matrix(unsigned rows, unsigned colomns, double **p);
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
