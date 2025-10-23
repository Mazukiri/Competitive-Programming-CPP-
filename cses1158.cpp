#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
ll dp[N], n, x, price[N], pages[N];

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

    cin >> n >> x;

    for (int i = 1; i <= n; i++)
        cin >> price[i];
    for (int i = 1; i <= n; i++)
        cin >> pages[i];

    ll INF = 1e9 + 7;

    memset(dp, -INF, sizeof dp);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int currMoney = x; currMoney >= price[i]; currMoney--)
        {

            dp[currMoney] = max(dp[currMoney], dp[currMoney - price[i]] + pages[i]);
        }
    }

    ll ans = 0;

    for (int i = 1; i <= x; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans;
}