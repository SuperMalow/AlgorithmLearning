#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int h[N], q[N], l[N], r[N];
typedef long long LL;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &h[i]);
        }
        h[0] = h[n + 1] = -1;

        int t = -1;
        q[++t] = 0;
        for (int i = 1; i <= n; i++)
        {
            while (h[q[t]] >= h[i])
            {
                t--;
            }
            l[i] = i - q[t];
            q[++t] = i;
        }
        t = -1;
        q[++t] = n + 1;
        for (int i = n; i; i--)
        {
            while (h[q[t]] >= h[i])
            {
                t--;
            }
            r[i] = q[t] - i;
            q[++t] = i;
        }

        LL res = 0;
        for (int i = 1; i <= n; i++)
        {
            res = max(res, (LL)h[i] * (l[i] + r[i] - 1));
        }
        printf("%lld\n", res);
        system("pause");
        return 0;
    }
}