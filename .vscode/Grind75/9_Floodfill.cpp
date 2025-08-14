#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> ans; // Global 'ans' to store the result
vector<vector<int>> image; // Global 'image' to store the input image
int sr, sc, color; // Start row, start column, and new color
int n, m; // Dimensions of the grid
int dx[4] = {0, 0, 1, -1}; // Direction vectors for 4 possible moves
int dy[4] = {1, -1, 0, 0};

// Check if a position is inside the grid
bool isInside(int sr, int sc) {
    return sr >= 0 && sr < n && sc >= 0 && sc < m;
}

// Iterative flood fill using a queue (BFS approach)
void floodFill(int sr, int sc, int color) {
    int originalColor = image[sr][sc]; // Save the original color to replace
    if (originalColor == color) return; // If the color is the same, no need to fill

    queue<pair<int, int>> q;
    q.push({sr, sc});
    ans[sr][sc] = color; // Change the starting cell's color

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isInside(nx, ny) && ans[nx][ny] == originalColor) {
                ans[nx][ny] = color; // Change color
                q.push({nx, ny});   // Push the next cell to the queue
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    image.resize(n, vector<int>(m));
    ans.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> image[i][j];
        }
    }

    ans = image; // Initialize 'ans' as a copy of 'image'

    cin >> sr >> sc >> color;

    if (isInside(sr, sc)) floodFill(sr, sc, color);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << ans[i][j] << " ";
        cout << '\n';
    }

    return 0;
}
