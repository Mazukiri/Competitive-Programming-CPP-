
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
int n, m;
bool vis[N][N];
char grid[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isInside(int x, int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

void dfs(int u, int v)
{
    vis[u][v] = true;

    for (int i = 0; i < 4; i++)
    {
        int x = u + dx[i];
        int y = v + dy[i];
        if (isInside(x, y) && !vis[x][y] && grid[x][y] == '.')
            dfs(x, y);
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                ans++;
                // vis[i][j] = true;
                dfs(i, j);
            }
        }
    }

    cout << ans;
}