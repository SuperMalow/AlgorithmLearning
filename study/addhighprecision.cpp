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
#include <vector>
using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
    {
        return add(B, A);
    }

    vector<int> C;
    int t = 0;

    for (int i = 0; i < A.size(); i++)
    {
        t += A[i]; // A的位数大于B的位数
        if (i < B.size())
        {
            t += B[i];
        }
        C.push_back(t % 10); // 整除，如果大于即取其个位
        t /= 10;             // 本身还要除以10
    }
    if (t) // 判断A B 前面位数都为0 但是t如果有进位的话就进行储存这个进位
    {
        C.push_back(t);
    }
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;                          // a="1234567"
    for (int i = a.size() - 1; i >= 0; i--) // 为什么要-1 是因为这个a.size()是返回的我们知道的长度 但在数组里需要-1
    {
        A.push_back(a[i] - '0'); // A = [7, 6, 5, 4, 3, 2, 1]
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        B.push_back(b[i] - '0');
    }

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i--)
    {
        printf("%d", C[i]);
    }

    return 0;
}