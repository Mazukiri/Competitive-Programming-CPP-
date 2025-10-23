#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int a[N];
ll dp[N];
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

    int maxSum = 0;

    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        maxSum += a[i];
        dp[a[i]]++;
    }

    // for (int i = 1; i <= n; i++)
    //     cout << a[i] << " ";
    // cout << '\n';

    dp[0] = 1;

    int ans = 0;

    // cout << maxSum << '\n';

    for (int i = 1; i <= n; i++)
    {
        for (int currSum = maxSum; currSum >= a[i]; currSum--)
        {
            {
                if (dp[currSum - a[i]] > 0)
                {
                    dp[currSum]++;
                }
            }
        }
    }

    // for (int i = 1; i <= maxSum; i++)
    //     cout << dp[i] << " ";
    // cout << '\n';

    cout << dp[n * (n + 1) / (2 * 2)];
}