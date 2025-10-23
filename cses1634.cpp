#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
ll dp[N], a[N];

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

    int n, target;
    cin >> n >> target;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    memset(dp, 0x3f, sizeof dp);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int currSum = a[i]; currSum <= target; currSum++)
        {
            dp[currSum] = min(dp[currSum], dp[currSum - a[i]] + 1);
        }
    }

    // for (int i = 1; i <= target; i++)
    //     cout << dp[i] << " ";

    // cout << '\n';

    ll INF = 0x3f3f3f3f3f3f3f3f;

    if (dp[target] != INF)
    {
        cout << dp[target];
    }

    else
    {
        cout << -1;
    }
}