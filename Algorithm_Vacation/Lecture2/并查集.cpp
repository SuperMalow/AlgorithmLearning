/**
 * @file 并查集.cpp
 * @author pengshengwen (pengshengwen.cn)
 * @brief 
 * @version 0.1
 * @date 2021-08-18
 * 
 * @copyright Copyright (c) 2021
 * @class 算法模版题-并查集
 */

/*
    sample input:
    4 5
    M 1 2
    M 3 4
    Q 1 2
    Q 1 3
    Q 3 4
    sample output:
    Yes
    No
    Yes
*/
#include <iostream>

using namespace std;

// 数据范围
const int N = 100010;

// 表示x的父节点(每个元素父节点是谁)
// p[x] = x 就为树根
int p[N];

// 返回x的祖宗节点(根节点编号) + 路径压缩(最后x指向根节点)
// 返回x所在集合的编号
int find(int x)
{
    // 如果p[x]不是x的树根 则让其父节点等于其祖宗节点
    // 就是找祖宗节点，祖宗节点即为其编号
    if (p[x] != x)
        p[x] = find(p[x]);
    // 最后返回祖宗节点
    return p[x];
}

int main()
{
    int n, m;
    // n表示n个数字 m表示操作次数
    cin >> n >> m;
    // p[x] = x 就为树根(祖宗节点) 初始化也就是p[i] = i
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    while (m--)
    {
        int a, b;
        char op[2];
        // 读入操作
        cin >> op >> a >> b;
        // 合并集合操作
        if (op[0] == 'M')
            // 让a的父节点等于b的祖宗编号
            // 相当于a插入到b 成为了b的叶子结点
            p[find(a)] = find(b);
        else
        {
            // 判断是否为一个集合
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}