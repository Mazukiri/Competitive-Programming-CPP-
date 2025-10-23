#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define II pair<ll, ll>
#define fi first
#define se second
const int N = 1e6 + 5;
int n, m, k;
vector<II> adj[N];
priority_queue<ll> dist[N];
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
    dist[1].push(0);

    while (!pq.empty())
    {
        II u = pq.top();
        pq.pop();

        if (u.fi > dist[u.se].top())
            continue;

        for (II v : adj[u.se])
        {
            if (dist[v.se].size() < k)
            {
                dist[v.se].push(u.fi + v.fi);
                pq.push(II(v.fi + u.fi, v.se));
            }

            else if (u.fi + v.fi < dist[v.se].top())

            {
                dist[v.se].pop();
                dist[v.se].push(u.fi + v.fi);
                pq.push(II(v.fi + u.fi, v.se));
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

    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(II(c, v));
    }

    djikstra();

    vector<ll> ans;

    // while (dist[n].size() > 0)
    // {
    //     cout << dist[n].top() << " ";
    //     dist[n].pop();
    // }

    for (int i = 0; i < k; i++)
    {
        ans.push_back(dist[n].top());
        dist[n].pop();
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}