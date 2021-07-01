/*
        P1035 世界杯之谜
        描述
        有N对情侣相约一起看世界杯，荧幕前正好有2N个横排的位置。 所有人都会随机坐在某个位置上。 当然，如果某一对情侣正好挨着坐，他们就会有说不完的话，影响世界杯的观看。 一般地，对于一个就座方案，如果正好有K对情侣正好是挨着坐的，就会产生D^K的喧闹值。 度度熊想知道随机就座方案的期望喧闹值。 为了避免输出实数，请输出（答案*(2N)!)）mod P的值。其中P=998244353

        格式
        输入格式
        有多组数据（不超过1000组），读到EOF结束。 对于每一组数据，读入两个数N和D。 1<=N,D<=1000
        输出格式
        对于每一组数据，输出一个数表示答案。
        样例
        输入样例
        1 10
        2 3
        输出样例
        20
        104
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod=998244353;
const int N=1000;
ll dp[N+5][N+5],p[N+5];

void init()
{
    p[0] = 1ll;
    for(int i=1; i<=N; i++)
        p[i] = p[i-1] * 2ll % mod;
    dp[0][0] = 1;
    for(ll i = 1; i<=N; i++)
        for(ll j=0; j<=i; j++)
        {
            dp[i][j] += dp[i-1][j] * j % mod;
            if(dp[i][j] > mod)
                dp[i][j] -= mod;
            if(j > 0)
            {
                dp[i][j] += dp[i-1][j-1] * (2*(i-1)-(j-1)+1) % mod;
                if(dp[i][j] > mod)
                    dp[i][j] -= mod;
            }
 
            dp[i][j] += dp[i-1][j+2] * ((j+2) * (j+1) / 2) % mod;
            if(dp[i][j] > mod)
                dp[i][j] -= mod;
            dp[i][j] += dp[i-1][j+1] * (2 * (i-1) - (j+1) + 1) * (j+1) % mod;
            if(dp[i][j] > mod)
                dp[i][j] -= mod;
            dp[i][j] += dp[i-1][j] * ((2 * (i-1)-j+1) * (2 * (i-1) - j) / 2) % mod;
            if(dp[i][j] > mod)
                dp[i][j] -= mod;
        }
}
int n;
ll d;
int main()
{
    init();
    while(scanf("%d%lld",&n,&d) != EOF)
    {
        ll ans=0,tmp=1ll;
        for(int i=0;i<=n;i++)
        {
            ans+=dp[n][i] * tmp % mod;
            if(ans>mod) ans -= mod;
            tmp=tmp * d % mod;
        }
        ans=ans * p[n] % mod;
        printf("%lld\n",ans);
    }
    return 0;
}