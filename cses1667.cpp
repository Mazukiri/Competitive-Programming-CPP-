#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int n, m;
int color[N];
bool flag = true;
vector<int> adj[N];

void colour(int u)
{
    for (int v : adj[u])
    {
        if (color[u] != 0 && color[v] != 0 && color[u] == color[v])
        {
            flag = false;
            return;
        }

        if (color[v] == 0)
        {
            if (color[u] == 1)
                color[v] = 2;
            else
            {
                color[v] = 1;
            }
            colour(v);
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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            color[i] = 1;
            colour(i);
        }
    }

    // Dem so do thi hai phia khac nhau co the tao ra: 2^(so tplt) va k ton tai
    // chu trinh do dai le
    // Tim chu trinh co do dai ngan nhat: BFS
    // Tim chu trinh co dai lon nhat: DFS de tim cac chu trinh nho nhat, va xem
    // co ghep duoc khong.

    if (!flag)
    {
        cout << "IMPOSSIBLE" << '\n';
    }

    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << color[i] << " ";
        }
    }
}