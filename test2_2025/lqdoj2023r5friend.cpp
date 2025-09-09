#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define II pair<int, int>
#define fi first
#define se second
#define edges pair<II, int>
const int N = 2e5 + 5;
bool vis[N];
unordered_map<int, unordered_map<int, int>> cost[2];
ll cnt[2001][2001], cst[N];
int n;
vector<edges> adj[N];

namespace sub1
{

    void solve()
    {
    }
}

namespace sub2
{
    template <class X, class Y>
    bool mini(X &x, const Y y)
    {
        if (x > y)
            return x = y, 1;
        return 0;
    }

    int f[2005], trace[2005];

    void dijkstra(int node)
    {
        memset(f, 0x3f, sizeof f);
        memset(trace, 0, sizeof trace);
        priority_queue<II, vector<II>, greater<II>> q;
        q.push({0, node});
        f[node] = 0;

        // find shortest path from node to other sources
        while (!q.empty())
        {
            II u = q.top();
            q.pop();
            if (u.fi != f[u.se])
                continue;
            for (edges v : adj[u.se])
            {
                if (mini(f[v.se], f[u.se] + v.fi.se))
                {
                    q.push({f[v.se], v.se});
                    trace[v.se] = u.se;
                }

                if (mini(f[v.se], f[u.se] + v.fi.fi))
                {
                    q.push({f[v.se], v.se});
                    trace[v.se] = u.se;
                }
            }
        }

        int u = node + 1;

        // trace to count path
        while (trace[u] != 0)
        {
            cnt[u][trace[u]]++;
            cnt[trace[u]][u]++;
            u = trace[u];
        }
    }

    void solve()
    {
        ll ans = 0;

        for (int i = 1; i < n; i++)
        {
            dijkstra(i);
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (cnt[i][j] > 0)
                {
                    ans += min(cnt[i][j] * (ll)cost[1][i][j],
                               (ll)cost[0][i][j]);
                }
            }
        }

        cout << ans;
    }
}

namespace sub3
{
#include <bits/stdc++.h>
    using namespace std;
    const int MAX_N = 200005;
    struct edge
    {
        int u, v, c1, c2;
    } edges[MAX_N];
    int numNode;
    vector<pair<int, int>> adj[MAX_N];
    int cnt = 0;
    int f[MAX_N], d[MAX_N];
    void dfs(int x, int pre)
    {
        d[x] = ++cnt;
        for (pair<int, int> tmp : adj[x])
        {
            if (tmp.first != pre)
            {
                dfs(tmp.first, x);
            }
        }
    }
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        freopen("FRIEND.inp", "r", stdin);
        freopen("FRIEND.out", "w", stdout);
        cin >> numNode;
        for (int i = 1; i < numNode; i++)
        {
            cin >> edges[i].u >> edges[i].v >> edges[i].c1 >> edges[i].c2;
            adj[edges[i].u].push_back(make_pair(edges[i].v, i));
            adj[edges[i].v].push_back(make_pair(edges[i].u, i));
        }
        int root;
        for (int i = 1; i <= numNode; i++)
        {
            if (adj[i].size() == 1)
            {
                root = i;
            }
        }
        dfs(root, root);
        for (int i = 1; i < numNode; i++)
        {
            int u = min(d[i], d[i + 1]), v = max(d[i], d[i + 1]);
            f[u]++;
            f[v]--;
        }
        for (int i = 1; i <= numNode; i++)
        {
            f[i] += f[i - 1];
        }
        long long answer = 0;
        for (int i = 1; i < numNode; i++)
        {
            int x = min(d[edges[i].u], d[edges[i].v]);
            answer += min(1LL * edges[i].c1 * f[x], 1LL * edges[i].c2);
        }
        cout << answer;
        return 0;
    }
}

namespace sub4
{

    void solve();
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

    int case1 = 0;

    for (int i = 1; i < n; i++)
    {
        int a, b, c1, c2;
        cin >> a >> b >> c1 >> c2;
        adj[a].push_back(edges(II(c1, c2), b));
        adj[b].push_back(edges(II(c1, c2), a));
        cost[1][a][b] = cost[1][b][a] = c1;
        cost[0][a][b] = cost[0][b][a] = c2;

        if (c1 == c2)
            case1++;
    }

    if (case1 == n - 1)
    {
        ll cost = 0;

        for (int u = 1; u <= n; u++)
        {
            for (auto v : adj[u])
            {
                cost += v.fi.fi;
            }
        }

        cout << cost;
    }

    if (n <= 2000)
    {
        sub2::solve();
    }

    cout << '\n';
    sub4::solve();
}