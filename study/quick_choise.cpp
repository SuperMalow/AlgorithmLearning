#include <iostream>
using namespace std;

const int N = 100010;
int n, k;
int q[N];

//  输入样例
//  5 3
//  2 4 1 5 3

int quick_choice(int l, int r, int k)
{ // 全局变量与局部变量重名时 会使用局部变量
    if (l == r)
    {
        //说明长度只有1个 即为答案
        return q[l];
    }
    int x = q[l], i = l - 1, j = r + 1;
    while (i < j)
    { //快排
        while (q[++i] < x)
            ;
        while (q[--j] > x)
            ;
        if (i < j)
        {
            swap(q[i], q[j]);
        }
    }
    //递归
    int sl = j - l + 1;
    if (k <= sl)
    {
        //递归左边
        return quick_choice(l, j, k);
    }
    return quick_choice(j + 1, r, k - sl);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }

    cout << quick_choice(0, n - 1, k) << endl;

    return 0;
}