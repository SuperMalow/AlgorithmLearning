#include <iostream>

using namespace std;

const int N = 100010;

int n, k;
int q[N];

int quick_sort_apply(int l, int r, int k)
{
    if (l == r)
    {
        return q[l];
    }
    // 1. 确定分界点x
    int x = q[l + r >> 1];
    // 2. 划分边界 l r
    int i = l - 1, j = r + 1;

    while (i < j)
    {
        while (q[++i] < x)
            ;
        while (q[--j] > x)
            ;
        if (i < j)
        {
            swap(q[i], q[j]);
        }
    }
    // 3. 递归
    int sl = j - l + 1;
    if (k <= sl)
    {
        return quick_sort_apply(l, j, k);
    }
    return quick_sort_apply(j + 1, r, k - sl);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    cout << quick_sort_apply(0, n - 1, k);
    return 0;
}