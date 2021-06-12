/*
        给定一个浮点数 n，求它的三次方根。

        输入格式
        共一行，包含一个浮点数 n。

        输出格式
        共一行，包含一个浮点数，表示问题的解。

        注意，结果保留 6 位小数。

        数据范围
        −10000≤n≤10000
        输入样例：
        1000.00
        输出样例：
        10.000000
*/

#include <iostream>
using namespace std;

// 浮点数的二分
int main()
{
    double n; // 输入值
    cin >> n;
    double l = -10000, r = 10000; // 定义左右边界
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2; // 定义下表的中间值
        if (mid * mid * mid >= n) // 不能使用 ^ 因为是这个是异或的意思不是次方
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    printf("%lf", l); // l和r是一样的
    return 0;
}