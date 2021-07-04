/*
    ��Ŀ
        ����һ�� n �� m �е��������������� q ��������ÿ����������������� x1,y1,x2,y2,c������ (x1,y1) �� (x2,y2) ��ʾһ���Ӿ�������Ͻ���������½����ꡣ
        ÿ��������Ҫ��ѡ�е��Ӿ����е�ÿ��Ԫ�ص�ֵ���� c��
        ���㽫���������в�����ľ��������
    �����ʽ
        ��һ�а������� n,m,q��
        ������ n �У�ÿ�а��� m ����������ʾ��������
        ������ q �У�ÿ�а��� 5 ������ x1,y1,x2,y2,c����ʾһ��������
    �����ʽ
        �� n �У�ÿ�� m ����������ʾ���в���������Ϻ�����վ���
    ���ݷ�Χ
        1��n,m��1000,
        1��q��100000,
        1��x1��x2��n,
        1��y1��y2��m,
        ?1000��c��1000,
        ?1000�ܾ�����Ԫ�ص�ֵ��1000
*/

#include <iostream>
using namespace std;

const int N = 1010;
int n, m, q;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            scanf("%d", &a[i][j]);

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++ )
            insert(i, j, i, j, a[i][j]);
    
    while (q --)
    {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            a[i][j] = a[i][j - 1] + a[i - 1][j] + b[i][j] - a[i - 1][j - 1];

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}