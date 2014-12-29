#include "matrix.h"

using namespace std;

int main()
{
    Matrix a = {3, 3, 3, 5, 7, 5, -8, 11, 45, 111, 10}, b = {3, 3, 0, 7, 2, -3, 11, 4, -45, 7, 1};
    cout << "\nA : " << a << "\nB : " << b << "\nA * B : " << (b * a);
    return 0;
}

