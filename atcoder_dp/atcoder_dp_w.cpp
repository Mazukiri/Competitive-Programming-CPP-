#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
ll pre[N];
int n, q;
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

    cin >> n >> q;

    for (int i = 1; i <= q; i++)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        pre[l] += x;
        pre[r + 1] += (-x);
    }

    for (int i = 1; i <= n; i++)
        cout << pre[i] << " ";
    cout << '\n';

    for (int i = 1; i <= n; i++)
        pre[i] += pre[i - 1];

    ll ans = 0;

    for (int len = 1; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;

            ans = max(ans, pre[r] - pre[l - 1]);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << pre[i] << " ";

    // cout << ans;
}