#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define II pair<int,int>
#define fi first
#define se second
#define III pair <ll, pair<ll, ll>>

vector<pair<ll, ll>> graph[100001]; // weight, node
ll du[100001], dv[100001], ds[100001], dp[2][100001], ans;
bool visited[100001];

void dijkstra1(ll start, ll arr[])
{
    fill(visited, visited + 100001, false);

    priority_queue<II, vector<II>, greater<II>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        ll c, node;
        tie(c, node) = pq.top();
        pq.pop();

        if (!visited[node])
        {
            arr[node] = c;
            visited[node] = true;
            for (auto &i : graph[node])
            {
                pq.push({c + i.first, i.second}); // i.first = weight, i.second = node
            }
        }
    }
}

void dijkstra2(ll start, ll end)
{
    fill(dp[0], dp[0] + 100001, LLONG_MAX / 2);
    fill(dp[1], dp[1] + 100001, LLONG_MAX / 2);
    fill(visited, visited + 100001, false);

    priority_queue<III, vector<III>, greater<III>> pq;
    
    pq.push({0, {start, 0}});
    dp[0][0] = dp[1][0] = LLONG_MAX / 2;
    while (!pq.empty())
    {
        ll c, node, par;
        pair<ll, ll> p;
        tie(c, p) = pq.top();
        tie(node, par) = p;
        pq.pop();

        if (!visited[node])
        {
            visited[node] = true;
            ds[node] = c;
            dp[0][node] = min(du[node], dp[0][par]);
            dp[1][node] = min(dv[node], dp[1][par]);
            for (auto i : graph[node])
            {
                pq.push({c + i.first, {i.second, node}}); // i.first = weight, i.second = node
            }
        }
        else if (c == ds[node])
        {
            if (min(du[node], dp[0][par]) + min(dv[node], dp[1][par]) <= dp[0][node] + dp[1][node])
            {
                dp[0][node] = min(du[node], dp[0][par]);
                dp[1][node] = min(dv[node], dp[1][par]);
            }
        }
    }

    ans = min(ans, dp[0][end] + dp[1][end]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("_ab.inp", "r"))
    {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
    cin.tie(0);
    ll n, m, s, t, u, v;
    cin >> n >> m >> s >> t >> u >> v;
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b}); // store weight first
        graph[b].push_back({c, a});
    }

    dijkstra1(u, du);
    dijkstra1(v, dv);

    ans = du[v];

    for (int i = 1; i<=n; i++) cout << du[i] << " ";
    cout << '\n';
    for (int i = 1; i <= n; i++) cout << dv[i] << " ";
    cout << '\n';

    dijkstra2(s, t);

    cout << ans << '\n';

    dijkstra2(t, s);
    
    cout << ans << '\n';
    return 0;
}
