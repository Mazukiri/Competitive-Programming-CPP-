#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
ll pre[N], pre_[N], point[N];

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

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= q; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        if (x > 0)
        {
            pre[l] += x;
            pre[r + 1] -= x;
        }

        else
        {
            pre_[l] += x;
            pre_[r + 1] -= x;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        pre[i] += pre[i - 1];
        pre_[i] += pre_[i - 1];
        point[i] = pre[i] + pre_[i];
    }

    for (int i = 1; i <= n; i++)
        cout << pre[i] << " ";

    cout << '\n';

    for (int i = 1; i <= n; i++)
        cout << pre_[i] << " ";

    cout << '\n';

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (point[i] > 0)
            ans += point[i];
    }

    cout << ans;
}