#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
#define II pair<int, int>
#define fi first
#define se second
queue<II> q, q2;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool vis[N][N], grid[N][N], f[N][N];
int n, m, k;

bool isInside(int x, int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m);
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j])
            {
                q.push({i, j});
                f[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << grid[i][j];
        }

        cout << '\n';
    }

    for (int i = 1; i <= k; i++)
    {
        while (!q.empty())
        {
            II node = q.front();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int x = node.fi + dx[i];
                int y = node.se + dy[i];
                if (isInside(x, y) && !f[x][y])
                {
                    q2.push(II(x, y));
                    f[x][y] = true;
                }
            }
        }

        while (!q2.empty())
        {
            q.push(q2.front());
            q2.pop();
        }

        if (q.empty())
            break;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << f[i][j] << " ";
        }

        cout << '\n';
    }
}