#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll dp[N];
int n;

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

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 1 + dp[1] + dp[3] + dp[2];
    dp[5] = 1 + dp[1] + dp[2] + dp[3] + dp[4];
    dp[6] = 1 + dp[1] + dp[2] + dp[3] + dp[4] + dp[5];

    for (int i = 7; i <= n; i++)
    {
        dp[i] += (dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6]);
        dp[i] %= MOD;
    }

    cout << dp[n];
}