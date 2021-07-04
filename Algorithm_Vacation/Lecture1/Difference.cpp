/*
    题目
        输入一个长度为 n 的整数序列。
        接下来输入 m 个操作，每个操作包含三个整数 l,r,c，表示将序列中 [l,r] 之间的每个数加上 c。
        请你输出进行完所有操作后的序列。
    输入格式
        第一行包含两个整数 n 和 m。
        第二行包含 n 个整数，表示整数序列。
        接下来 m 行，每行包含三个整数 l，r，c，表示一个操作。
    输出格式
        共一行，包含 n 个整数，表示最终序列。
    数据范围
        1≤n,m≤100000,
        1≤l≤r≤n,
        ?1000≤c≤1000,
        ?1000≤整数序列中元素的值≤1000
*/
#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N], b[N];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        insert(i, i, a[i]);
    }

    while (m --)
    {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    
    for (int i = 1; i <= n; i ++ )
    {
        a[i] = a[i - 1] + b[i];
        cout << a[i] << " ";
    }

    return 0;
}