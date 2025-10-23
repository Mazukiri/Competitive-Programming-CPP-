#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int n, m;

bool canReach(int x, int y)
{

    for (int v : adj[x])
    {
        if (v == y)
            return true;
        if ()
    }
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

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    while (q--)
    {
        int typ, x, d;
        cin >> typ >> x >> d;

        if (typ == 1)
        {
            if (d == 0)
            {
                n++;
                adj[u].push_back(n);
            }

            else
            {
                n++;
                adj[n].push_back(u);
            }
        }

        else
        {
            if (canReach(x, y))
            {
                cout << "Yes" << '\n';
            }

            else
                cout << "No" << '\n';
        }
    }
}