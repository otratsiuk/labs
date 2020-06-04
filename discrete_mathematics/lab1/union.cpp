#include <iostream>
using namespace std;

int main()
{
    int B[] = {1, 2, 3, 4, 5};
    int C[] = {3, 5, 7, 8};
    int b = 5, c = 4, n = 0;
    int *interflow = new int[b + c - n];
    int i = 0, j = 0;
    for (int f = 0; f < b + c; f++)
    {
        if (i > b - 1)
        {
            int c_temp = C[j];
            interflow[f] = c_temp;
            j++;
        }
        else if (j > c - 1)
        {
            int b_temp = B[i];
            interflow[f] = b_temp;
            i++;
        }
        else if (B[i] < C[j])
        {
            int b_temp = B[i];
            interflow[f] = b_temp;
            i++;
        }
        else if (B[i] > C[j])
        {
            int c_temp = C[j];
            interflow[f] = c_temp;
            j++;
        }
        else if (B[i] == C[j])
        {
            f--;
            j++;
            n++;
        }
    }
    cout << "result of interflow equals: "
         << "\n";
    for (int i = 0; i < b + c - n; i++)
    {
        cout << interflow[i] << " ";
    }
    cout << "\n";
}