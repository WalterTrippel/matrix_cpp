#include "matrix.h"

using namespace std;

int main()
{
    double **p = new double*[3];
    for(int i = 0; i < 3; ++i)
    {
        p[i] = new double[3];
    }
    Matrix a(3, 3, p);
    cin >> a;
    cout << a;
    Matrix b = std::move(a);
    cout << b;
    return 0;
}

