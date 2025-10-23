#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define II pair<ll, int>
#define fi first
#define se second
const int N = 2e3 + 505;
ll f[N];
int n, m;
vector<II> adj[N];

template <class X, class Y>
bool mini(X &x, const Y y)
{
    if (x > y)
        return x = y, 1;
    return 0;
}

void djikstra()
{
    priority_queue<II, vector<II>, greater<II>> q;
    memset(f, 0x3f, sizeof f);

    q.push({0, 1});
    f[1] = 0;

    while (!q.empty())
    {
        II u = q.top();
        q.pop();

        if (u.fi != f[u.se])
            continue;

        for (II v : adj[u.se])
        {
            if (mini(f[v.se], f[u.se] + v.fi))
            {
                q.push({f[v.se], v.se});
            }
        }
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
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({-c, v});
        // adj[v].push_back({c, u});
    }

    djikstra();

    if (abs(f[n] == 0))
        cout << -1;
    else
    {
        cout << -f[n];
    }
}