#include <iostream>
using namespace std;

int to_gray_in_dec(int bin)
{
    return bin ^ (bin >> 1);
}

int to_bin(int num)
{
    int bin = 0, k = 1;
    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }
    return bin;
}

int main()
{
    int b = 4;
    int B[b] = {4, 5, 6, 7};
    int B_temp[b] = {};
    for (int i = 0; i < b; i++)
    {
        B_temp[i] = to_gray_in_dec(B[i]);
    }
    cout << "binary Gray code for B equals: "
         << "\n";
    for (int i = 0; i < b; i++)
    {
        cout << to_bin(B_temp[i]) << "\n";
    }
}