/**
 * @file 单调栈.cpp
 * @author pengshengwen (pengshengwen.cn)
 * @brief 
 * @version 0.1
 * @date 2021-08-08
 * 
 * @copyright Copyright (c) 2021
 * @class 算法模版题-单调栈
 */

/*
    sample input:
    5
    3 4 2 7 5

    sample output:
    -1 3 -1 2 2
*/

#include <iostream>
using namespace std;

// 1 ≤ 数列中元素 ≤ 10^9
const int N = 100010;
int stk[N], tt;

// 1 ≤ N ≤ 105
int n;

int main()
{
    cin >> n; // 输入格式
    while (n--)
    {
        int x;
        cin >> x;                  // 读入
        while (tt && stk[tt] >= x) // 栈内有数且栈内的数大于x的 删除(出栈)
            tt--;                  // 出栈操作
        if (tt)                    // 如果栈内有数(不为空栈)
            cout << stk[tt] << ' ';
        else
            cout << -1 << ' ';

        stk[++tt] = x; // 将x入栈
    }

    return 0;
}