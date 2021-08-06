/**
 * @file 双链表.cpp
 * @author pengshengwen (pengshengwen.cn)
 * @brief 
 * @version 0.1
 * @date 2021-08-06
 * 
 * @copyright Copyright (c) 2021
 * @class 算法模版题-双链表
 * 
 */

/*
    sample input:
    10
    R 7
    D 1
    L 3
    IL 2 10
    D 3
    IL 2 7
    L 8
    R 9
    IL 4 7
    IR 2 2

    sample output:
    8 7 7 3 2 9
*/

#include <iostream>
#include <string>

using namespace std;

// 数据范围1≤M≤100000
const int N = 100010;

// e[i]是i节点的值
// l[i]是i节点左边指针
// r[i]是i节点右边指针
// idx是当前点的位置
int e[N], l[N], r[N], idx;

void init()
{
    // 0 1
    // 1 0  左右节点
    r[0] = 1, l[1] = 0;
    // 故idx从2开始因为有了上述俩个点
    idx = 2;
}

// 是在k位置后添加节点x
// 需要k + 1
void add(int k, int x)
{
    //        <简略图>
    //      k        r[k]
    //       \      /
    //           o
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx++;
}

// 是在k位置后添加节点x
// 需要k + 1
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    int m, k, x;
    string op;

    cin >> m;
    init();
    while (m--)
    {
        cin >> op;
        if (op == "L")
        {
            cin >> x;
            add(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            add(l[1], x);
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else if (op == "IR")
        {
            cin >> k >> x;
            add(k + 1, x);
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k + 1);
        }
    }
    for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
    cout << endl;

    return 0;
}