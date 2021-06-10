#include <iostream>

using namespace std;

// 输入样例：
// 6
// 2 3 4 5 6 1

// 输出样例：
// 5

typedef long long LL;

const int N = 100010;

int n;
int q[N], temp[N];

LL merge_sort_apply(int l, int r)
{
    if (l >= r)
    {
        return 0;
    }
    // 找中间值
    int mid = l + r >> 1; // +运算符比>>要高

    // 递归  并且这两种刚好属于是 1 2 类型
    LL res = merge_sort_apply(l, mid) + merge_sort_apply(mid + 1, r);

    // 归并 合二为一
    int k = 0, i = l, j = mid + 1; // 记录temp的数量
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
        {
            temp[k++] = q[i++];
        }
        else
        {
            temp[k++] = q[j++];
            res += mid - i + 1;
        }
    }
    // 当i或者j停下来了进行接尾
    // 扫尾
    while (j <= r)
    {
        temp[k++] = q[j++];
    }
    while (i <= mid)
    {
        temp[k++] = q[i++];
    }

    // 物归原主
    for (int i = l, j = 0; i <= r; i++, j++)
    {
        q[i] = temp[j];
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }

    cout << merge_sort_apply(0, n - 1);

    return 0;
}