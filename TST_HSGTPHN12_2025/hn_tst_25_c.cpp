#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int pre[4][N], A[N];
int n;

bool check(int a, int b, int c, int d)
{
    return (a == b && b == c && d == 0) || (a == b && b == d && c == 0) || (a == c && c == d && b == 0) || (b == c && c == d && a == 0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("_ab.inp", "r"))
    {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    /* There has to be the same numbers of 0, 1, 2 on range [L, R];
    Hence, (R - L + 1) % 3 == 0 and pre0 = pre1 = pre2
    */

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        pre[0][i] += pre[0][i - 1] + (A[i] == 0);
        pre[1][i] += pre[1][i - 1] + (A[i] == 1);
        pre[2][i] += pre[2][i - 1] + (A[i] == 2);
        pre[3][i] += pre[3][i - 1] + (A[i] == 3);
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int len = 3; i + len - 1 <= n; len += 3)
        {
            int pre0 = pre[0][i + len - 1] - pre[0][i - 1];
            int pre1 = pre[1][i + len - 1] - pre[1][i - 1];
            int pre2 = pre[2][i + len - 1] - pre[2][i - 1];
            int pre3 = pre[3][i + len - 1] - pre[3][i - 1];

            if (check(pre0, pre1, pre2, pre3))
            {
                ans++;
            }
        }
    }

    cout << ans;
}