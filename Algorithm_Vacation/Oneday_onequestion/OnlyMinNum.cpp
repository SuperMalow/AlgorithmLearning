/*
    题目
        给定一个长度为 n 的整数数组 a1,a2,…,an。
        请你找到数组中只出现过一次的数当中最小的那个数。
        输出找到的数的索引编号。
        a1 的索引编号为 1，a2 的索引编号为 2，…，an 的索引编号为 n。
    输入格式
        第一行包含整数 T，表示共有 T 组测试数据。
        每组数据第一行包含整数 n。
        第二行包含 n 个整数 a1,a2,…,an。
    输出格式
        每组数据输出一行结果，即满足条件的数的索引编号，如果不存在满足条件的数，则输出 ?1。
    数据范围
        1≤T≤2×104,
        1≤n≤2×105,
        1≤ai≤n,
        同一测试点内的所有 n 的和不超过 2×105。
    输入样例：
        6
        2
        1 1
        3
        2 1 3
        4
        2 2 2 3
        1
        1
        5
        2 3 2 4 2
        6
        1 1 5 5 4 4
    输出样例：
        -1
        2
        4
        1
        2
        -1
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200010;
int n;
int w[N], cnt[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T --)
    {
        scanf("%d", &n);
        memset(cnt, 0, (n + 1) * 4);
        for (int i = 0; i < n; i ++ )
        {
            scanf("%d", &w[i]);
            cnt[w[i]] ++;
        }
        int res = -1;
        for (int i = 0; i < n; i ++ )
        {
            if (cnt[w[i]] == 1)
            {
                if (res == -1 || w[res] > w[i]) // 排序从小到大
                {
                    res = i;
                }
            }
        }
        if (res != -1) res ++; // 数组从
        printf("%d\n", res);
    }

    return 0;
}