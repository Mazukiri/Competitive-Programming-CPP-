#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll dp[2][N];
vector<int> adj[N];
ll n, MOD;

void dfs(int node, int pre)
{

    if (adj[node].size() == 1 && adj[node][0] == pre)
    {
        dp[0][node] = 1;
        dp[1][node] = 1;
        return;
    }

    for (int v : adj[node])
    {
        if ((dp[0][v] == 0 || dp[1][v] == 0) && (v != pre))
        {
            dfs(v, node);
        }
    }

    dp[0][node] = 1;
    dp[1][node] = 1;

    for (int v : adj[node])
    {
        if (v != pre)
        {
            dp[1][node] *= (dp[0][v] + dp[1][v]);
            dp[1][node] %= MOD;
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

    cin >> n >> MOD;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int choosen_One = 1;

    for (int i = 2; i <= n; i++)
    {
        if (adj[i].size() > adj[choosen_One].size())
        {
            choosen_One = i;
        }
    }

    dp[1][choosen_One] = 1;
    dfs(choosen_One, choosen_One);

    for (int i = 1; i <= n; i++)
        if (i != choosen_One && adj[i].size() < adj[choosen_One].size())
            cout << (dp[1][i] + (dp[1][choosen_One] / 2)) % MOD << '\n';
        
            if (i != choosen_One && adj[i].size() < adj[choosen_One].size())
            cout << dp[1][choosen_One]  << '\n';
}
