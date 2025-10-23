#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll dp[N], target, a[N], n;

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

    cin >> n >> target;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dp[0] = 1;

    for (int currSum = 1; currSum <= target; currSum++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (a[j] <= currSum)
            {
                dp[currSum] += (dp[currSum - a[j]] != 0);
                dp[currSum] %= MOD;
            }
        }
    }

    cout << dp[target];
}