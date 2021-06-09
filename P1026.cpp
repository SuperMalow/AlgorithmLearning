/*
        P1026 最大矩形面积勾勒
        描述
        度度熊碰到了一道难题：现在有n个紧密连接的矩形，它们拥有着相同的宽度，都为1，但是高度却不一定相同，用一个非负整数数组来表示它们各自的高度。求在该组矩形中，能够勾勒出来的矩形的最大面积。

        例如：
        输入：n=6, heights = [2,1,5,6,2,3]
        输出：res=10
        解释：可以发现在高度为5和6的两个矩形基础上进行勾勒，可以勾勒出1个宽度为2，高度为5的矩形，其面积为10，为该组矩形所能勾勒出的最大矩形。

        格式
        输入格式
        int n int n1 int n2....
        输出格式
        int res

        样例
        输入样例
        6 2 1 5 6 2 3
        输出样例
        10

        限制
        时间限制: 1000 ms
        内存限制: 65535 KB

*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

//l[i], r[i]表示第i个矩形的高度可向两侧扩展的左右边界
int h[N], q[N], l[N], r[N];

typedef long long LL;

int main()
{
    int n;
    while (scanf("%d", &n), n)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        h[0] = h[n + 1] = -1;

        int tt = -1;
        q[++tt] = 0;
        for (int i = 1; i <= n; i++)
        {
            while (h[q[tt]] >= h[i])
                tt--;
            l[i] = i - q[tt];
            q[++tt] = i;
        }

        tt = -1;
        q[++tt] = n + 1;
        for (int i = n; i; i--)
        {
            while (h[q[tt]] >= h[i])
                tt--;
            r[i] = q[tt] - i;
            q[++tt] = i;
        }

        LL res = 0;
        for (int i = 1; i <= n; i++)
            res = max(res, (LL)h[i] * (l[i] + r[i] - 1));
        printf("%lld\n", res);
    }
    return 0;
}
