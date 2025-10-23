#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
ll dp[N], preW[N], preV[N], V[N], W[N];
ll n, k, s;

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

    cin >> n >> k >> s;

    if (k > n)
        return cout << 0, 0;

    int cntS = 0;

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> V[i];
        preV[i] = preV[i - 1] + V[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> W[i];
        if (W[i] > s)
            cntS++;
        preW[i] = preW[i - 1] + W[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int initial = i;
        for (int j = i + k - 1; j <= n; j += (k))
        {
            ll currSum = preV[j] - preV[initial - 1];
            ll currEnergy = preW[j] - preW[initial - 1];
            if (currEnergy < s)
            {
                ans = max(ans, currSum);
            }
        }
    }

    cout << ans;
}
