#include <iostream>

using namespace std;

const int N = 100010;
int A[N], B[N], C[N];

int getarraylen(int *A)
{
    int len = sizeof(A) / sizeof(int);
    return len;
}
int *add(int A[], int B[])
{
    int A_len = getarraylen(A);
    int B_len = getarraylen(B);
    if (A_len < B_len)
    {
        return (B, A);
    }
    int t = 0;
    for (int i = 0; i < A_len; i++)
    {
        int j = 0;
        t += A[i];
        if (i < B_len)
        {
            t += B[i];
        }
        C[j] = t % 10;
        j++;
        t /= 10;
    }

    if (t)
    {
        int C_len = getarraylen(C);
        C[C_len - 1] = t;
    }
    return C;
}
int main()
{
    string a, b;
    cin >> a >> b; // a = "1234567"
    for (int i = a.size() - 1, j = 0; i >= 0; i--, j++)
    { // A = "7654321"
        A[j] = a[i] - '0';
    }
    for (int i = b.size() - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = a[i] - '0';
    }
    auto C = add(A, B);
    int C_len = getarraylen(C);
    for (int i = C_len - 1; i >= 0; i--)
    {
        cout << C[i];
    }
}