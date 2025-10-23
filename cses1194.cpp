#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define II pair<int, int> // Added definition
#define fi first          // Added definition
#define se second         // Added definition

const int N = 1005; // Changed to a reasonable grid size
const int INF = 0x3f3f3f3f;
int n, m;

// Grid and distance arrays
char grid[N][N];
int distMonster[N][N];
int distPerson[N][N];
int par[N][N]; // Stores parent direction (0=U, 1=D, 2=L, 3=R)

// Queues
queue<II> qMonster;
queue<II> qPerson;

// Start and end coordinates
int startX, startY;
int endX = -1, endY = -1; // -1 indicates no exit found yet

// Movement vectors (Up, Down, Left, Right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dirChar[] = {'U', 'D', 'L', 'R'};

template <class X, class Y>
bool mini(X &x, const Y y)
{
    if (x > y)
        return x = y, 1;
    return 0;
}

bool isSafe(int x, int y)
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

    cin >> n >> m;

    memset(distMonster, 0x3f, sizeof distMonster);
    memset(distPerson, 0x3f, sizeof distPerson);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'M')
            {
                qMonster.push({i, j}); // Use {} for pair
                distMonster[i][j] = 0;
            }

            if (grid[i][j] == 'A')
            {
                qPerson.push({i, j}); // Use {} for pair
                distPerson[i][j] = 0;
                startX = i;
                startY = j;
            }
        }
    }

    // --- Monster BFS ---
    // Calculates shortest time for *any* monster to reach each cell
    while (!qMonster.empty())
    {
        II u = qMonster.front();
        qMonster.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = u.fi + dx[i];
            int y = u.se + dy[i]; // FIX: Was u.fi

            // Check bounds, not a wall, and not visited
            if (isSafe(x, y) && grid[x][y] != '#' && mini(distMonster[x][y], distMonster[u.fi][u.se] + 1))
            {
                qMonster.push({x, y});
            }
        }
    }

    // --- Person BFS ---
    // Finds shortest path to an exit, avoiding monsters
    while (!qPerson.empty())
    {
        II u = qPerson.front();
        qPerson.pop();

        // Check if this is an exit cell (border)
        if (u.fi == 1 || u.fi == n || u.se == 1 || u.se == m)
        {
            endX = u.fi;
            endY = u.se;
            break; // Found the shortest path to an exit
        }

        for (int i = 0; i < 4; i++)
        {
            int x = u.fi + dx[i];
            int y = u.se + dy[i]; // FIX: Was u.fi

            // Check bounds, not a wall
            if (isSafe(x, y) && grid[x][y] != '#')
            {
                // CRITICAL: Can only move here if we arrive BEFORE a monster
                // AND this is a shorter path for us than one we've already found
                if (distPerson[u.fi][u.se] + 1 < distMonster[x][y] &&
                    mini(distPerson[x][y], distPerson[u.fi][u.se] + 1)) // FIX: Was distMonster
                {
                    par[x][y] = i; // Store the direction we came from
                    qPerson.push({x, y});
                }
            }
        }
        if (endX != -1)
            break; // Stop BFS once exit is found
    }

    // --- Output ---
    if (endX == -1) // No exit was found
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";

        string path = "";
        int currX = endX;
        int currY = endY;

        // Trace path backwards from end to start
        while (currX != startX || currY != startY)
        {
            int dir = par[currX][currY];
            path += dirChar[dir];

            // Move to the parent cell
            currX -= dx[dir];
            currY -= dy[dir];
        }
        reverse(path.begin(), path.end()); // Reverse to get start-to-end path

        cout << path.length() << "\n";
        cout << path << "\n";
    }

    return 0;
}