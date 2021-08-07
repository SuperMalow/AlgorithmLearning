/**
 * @file 模拟队列.cpp
 * @author pengshengwen (pengshenwen.cn)
 * @brief 
 * @version 0.1
 * @date 2021-08-07
 * 
 * @copyright Copyright (c) 2021
 * @class 算法模版题-模拟队列
 * 
 */

/*
    sample input:
    10
    push 6
    empty
    query
    pop
    empty
    push 3
    push 4
    pop
    query
    push 6

    sample output:
    NO
    6
    YES
    4
*/

#include <iostream>

using namespace std;

const int N = 100010;
int q[N], hh, tt = -1;

// push 向队尾插入一个数 x
void push(int x)
{
    q[++tt] = x; // 队尾开始添加元素
}

// pop 从队头弹出一个数
void pop()
{
    hh++; // 队头向后移动就为删除队头
}

// query  查询队头元素
int query()
{
    return q[hh]; // 返回队头的值
}

// empty 判断队列是否为空
int empty()
{
    // 建议画图看
    if (hh <= tt)
        return 0; // 不为空
    else
        return 1; // 为空 默认tt = -1
}

int main()
{
    int m, x;
    string s;
    cin >> m;
    while (m--)
    {
        cin >> s;
        if (s == "push")
        {
            cin >> x;
            push(x);
        }
        else if (s == "pop")
        {
            pop();
        }
        else if (s == "query")
        {
            cout << query() << endl;
        }
        else if (s == "empty")
        {
            if (empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
