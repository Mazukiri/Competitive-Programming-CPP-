#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
unordered_map<ll, bool> mp;
ll pre[N], dp[N], A[N], suff[N];
#define II pair<ll, bool>
#define fi first
#define se second

int n;

int bs(int l, int r, int currIndex, ll target)
{

    ll ans = -1;

    while (l <= r)
    {
        int mid = (l + r) >> 1;

        if (pre[currIndex] - pre[mid - 1] <= target)
        {
            ans = mid;
            r = mid - 1;
        }

        else
        {
            l = mid + 1;
        }
    }

    return (pre[currIndex] - pre[ans - 1] == target) ? ans : -1;
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
        cin >> A[i];
        pre[i] = pre[i - 1] + A[i];
    }

    ll X, Y;
    cin >> X >> Y;
    mp[X] = mp[Y] = true;

    if (X > Y)
        swap(X, Y);

    while (X + Y <= 1e18)
    {
        ll Z = X + Y;
        mp[Z] = true;
        X = Y;
        Y = Z;
    }

    dp[0] = 1;

    // for (int i = 1; i <= n; i++)
    // {

    //     ll currSum = 0;

    //     for (int j = i; j >= 1; j--)
    //     {
    //         currSum += A[j];
    //         if (mp[currSum])
    //         {
    //             dp[i] += dp[j - 1];
    //             dp[i] %= MOD;
    //         }
    //     }
    // }

    for (int i = 1; i <= n; i++)
    {
        for (II s : mp)
        {
            int ithIndex = bs(1, i, i, s.fi);
            if (ithIndex != -1)
            {
                dp[i] += dp[ithIndex - 1];
                dp[i] %= MOD;
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    //     cout << dp[i] << " ";

    // cout << '\n';

    cout << dp[n];
}