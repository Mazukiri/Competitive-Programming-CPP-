#include <bits/stdc++.h>
using namespace std;

#define int long long
int M, N, D, K;
char grid[10][10];
int impact[10][10]; // Mảng tạm để lưu tác động
int countMarkets[10][15]; // Mảng để lưu số lượng tích lũy

void apply_impact() {
    // Tính toán số lượng "markets" tích lũy từ mảng impact
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (i > 1) impact[i][j] += impact[i-1][j];
            if (j > 1) impact[i][j] += impact[i][j-1];
            if (i > 1 && j > 1) impact[i][j] -= impact[i-1][j-1]; // Trừ đi phần tử bị cộng dư
            
            countMarkets[i][j] += impact[i][j]; // Cộng dồn để tính kết quả cuối cùng
        }
    }
}

void update(int x, int y) {
    int min_x = max(x - D, 1LL), max_x = min(x + D, M);
    int min_y = max(y - D, 1LL), max_y = min(y + D, N);

    // Cập nhật tại các điểm giới hạn
    impact[min_x][min_y] += 1;
    if (max_y + 1 <= N) impact[min_x][max_y + 1] -= 1;
    if (max_x + 1 <= M) impact[max_x + 1][min_y] -= 1;
    if (max_x + 1 <= M && max_y + 1 <= N) impact[max_x + 1][max_y + 1] += 1;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
    
    cin >> M >> N >> D >> K;

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') update(i, j);
        }
    }

    apply_impact(); // Tính toán kết quả cuối cùng từ mảng phân biệt

    int ans = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (grid[i][j] == 'P' && countMarkets[i][j] >= K) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
