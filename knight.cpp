#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int, int>
#define fi first
#define se second

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
//Bài Knight
//Thuật toán Dial trên lưới
//Decorate 

 queue<II> q;
vector<vector<int>> dist(11, vector<int>(11, -1)); // Tạo mảng 2D 11x11 với giá trị -1 (chưa được thăm)

bool isInside(int x, int y) {
    return (1 <= x && x <= 10 && 1 <= y && y <= 10);
}

signed main() {
    ios_base::sync_with_stdio(0);
    
    cin.tie(0);
    cout.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int x, y, n;
    cin >> x >> y >> n;

    dist[x][y] = 0; // Điểm bắt đầu có số bước = 0
    q.push({x, y});

    while (!q.empty()) {
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();

        // Kiểm tra 8 hướng đi hợp lệ
        for (int i = 0; i < 8; i++) {
            int u1 = u + dx[i];
            int v1 = v + dy[i];
            if (isInside(u1, v1) && dist[u1][v1] == -1) {
                dist[u1][v1] = dist[u][v] + 1; // Cập nhật số bước đến ô mới
                 
                    q.push({u1, v1});
                
            }
        }
    }

    // Đếm số ô đến được sau đúng n bước
    int ans = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (dist[i][j] == n) {
                ans++;
            }
        }
    }

    cout << ans;
}
