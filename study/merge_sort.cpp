#include <iostream>

using namespace std;

const int N = 1000010;

int n;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    //  先找mid中心点 且是下标的中心点
    int mid = (l + r) >> 1; // 等价于 (l + r) / 2
    //  再递归
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    //  再归并 合二为一
    int k = 0, i = l, j = mid + 1; // k表示我们的tmp里面有多少个数了
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
        {
            tmp[k++] = q[i++];
        }
        else
            tmp[k++] = q[j++];
    //上面的循环被打破了 也就是i或者j停下来了
    while (j <= r) // 这里是i到最右边了
    {
        // 把j剩下的元素合并到tmp上面
        tmp[k++] = q[j++];
    }
    while (i <= mid) // 这里是j到最右边了
    {
        // 把i剩下的元素合并到tmp上面
        tmp[k++] = q[i++];
    }

    // 把tmp的元素全部拷贝到q里面
    for (int i = l, j = 0; i <= r; i++, j++)
    {
        q[i] = tmp[j];
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