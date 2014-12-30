#include "matrix.h"

Matrix::Matrix():size_n(2), size_m(2), p(nullptr)
{
    this->p = new double*[size_n];
    for(unsigned i = 0; i < size_n; ++i)
    {
        this->p[i] = new double[size_m];
    }
}

/**
    First two digitals form array dimension; others form its contents
*/
Matrix::Matrix(std::initializer_list<double> list)
{
    this->size_n = (unsigned)(*(list.begin()));
    this->p = new double*[size_n];

    this->size_m = (unsigned)(*(list.begin() + 1));
    for(unsigned k = 0; k < size_n; ++k)
    {
        this->p[k] = new double[size_m];
    }
    for(unsigned k = 0; k < size_n; ++k)
    {
        std::copy(list.begin() + (k * size_m) + 2, list.end(), &this->p[k][0]);
    }
}

Matrix::Matrix(unsigned rows, unsigned colomns):size_n(rows), size_m(colomns)
{
    this->p = new double*[size_n];
    for(unsigned i = 0; i < size_n; ++i)
    {
        this->p[i] = new double[size_m];
    }
}

Matrix::Matrix(unsigned rows, unsigned colomns, double **p):size_n(rows), size_m(colomns), p(p)
{
    std::copy(&p[0][0], &p[0][0] + size_n * size_m + 2, &this->p[0][0]);
}

Matrix::Matrix(const Matrix &matrix):Matrix(matrix.size_n, matrix.size_m)
{
    std::copy(&matrix.p[0][0], &matrix.p[0][0] + size_n * size_m + 2, &this->p[0][0]);
}

Matrix::Matrix(Matrix &&other):size_n(0), size_m(0), p(nullptr)
{
    size_n = other.size_n;
    size_m = other.size_m;
    p = other.p;

    other.size_n = 0;
    other.size_m = 0;
    other.p = nullptr;
}

Matrix::~Matrix()
{
    delete []p;
}

Matrix & Matrix::operator = (const Matrix & other)
{
    assert(this->size_m == other.size_m && this->size_n == other.size_n);

    for(unsigned i = 0; i < other.size_n; ++i)
    {
        for(unsigned j = 0; j < other.size_m; ++j)
        {
            this->p[i][j] = other.p[i][j];
        }
    }
    return * this;
}

Matrix & Matrix::operator += (const Matrix & other)
{
    assert(this->size_m == other.size_m && this->size_n == other.size_n);

    for(unsigned i = 0; i < this->size_n; ++i)
    {
        for(unsigned j = 0; j < this->size_m; ++j)
        {
            this->p[i][j] += other.p[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator + (const Matrix & other)
{
    assert(this->size_m == other.size_m && this->size_n == other.size_n);

    Matrix current(other.size_n, other.size_m);
    for(unsigned i = 0; i < size_n; ++i)
    {
        for(unsigned j = 0; j <size_m; ++j)
        {
            current.p[i][j] = this->p[i][j] + other.p[i][j];
        }
    }
    return current;
}

Matrix & Matrix::operator *= (const Matrix & other)
{
    assert(this->size_m == other.size_n && this->size_n == other.size_m);

    Matrix result = (*this) * other;
    (*this) = result;
    return * this;
}

Matrix Matrix::operator * (const Matrix & other)
{
    assert(this->size_m == other.size_n && this->size_n == other.size_m);

    Matrix current(size_n, size_m);
    for(unsigned i = 0; i < size_n; ++i)
    {
        for(unsigned j = 0; j < size_m; ++j)
        {
            for(unsigned k = 0; k < size_n; ++k)
            {
                current.p[i][j] += this->p[i][k] * other.p[k][j];
            }
        }
    }
    return current;
}

bool Matrix::operator == (const Matrix & other)
{
    assert(this->size_m == other.size_n && this->size_n == other.size_m);

    for(unsigned i = 0; i < size_n; ++i)
    {
        for(unsigned j = 0; j < size_m; ++j)
        {
            if(this->p[i][j] != other.p[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

Matrix & Matrix::operator -=(const Matrix & other)
{
    assert(this->size_n == other.size_n && this->size_m == other.size_m);

    Matrix current = (*this) - other;
    (*this) = current;
    return *this;
}

Matrix Matrix::operator -(const Matrix & other)
{
    assert(this->size_n == other.size_n && this->size_m == other.size_m);

    Matrix current(other.size_n, other.size_m);
    for(unsigned i = 0; i < size_n; ++i)
    {
        for(unsigned j = 0; j < size_m; ++j)
        {
            current.p[i][j] = other.p[i][j] - this->p[i][j];
        }
    }
    return current;
}

std::ostream & operator << (std::ostream & out, const Matrix & obj)
{
    out << "\nRESULT : \n";
    for(unsigned i = 0; i < obj.size_n; ++i)
    {
        for(unsigned j = 0; j < obj.size_m; ++j)
        {
            out << obj.p[i][j] << "\t";
        }
        out << "\n";
    }
    return out;
}

std::istream & operator >> (std::istream & in, const Matrix & obj)
{
    for(unsigned i = 0; i < obj.size_n; ++i)
    {
        for(unsigned j = 0; j < obj.size_m; ++j)
        {
            in >> obj.p[i][j];
        }
    }
    return in;
}


