#include <iostream>
using namespace std;

int n, m1, m2;
int l, r, k;

int main()
{
    while (~scanf("%d%d%d", &n, &m1, &m2))
    {
        int res = 0;
        scanf("%d%d%d", &l, &r, &k); // M1
        if (r - l + 1 >= k && k >= m1 && m1 >= 0)
        {
            res += m1;
        }
        scanf("%d%d%d", &l, &r, &k); // M2
        if (n - (r - l + 1) >= k && m2 >= k  && m2 <= 500)
        {
            res += m2;
        }
        cout << res << endl;
    }

    system("pause");
    return 0;
}