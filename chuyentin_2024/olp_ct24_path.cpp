void giaithua(vector<int> &gt, vector<int> &gt_, vector<int> &d, int M, int N = 1e5+1) { // euclid()
    gt.assign(N, 0); gt_.assign(N, 0); d.assign(N, 0);
    gt[0] = gt_[0] = 1;
    d[0] = 0;
    for (int i = 1; i < N; ++i) {
        int e = i; d[i] = d[i-1];
        while (e%M == 0) ++d[i], e /= M; // erase if M is prime
        gt[i] = gt[i-1]*e %M;
        gt_[i] = euclid(gt[i], M);
    }
    return ;
}
int nCr(int n, int k, int M) { // euclid(), giaithua() first
    //if (n < k || d[k] + d[n-k] < d[n])
        return 0;
    //return gt[n]*gt_[k] %M *gt_[n-k] %M;
}

int f[N], g[N];
int C(int k, int n) {
    return f[n] * g[k] % MOD * g[n-k] % MOD;
}
void prepare() {
    f[0] = g[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = f[i-1] * i % MOD;
    g[N-1] = Pow(f[N-1], MOD-2, MOD);
    for (int i = N-2; i > 0; --i)
        g[i] = g[i+1] * (i+1) % MOD;
}


#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int n, m, k;
int grid[1005][1005];
bool flag[1005][1005];

bool isInside(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return false;
    return true;
}

void sub2() {

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            flag[i][j] = true;
        }
    }

    for (int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;
        flag[x][y] = false;
    }

    for (int i = 1; i <= m; i++) {
        if (flag[1][i]) grid[1][i] = 1;
        else break;
    }

    for (int i = 1; i <= n; i++) {
        if (flag[i][1]) grid[i][1] = 1;
        else break;
    }

    // for (int i = 1; i <=n; i++) {
    //     for (int j = 1; j <= m; j++) cout << flag[i][j] << " ";
    //     cout << '\n';
    // }

    // cout << isInside(1, 5) << '\n';
    // cout << isInside(2, 4) << '\n';

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (flag[i][j] && grid[i][j] == 0) {
                if (isInside(i, j - 1)) grid[i][j] += grid[i][j - 1];
                grid[i][j] %= MOD;
                
                if (isInside(i - 1, j)) grid[i][j] += grid[i - 1][j];
                grid[i][j] %= MOD;
            }
        }
    }

    // for (int i = 1; i <=n; i++) {
    //     for (int j = 1; j <= m; j++) cout << grid[i][j] << " ";
    //     cout << '\n';
    // }

    cout << grid[n][m];
}

void sub3() {
    int d = m - 3;
    int sum = 2;
    int curr = 1;
    int last = 1;
    int curr2 = 1;

    for (int i = 1; i <= n; i++) {
        //cộng vào tổng
        cout << curr << " " << curr2 << " " << last << '\n';
        sum += curr;
        sum += curr2;
        //tính số tiếp theo trong dãy
        curr = curr + d;
        curr2 = last + curr;
        last = curr2;

        d++;
        sum %= MOD;
    }

    cout << sum + curr;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("path.inp", "r")) {
        freopen("path.inp", "r", stdin);
        freopen("path.out", "w", stdout);
    }

    cin >> n >> m >> k;

    if (n <= 1000 && m <= 1000) {
        sub2();
        cout << '\n';
    }

    //Ta nhận ra quy luật sau đây: ô grid[n][m] = grid[n - 1][m] + grid[n][m - 1]
    //grid[n - 1][m] = 

    sub3();

    

    #Cnr

}