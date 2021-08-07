/**
 * @file 模拟栈.cpp
 * @author pengshengwen (pengshengwen.cn)
 * @brief 
 * @version 0.1
 * @date 2021-08-07
 * 
 * @copyright Copyright (c) 2021
 * @class 算法模版题-模拟栈
 */

/*
    sample input:
    10
    push 5
    query
    push 6
    pop
    query
    pop
    empty
    push 4
    query
    empty

    sample output:
    5
    5
    YES
    4
    NO
*/

#include <iostream>

using namespace std;

const int N = 100010;
int stk[N], tt;

void push(int x)
{
    stk[++tt] = x;
}

// 删除栈顶元素,栈顶元素出栈
void pop()
{
    tt--;
}

// 是否为栈空
int emtpy()
{
    if (tt > 0)
        return 0; // 栈满
    else
        return 1; // 栈空
}

// 查询栈顶元素
int query()
{
    return stk[tt];
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
        else if (s == "empty")
        {
            if (emtpy())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (s == "query")
        {
            cout << query() << endl;
        }
    }

    return 0;
}