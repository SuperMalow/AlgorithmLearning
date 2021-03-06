/*
    题目
    节能主义者小度沉迷于Windows自带的画图软件。 他先画出了N个格子，并把它们标号为1~N。刚开始时每一个格子都是白色的。 然后，小度选择了喷桶工具，想要把尽量少的格子喷成黑色的。 黑色太少了就不美观了，对此，小度给出了两种要求。 第一种要求一共有M1个，每一个形如（L,R,K），意思是L~R这些格子中黑色格子不能少于K个。 第二种要求一共有M2个，每一个形如（L,R,K），意思是除了L~R这些格子的剩余格子中黑色格子不能少于K个。 请帮小度计算出，在满足所有要求的情况下，最少要把多少个格子涂黑。
    格式
        输入格式
        有多组数据，读到EOF结束。 对于每一组数据，第一行读入三个数N，M1和M2。(1<=N<=1000,0<=M1,M2<=500) 接下来先是M1行，每行三个数（L,R,K）。K<=R-L+1 接下来再是M2行，每行三个数（L,R,K）。K<=N-(R-L+1) 数据组数<=100。 N,M1,M2中至少有一个大于100的数据最多只有四组。
    输出格式
        对于每组数据输出一行，表示答案。
    输入样例
        3 1 1
        1 2 1
        2 2 1
    输出样例
        1

    时间 2021年7月6日 21点54分 
*/
#include <iostream>
using namespace std;

const int N = 1010;
int n, m1, m2;
int l, r, k;
int a[N];

int main()
{
    while (~scanf("%d%d%d", &n, &m1, &m2))
    {
        scanf("%d%d%d", &l, &r, &k);
        if (r - l + 1 >= k) // M1
        {
            for (int i = l; i <= r + 1; i ++ )
            {
                a[i] ++;
            }
        }
        scanf("%d%d%d", &l, &r, &k);
        if (n - (r - l + 1) >= k) //M2
        {
            for (int i = 1; i < l; i ++ )
            {
                a[i] ++;
            }
            for (int i = r + 1; i <= n; i ++ )
            {
                a[i] ++;
            }
        }

        for (int i = 1, res = 0; i < n; i ++ )
        {
            while (a[i] > 1) 
            {
                res --;
            }
            res ++ ;
            cout << res << endl;
        }
    }

    return 0;
}