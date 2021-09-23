#include <iostream>
using namespace std;

main()
{
    int A[5] = {1, 2, 3, 4, 5}, a = 5;
    int B[4] = {4, 5, 6, 7}, b = 4;
    cout << "{";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "(" << A[i] << "," << B[j] << ")";
        }
    }
    cout << "}"
         << "\n";
    cout << "Power equals " << a * b << "\n";
}