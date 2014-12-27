#include "matrix.h"

using namespace std;

int main()
{
    Matrix a(3, 3), b(3, 3), c(3, 3);
    cin >> a;
    c = (a * a);
    cout << c << "\n";
    cin >> b;
    cout << b << (c - b);
    return 0;
}

