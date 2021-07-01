#include <iostream>
using namespace std;

const int N = 100010;
int n;
int q[N];
int res[N];

void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int mid = (l + r ) / 2;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    int i = l,j = mid + 1;
    int k = 0;
    while(i <= mid && j <= r)
    {
        if (q[i] <= q[j]) res[k++] = q[i++];
        else res[k++] = q[j++];
    }

    while (j <= r) res[k++] = q[j++];
    while (i <= mid) res[k++] = q[i++];

    for (i = l ,j = 0; i <= r; i ++, j ++) q[i] = res[j];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> q[i];

    merge_sort(q, 0, n - 1);
    
    for  (int i = 0; i < n; i ++) printf("%d ", q[i]);
    
    return 0;
}