/*
        P1035 ���籭֮��
        ����
        ��N��������Լһ�����籭��ӫĻǰ������2N�����ŵ�λ�á� �����˶����������ĳ��λ���ϡ� ��Ȼ�����ĳһ���������ð����������Ǿͻ���˵����Ļ���Ӱ�����籭�Ĺۿ��� һ��أ�����һ���������������������K�����������ǰ������ģ��ͻ����D^K������ֵ�� �ȶ�����֪�����������������������ֵ�� Ϊ�˱������ʵ�������������*(2N)!)��mod P��ֵ������P=998244353

        ��ʽ
        �����ʽ
        �ж������ݣ�������1000�飩������EOF������ ����ÿһ�����ݣ�����������N��D�� 1<=N,D<=1000
        �����ʽ
        ����ÿһ�����ݣ����һ������ʾ�𰸡�
        ����
        ��������
        1 10
        2 3
        �������
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