#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define II pair<ll, ll>
#define fi first
#define se second
const int N = 1e6 + 5;
int n, m, k;
vector<II> adj[N];
vector<ll> dist;
ll f[N];

template <class X, class Y>
bool mini(X &x, const Y y)
{
    if (x > y)
        return x = y, 1;
    return 0;
}

void djikstra()
{
    priority_queue<II, vector<II>, greater<II>> pq;

    pq.push({0, 1});

    while (!pq.empty())
    {
        II u = pq.top();
        pq.pop();

        if (u.se == n)
        {
            dist.push_back(u.fi);
        }

        for (II v : adj[u.se])
        {
            pq.push({u.fi + v.fi, v.se});
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

    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(II(c, v));
    }

    djikstra();

    sort(dist.begin(), dist.end());

    for (int i = 0; i < k; i++)
        cout << dist[i] << " ";
}