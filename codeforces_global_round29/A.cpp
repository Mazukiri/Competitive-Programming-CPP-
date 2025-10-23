#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;

ll solve(int u, int v)
{
    if (u < v)
        return 2;
    if (u > v)
    {
        if (u - v > 1 && v > 1)
            return 3;
        return -1;
    }

    return -1;
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

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << solve(u, v) << '\n';
    }
}