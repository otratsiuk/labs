#include <iostream>
#include <cmath>

using namespace std;
main()
{
    int A[5] = {1, 2, 3, 4, 5}, B[4] = {4, 5, 6, 7};
    int U[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int mask_A[11] = {0}, mask_B[11] = {0};
    for (int j = 0, i = 0; j < 11; j++)
    {
        if (A[i] == U[j])
        {
            mask_A[j] = 1;
            i++;
        }
        else
            continue;
    }
    for (int j = 0, i = 0; j < 11; j++)
    {
        if (B[i] == U[j])
        {
            mask_B[j] = 1;
            i++;
        }
        else
            continue;
    }
    for (int i = 0; i < 11; i++)
    {
        cout << mask_A[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < 11; i++)
    {
        cout << mask_B[i] << " ";
    }
    cout << "\n";
    cout << "{ ";
    for (int i = 0; i < 11; i++)
    {
        if (mask_A[i] & mask_B[i])
        {
            cout << U[i] << " ";
        }
    }
    cout << "}"
         << "\n";
}