#include <iostream>

using namespace std;
/*
        输入格式
        输入共两行，第一行包含整数 n。

        第二行包含 n 个整数（所有整数均在 1∼109 范围内），表示整个数列。

        输出格式
        输出共一行，包含 n 个整数，表示排好序的数列。

        数据范围
        1≤n≤100000
        输入样例：
        5
        3 1 2 4 5
        输出样例：
        1 2 3 4 5
*/
const int N = 100010;

int n;
int q[N], temp[N];

void merge_sort(int q[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    // 中点 下标
    int mid = l + r >> 1;

    //递归
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    // 归并
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) // 分为两个数组进行一一对比，i和j分别两数组的指针
    {
        if (q[i] <= q[j])
        {
            temp[k++] = q[i++];
        }
        else
        {
            temp[k++] = q[j++];
        }
    }
    // 扫尾
    while (j <= r)
    {
        temp[k++] = q[j++];
    }
    while (i <= mid)
    {
        temp[k++] = q[i++];
    }

    // 拷贝到原来的地方去
    for (int i = l, j = 0; i <= r; i++, j++)
    {
        q[i] = temp[j];
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }

    merge_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", q[i]);
    }

    return 0;
}