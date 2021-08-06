/**
 * @file 单链表.cpp
 * @author pengshengwen (pengshengwen.cn)
 * @brief 
 * @version 0.1
 * @date 2021-08-06
 * 
 * @copyright Copyright (c) 2021
 * @class 算法模版题-单链表
 * 
 */

/*
    sample input:
    10
    H 9
    I 1 1
    D 1
    D 0
    H 6
    I 3 6
    I 4 5
    I 4 5
    I 3 4
    D 6

    sample output:
    6 4 6 5
*/

#include <iostream>
using namespace std;

// 数据范围1≤M≤100000
const int N = 100010;

// head表示头节点
// idx表示当前点的位置
// e[i]表示i位置的值
// ne[i]表示i位置的指针
int head, idx, e[N], ne[N];

// 初始化
void init()
{
    head = -1;
    idx = 0;
}

// 添加值在头节点(头插法)
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

//  在k下标的节点后添加x
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

// 删除k下标的节点
void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m, k, x;
    char op;

    cin >> m;

    init();

    while (m--)
    {
        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'I')
        {
            cin >> k >> x;
            // 因为数组存的下标是从0开始
            add(k - 1, x);
        }
        else if (op == 'D')
        {
            cin >> k;
            // 如果要删除的是头节点，也就是头节点后一个节点，那就把头节点这个箭头指向下一个位置
            if (!k)
                head = ne[head];
            else
                // 因为数组存的下标是从0开始
                remove(k - 1);
        }
    }
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << " ";
    cout << endl;

    return 0;
}