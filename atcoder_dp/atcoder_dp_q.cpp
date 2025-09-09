#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
ll h[N], dp[N], a[N];
int n;
template <class X, class Y>
bool maxi(X &x, const Y y)
{
    if (x < y)
        return x = y, 1;
    return 0;
}

const ll INF = 0;
ll seg[N * 4];

void update(ll pos, ll val, int id = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        seg[id] = val;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
        update(pos, val, id << 1, l, mid);
    else
        update(pos, val, id << 1 | 1, mid + 1, r);
    seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
ll get(int u, int v, int id = 1, int l = 1, int r = n)
{
    if (l > r || r < u || v < l)
        return INF;
    if (u <= l && r <= v)
    return seg[id];
    int mid = l + r >> 1;
    return max(
        get(u, v, id << 1, l, mid),
        get(u, v, id << 1 | 1, mid + 1, r));
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

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {   
        // dp[h[i]] = a[i];

        maxi(dp[h[i]], get(1, h[i] - 1) + a[i]);

        // cout << get(1, h[i] - 1) << '\n';

        update(h[i], dp[h[i]]);
    }

    // for (int i = 1; i <= n; i++)
    //     cout << dp[h[i]] << " " << '\n';

    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);

    cout << ans;
}