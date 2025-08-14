#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int n, m;
char A[N][N];

void updateCols(int x, int y){
    for (int i = x; i <= n; i++) {
        if (A[i][y] == '#') {
            A[i][y] = '.';
        } else {
            return;
        }
    }
}

void updateRows(int x, int y){
    for (int i = y; i <= m; i++) {
        if (A[x][i] == '#') {
            A[x][i] = '.';
        } else {
            return;
        }
    }
}

int check(int x, int y) {
    int tempHang = 0;
    int tempCot = 0;

    for (int i = y; i <= m; i++) {
        if (A[x][i] == '#') tempHang++;
        else break;
    }
    
    for (int i = x; i <= n; i++) {
        if (A[i][y] == '#') tempCot++;
        else break;
    }

    if (tempHang >= tempCot && tempHang > 0) return 1;
    if (tempCot > tempHang && tempCot > 0) return 2;
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> A[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i][j] == '#') {
                int flag = check(i, j);
                if (flag == 1) {
                    updateRows(i, j);
                    ans++;
                } else if (flag == 2) {
                    updateCols(i, j);
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
