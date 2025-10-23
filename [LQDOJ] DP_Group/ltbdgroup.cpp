#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll A[N], dp[N];

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

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    int k;
    cin >> k;

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= i - k + 1; j--)
        {
            if (j - 1 >= 0 && A[i] == A[j])
                dp[i] += dp[j - 1];
            dp[i] %= MOD;
        }
    }

    // for (int i = 1; i <= n; i++)
    //     cout << dp[i] << " ";

    cout << dp[n];
}