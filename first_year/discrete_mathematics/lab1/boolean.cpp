#include <iostream>
using namespace std;

int *to_array(int num)
{
    static int arr[5] = {0};
    for (int i = 4; i >= 0, num != 0; i--)
    {
        if (num % 2 == 0)
        {
            arr[i] = 0;
        }
        else
        {
            arr[i] = 1;
        }
        num /= 2;
    }
    return arr;
}

main()
{
    int bin, n = 5;
    int A[n] = {1, 2, 3, 4, 5};
    int *bin_code;
    cout << "boolean A equals: "
         << "\n";
    cout << "{ ";
    for (int j = 0; j <= 31; j++)
    {
        int *bin_code = to_array(j);
        cout << "{";
        for (int i = 0; i <= 4; i++)
        {
            if (bin_code[i] == 1)
            {
                cout << A[i];
            }
            else
                continue;
        }
        cout << "} ";
    }
    cout << "}"
         << "\n";
}