#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll dp[2][N];
vector<int> adj[N];
bool vis[N];
int n;
// dp[0][u]: Số cách tô màu cây gốc u mà tại đó màu của u là 0 (trắng)
// dp[1][u]: Số cách tô màu cây gốc u mà tại đó màu của u là 1 (đen)
void dfs(int node)
{

    if (adj[node].size() == 1 && !vis[node])
    {
        dp[0][node] = 1;
        dp[1][node] = 1;
    }

    ll case1 = 1;
    ll case0 = 1;

    vis[node] = true;

    for (auto v : adj[node])
    {
        if (!vis[v] && dp[0][v] == 0)
        {
            dfs(v);
            case0 *= (dp[0][v] + dp[1][v]);
            case0 %= MOD;
            case1 *= dp[0][v];
            case1 %= MOD;
        }
    }

    dp[0][node] = case0;
    dp[1][node] = case1;
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

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << (dp[0][1] + dp[1][1]) % MOD;
}