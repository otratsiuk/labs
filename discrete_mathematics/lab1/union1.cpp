#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int j = 0, i = 0;
    int A[4] = {1, 2, 6, 9};
    int B[5] = {2, 3, 5, 6, 7};
    int *AB = new int[9];
    for (; i < 4; i++)
    {
        if (A[i] != B[j])
        {
            AB[i] = A[i];
        }
        else
        {
            AB[i] = A[i];
            j++;
        }
    }
    cout << "j= " << j << "\n";
    cout << "i = " << i << "\n";
    for (; j < 5; j++)
    {
        for (; i >= 0;)
        {
            if (B[j] != A[i])
            {
                AB[i] = B[j];
                i--;
            }
            else
                continue;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        cout << AB[i] << " ";
    }
}