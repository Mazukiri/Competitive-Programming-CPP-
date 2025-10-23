#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;

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

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        ll x;
        cin >> x;

        if (x%3 == 0) cout << 0 << '\n';
        if (x%3 == 1) cout << 2 << '\n';
        if (x%3 == 2) cout << 1 << '\n';
    }
}