/**
 * @file 单调队列.cpp
 * @author pengshengwen (pengshengwen.cn)
 * @brief 
 * @version 0.1
 * @date 2021-08-12
 * 
 * @copyright Copyright (c) 2021
 * @class 算法模版题-单调队列
 */

/*
    sample input:
    8 3
    1 3 -1 -3 5 3 6 7
    sample output:
    -1 -3 -3 -3 3 3
    3 3 5 5 6 7
*/
#include <iostream>

using namespace std;

// 数据范围10 ^ 6
const int N = 1000010;
// n为输入数据个数  k为窗口长度
int n, k;
// a存值 q队列存下标
int a[N], q[N];

int main()
{
    // 输入样例处理
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // 取窗口最大值
    // 队列初始化
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        // 判断队头是否滑出窗口。 因为q存下标 判断其是否在i - k + 1 ~ i 区间
        // i为枚举当右端点
        if (hh <= tt && i - k + 1 > q[hh])
            // 做删除队头的操作
            hh++;
        // 窗口的最右边元素是否大于当前枚举的元素
        while (hh <= tt && a[q[tt]] >= a[i])
        {
            // 做删除队尾的操作
            tt--;
        }

        // 把i添加到队尾
        q[++tt] = i;
        // 输出样例处理 当窗口为3才输出数
        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }
    // 输出回车
    puts("");

    // 取窗口最大值 原理跟上面一样
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) // 这里 <= 跟上面唯一区别
        {
            tt--;
        }

        q[++tt] = i;
        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }
    // 输出回车
    puts("");

    return 0;
}