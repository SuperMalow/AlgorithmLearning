/*
        给定一个按照升序排列的长度为 n 的整数数组，以及 q 个查询。
        对于每个查询，返回一个元素 k 的起始位置和终止位置（位置从 0 开始计数）。
        如果数组中不存在该元素，则返回 -1 -1。
        输入格式
        第一行包含整数 n 和 q，表示数组长度和询问个数。
        第二行包含 n 个整数（均在 1∼10000 范围内），表示完整数组。
        接下来 q 行，每行包含一个整数 k，表示一个询问元素。
        输出格式
        共 q 行，每行包含两个整数，表示所求元素的起始位置和终止位置。
        如果数组中不存在该元素，则返回 -1 -1。
        数据范围
        1≤n≤100000
        1≤q≤10000
        1≤k≤10000
        输入样例：
        6 3
        1 2 2 3 3 4
        3
        4
        5
        输出样例：
        3 4
        5 5
        -1 -1
*/

#include <iostream>
using namespace std;

const int N = 100010;

int n, k;
int q[N];

int main()
{
    cin >> n >> k; // n为数组的数  k为要查找几个数
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    while (k--)
    {
        int x;
        scanf("%d", &x); // 查找的k个数分别是

        int l = 0, r = n - 1; // 定义边界

        while (l < r) // 保持在边界范围内进行 且最后是l==r的
        {
            int mid = l + r >> 1; // 下标值 二分的边界
            if (q[mid] >= x)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        // 因为跳出上面的循环l<r时是l==r的情况下 输出l和r是一样的
        if (q[l] != x) // 不满足要求输出-1 -1
        {
            cout << "-1 -1" << endl;
        }
        else // 满足要求 并返回出值 l跟r值是一样的
        {
            cout << l << " "; // 因为要求输出 3 4 5 5这样的格式，故" "

            int l = 0, r = n - 1; // 再次定义边界 因为上面的循环l跟r会变动

            while (l < r)
            {
                int mid = l + r + 1 >> 1; // 再次定义二分边界
                if (q[mid] <= x)
                {
                    l = mid;
                }
                else
                {
                    r = mid - 1;
                }
            }

            cout << l << endl;
        }
    }

    return 0;
}