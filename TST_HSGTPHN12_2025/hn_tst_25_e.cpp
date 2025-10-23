#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define II pair<int, int>
#define fi first
#define se second
const int N = 10;
int n, m;
queue<II> q, q1;
II nxt[N][N][4];
ll dist[N][N];
char grid[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

template <class X, class Y>
bool mini(X &x, const Y y)
{
    if (x > y)
        return x = y, 1;
    return 0;
}

bool isInside(II u)
{
    return (1 <= u.fi && u.fi <= n && 1 <= u.se && u.se <= m);
}

void BFS()
{
    while (!q.empty())
    {
        II u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            II v = nxt[u.fi][u.se][i];

            if (isInside(v) && grid[u.fi + dx[i]][v.fi + dy[i]] == '1')
            {
                if (mini(dist[v.fi][v.se], dist[u.fi][u.se] + 1))
                {
                    q1.push(II(v));
                }
            }

            if (isInside(v) && grid[u.fi + dx[i]][v.fi + dy[i]] == '0')
            {
                if (mini(dist[v.fi][v.se], dist[u.fi][u.se]))
                {
                    q.push(II(v));
                }
            }
        }
    }

    while (1)
    {
        if ((q.empty()))
            break;
        while (!q.empty())
        {
            II u = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                II v = nxt[u.fi][u.se][i];

                if (isInside(v) && grid[u.fi + dx[i]][v.fi + dy[i]] == '1')
                {
                    if (mini(dist[v.fi][v.se], dist[u.fi][u.se] + 1))
                    {
                        q1.push(II(v));
                    }
                }

                if (isInside(v) && grid[u.fi + dx[i]][v.fi + dy[i]] == '0')
                {
                    if (mini(dist[v.fi][v.se], dist[u.fi][u.se]))
                    {
                        q.push(II(v));
                    }
                }
            }
        }

        while (!q1.empty())
        {
            q.push(q1.front());
            q1.pop();
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

    II u;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '@')
            {
                q.push(II(i, j));
            }

            if (grid[i][j] == '#')
            {
                II u = II(i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == '0')
            {
                for (int id = 0; id < 4; id += 2)
                {
                    nxt[i][j][id] = II(i, j);
                }
            }

            if (grid[i][j] == '1')
            {
                for (int id = 0; id < 4; id += 2)
                {
                    int i1 = i - dx[id];
                    int j1 = j - dy[id];
                    if (isInside(II(i1, j1)))
                    {
                        nxt[i][j][id] = nxt[i1][j1][id];
                    }
                }
            }
        }
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            if (grid[i][j] == '0')
            {
                for (int id = 1; id < 4; id += 2)
                {
                    nxt[i][j][id] = II(i, j);
                }
            }

            if (grid[i][j] == '1')
            {
                for (int id = 1; id < 4; id += 2)
                {
                    int i1 = i - dx[id];
                    int j1 = j - dy[id];
                    if (isInside(II(i1, j1)))
                    {
                        nxt[i][j][id] = nxt[i1][j1][id];
                    }
                }
            }
        }
    }

    BFS();

    cout << dist[u.fi][u.se];
}