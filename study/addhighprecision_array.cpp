/*
        给定两个正整数，计算它们的和。
        输入格式
        共两行，每行包含一个整数。
        输出格式
        共一行，包含所求的和。
        数据范围
        1≤整数长度≤100000
        输入样例：
        12
        23
        输出样例：
        35
*/
#include <iostream>
using namespace std;

const int N = 100010;
int A[N], B[N], C[N];

int add(int A[], int B[], int C[], int cnt)
{
    int t = 0;

    for (int i = 0; i <= cnt; i++)
    {
        t += A[i] + B[i];
        C[i] = t % 10;
        t /= 10;
    }
    if (t)
    {
        C[++cnt] = 1;
    }
    return cnt;
}

int main()
{
    string a, b;
    cin >> a >> b;

    int A_cnt = 0, B_cnt = 0;
    for (int i = a.size() - 1; i >= 0; i--)
        A[++A_cnt] = a[i] - '0';

    for (int i = b.size() - 1; i >= 0; i--)
        B[++B_cnt] = b[i] - '0';

    int C_cnt = add(A, B, C, max(A_cnt, B_cnt));

    for (int i = C_cnt; i >= 1; i--)
        cout << C[i];

    return 0;
}