/**
 * @file 单调队列.cpp
 * @author pengshengwen (pengshengwen.cn)
 * @brief 
 * @version 0.1
 * @date 2021-08-12
 * 
 * @copyright Copyright (c) 2021
 * @class 算法模版题-Trie字符串统计
 */

/*
    sample input:
    5
    I abc
    Q abc
    Q ab
    I ab
    Q ab
    sample output:
    1
    0
    1
*/

#include <iostream>

using namespace std;
// 数据范围
const int N = 100010;
// son表示子节点 cnt标记是否为一个单词 idx创建空子节点的路线
int son[N][26], cnt[N], idx;
// 全局变量存储输入的字符
char str[N];

// 插入字符
void insert(char str[])
{
    int p = 0; // 创建根节点
    // 从0开始到str字符串数组‘\0’
    for (int i = 0; str[i]; i ++)
    {
        // 将26个字母映射到0～25
        int u = str[i] - 'a';
        // 如果子节点为空则创建一个
        if (!son[p][u]) son[p][u] = ++idx; // 如果子节点为空就创建一个
        // 节点
        p = son[p][u];
    }
    // 标记单词的结尾
    cnt[p] ++;
}

// 查找字符(跟插入字符无大差别)
int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}


int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        char op[2];
        cin >> op >> str;
        if (op[0] == 'I') insert(str);
        else cout << query(str) << endl;
    }

    return 0;
}
