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
        int ans = 0;

        int n;
        cin >> n;

        int x;
        cin >> x;

        for (int j = 2; j <= n; j++)
        {
            int y;
            cin >> y;

            ans = max(ans, abs(x - y));
            x = y;
        }

        cout << "Case #" << i << ": " << ans << '\n';
    }
}