//  学习算法的第一天 2021.06.09  Supermalow

//  快排

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r) //防止边界出问题
    {
        return;
    }
    int x = q[l];  //可以设为l r (l+r)/2 也可以随机
    int i = l - 1; //因为后续用了do-while结构，我们是先进行指针+1再进行比较
    int j = r + 1; //所以存在一个边界问题

    while (i < j)
    {
        do
            ++i;
        while (q[i] < x);
        do
            --j;
        while (q[j] > x);
        if (i < j) //这是i跟j停下了的意思
        {          //且如果停下了而且i<j那么交换下值
                   //如果停下了 然后i没有满足<j 即为这一次迭代结束
            swap(q[i], q[j]);
        }
    }
    // 1.当 quick_sort(q,l,i-1);
    // quick_sort(q,i,r);时  上面的x = q[l]不能取  只能取 x = q[(l + r + 1) / 2] 和 x = q[r] 不然会出现边界问题造成死循环

    // 2. 当 quick_sort(q,l,j);
    // quick_sort(q,j + 1,r);时  上面的x = q[r] 不能取 只能取 x = q[(l + r + 1) / 2] 和 x = q[l]
    quick_sort(q, l, j);     //此时l    为下一个q1的区间的左边界 j为右边界
    quick_sort(q, j + 1, r); //此时j+1为下一个q2的的左边界 r为右边界
}

// 输入样例
// 5
// 2 1 3 2 5
// 输出 1 2 2 3 5
int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &q[i]);
    }

    quick_sort(q, 0, n - 1);

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", q[i]);
    }

    return 0;
}