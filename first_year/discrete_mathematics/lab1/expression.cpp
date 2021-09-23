#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a = 5, b = 4, c = 4, u = 11;
    int A[a] = {1, 2, 3, 4, 5};
    int B[b] = {4, 5, 6, 7};
    int C[c] = {3, 5, 7, 8};
    int U[u] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int mask_A[u] = {0}, mask_B[u] = {0}, mask_C[u] = {0}, mask_U[u] = {0};
    int A_addition[u - a];
    int mask_A_addition[11] = {0};
    int mask_union_of_BC[11] = {0};
    int bc = 0;
    int *union_of_BC = new int[bc];
    int expr = 0;
    int *expression = new int[expr];
    for (int j = 0, i = 0; j < u; j++)
    {
        if (A[i] == U[j])
        {
            mask_A[j] = 1;
            i++;
        }
        else
            continue;
    }
    for (int i = 0, j = 0; i < u; i++)
    {
        if (mask_A[i] == 0)
        {
            A_addition[j] = U[i];
            j++;
        }
    }
    cout << "mask_A equals: "
         << "\n";
    for (int i = 0; i < 11; i++)
    {
        cout << mask_A[i] << " ";
    }
    cout << "\n";
    cout << "A_addition equals: "
         << "\n";
    for (int i = 0; i < u - a; i++)
    {
        cout << A_addition[i] << " ";
    }
    cout << "\n";
    for (int j = 0, i = 0; j < u; j++)
    {
        if (B[i] == U[j])
        {
            mask_B[j] = 1;
            i++;
        }
        else
            continue;
    }
    for (int j = 0, i = 0; j < u; j++)
    {
        if (C[i] == U[j])
        {
            mask_C[j] = 1;
            i++;
        }
        else
            continue;
    }
    for (int i = 0; i < u; i++)
    {
        if (mask_B[i] | mask_C[i])
        {
            mask_U[i] = 1;
            bc++;
        }
    }
    cout << "mask of union B and C equals: "
         << "\n";
    for (int i = 0; i < u; i++)
    {
        cout << mask_U[i] << " ";
    }
    cout << "\n";
    for (int i = 0, j = 0; i < u; i++)
    {
        if (mask_U[i] == 1)
        {
            union_of_BC[j] = U[i];
            j++;
        }
        else
            continue;
    }
    cout << "union of B and C equals: "
         << "\n";
    for (int i = 0; i < bc; i++)
    {
        cout << union_of_BC[i] << " ";
    }
    cout << "\n";

    for (int j = 0, i = 0; j < u; j++)
    {
        if (A_addition[i] == U[j])
        {
            mask_A_addition[j] = 1;
            i++;
        }
        else
            continue;
    }
    for (int j = 0, i = 0; j < u; j++)
    {
        if (union_of_BC[i] == U[j])
        {
            mask_union_of_BC[j] = 1;
            i++;
        }
        else
            continue;
    }
    for (int i = 0, j = 0; i < u; i++)
    {
        if (mask_A_addition[i] == 1 && mask_union_of_BC[i] != 1)
        {
            expr++;
            expression[j] = U[i];
            j++;
        }
    }
    cout << "expression equals: "
         << "\n";
    for (int i = 0; i < expr; i++)
    {
        cout << expression[i] << " ";
    }
    cout << "\n";
}