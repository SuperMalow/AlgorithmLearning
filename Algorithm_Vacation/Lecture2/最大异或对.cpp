/**
 * @file 单调队列.cpp
 * @author pengshengwen (pengshengwen.cn)
 * @brief 
 * @version 0.1
 * @date 2021-08-12
 * 
 * @copyright Copyright (c) 2021
 * @class Trie字符串统计-练习题
 */

/*
    sample input:
    3
    1 2 3
    sample output:
    3
*/

#include <iostream>
#include <algorithm>

using namespace std;

// N 数据范围 M为son最多能多少个分支
const int N = 100010, M = 31 * N;
// son表示叶节点 a为存储输入的数据
int son[M][2], a[N];
// idx创建空子节点的路线
int idx;

// 插入操作
void insert(int x)
{
    int p = 0; // 创建根节点
    for (int i = 30; i >= 0; i--) // 从30位开始 也就是从高位开始存
    {
        // 让i也从30位开始，这里是右移i位
        int u = x >> i & 1;
        // 如果为空节点就创建一个
        if (!son[p][u])
            son[p][u] = ++idx;
        // 接着走
        p = son[p][u];
    }
}

// 查询操作
int query(int x)
{
    // 创建根节点 res为输出的数(最配的那个数)
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) // 从高位开始
    {
        // 让x也从高位开始
        int u = x >> i & 1;
        // 找到与输入的数x最为相配的数
        if (son[p][!u])
        {
            p = son[p][!u];
            // res = res * 2 + !u;
            res = (res << 1) + !u;
        }
        else 
        {
            p = son[p][u];
            // res = res * 2 + u;
            res = (res << 1) + u;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        insert(a[i]);

        int t = query(a[i]);
        res = max(res, a[i] ^ t);
    }

    cout << res << endl;

    return 0;
}