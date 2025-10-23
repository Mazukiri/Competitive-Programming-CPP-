#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
int n, m, k;
int grid[N][N], state[N][N];
bool vis[N][N];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isInside(int u, int v)
{
    return (u >= 1 && u <= n && v >= 1 && v <= m);
}

void sub1()
{
    // n = 1 and k = 1. Prefixsum lazy
    for (int i = 1; i <= m; i++)
    {
        if (grid[1][i] == 1)
        {
            if (isInside(1, i - 1) && grid[1][i - 1] != 1)
            {
                state[1][i - 1] = 1;
            }

            if (isInside(1, i + 1) && grid[1][i + 1] != 1)
            {
                state[1][i + 1] = 1;
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {

        if (grid[1][i] == 1 || state[1][i] == 1)
        {
            cout << 1 << " ";
        }

        else
        {
            cout << 0 << " ";
        }
    }
    cout << '\n';
}

void update(int u, int v)
{
    vis[u][v] = true;

    for (int i = 0; i < 8; i++)
    {
        int x = u + dx[i];
        int y = v + dy[i];

        if (isInside(x, y) && grid[x][y] != 1)
        {
            grid[x][y] = 1;
            vis[x][y] = true;
        }
    }
}

void sub2()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            vis[i][j] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                update(i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << grid[i][j] << " ";
        }

        cout << '\n';
    }
}

void sub3()
{
    // Actually, k will be smaller than 1000
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         if (grid[i][j] == 1 || state[i][j] == 1)
    //         {
    //             state[i][j] += 1
    //                 // Ngang
    //                 state[i][min(m, j + k)] += 1;
    //             state[i][max(1, j - k)] += 1;
    //             // Tren duoi
    //             state[min(1, i + k)][j] += 1;
    //             state[max(m, i - k)][j] += 1;
    //             // Cheo tren
    //             state[max(m + 1, i + k + 1)][j + k] += 1;
    //             state[i + k][j - k] += 1;
    //             state[i - k][j + k] += 1;
    //             state[i - k][j - k] += 1;
    //         }
    //     }
    // }
    return;
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
            cin >> grid[i][j];
    }

    if (k == 0 || (n == 1 && m == 1))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << grid[i][j] << " ";
            cout << '\n';
        }

        return 0;
    }

    if (n == 1 && k == 1)
    {
        sub1();
        return 0;
    }

    if (k == 1)
    {
        sub2();
    }

    sub3();
}