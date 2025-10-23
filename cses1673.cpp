#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define II pair<int, int>
#define fi first
#define se second
const int N = 1e6 + 5;
ll n, m, k;

bool f[N];

int d[N];
bool inqueue[N];
int cnt[N];

void SPFA()
{
    vector<int> d(n, INF);
    d[v] = 0;
    for (;;)
    {
        bool any = false;

        for (Edge e : edges)
            if (d[e.a] < INF)
                if (d[e.b] > d[e.a] + e.cost)
                {
                    d[e.b] = d[e.a] + e.cost;
                    any = true;
                    cnt[e.b]++;
                }

        if (cnt[e.b] > n)
        {
            break
        }
    }
    // display d, for example, on the screen
}

void detect()
{
    priority_queue<II, vector<II>, greater<II>> pq;

    q.push({0, 1});

    while (!q.empty())
    {
        II u = q.top();
        q.pop();

        if (u.fi != f[u.se])
            continue;

        for (II v : adj[u.se])
        {
            if
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

    // Chao thau pentest

    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
    }
}