#include <bits/stdc++.h>
using namespace std;
#define int long long

int MOD = 1e9 + 7;
int LIM;
struct Matrix {
    int n, v[3][3];
    Matrix() {}
    Matrix(int n) : n(n) {
        memset(v, 0, sizeof v);
    }
    Matrix(const vector<vector<int> > &tmp) {
        n = tmp.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                v[i][j] = tmp[i][j];
    }
    Matrix operator* (Matrix b) {
        Matrix res(b.n);
        for (int i = 0; i < b.n; ++i)
            for (int j = 0; j < b.n; ++j) {
                int x = 0;
                for (int k = 0; k < b.n; k++) {
                    x += v[i][k] * b.v[k][j];
                    if (x > LIM) x -= LIM;
                }
                res.v[i][j] = x % MOD;
            }
        return res;
    }
    friend Matrix Pow(Matrix a, int b) {
        Matrix ans(a.n);
        for (int i = 0; i < a.n; ++i)
            ans.v[i][i] = 1;
        while (b) {
            if (b & 1)
            ans = ans * a;
            a = a * a;
            b >>= 1;
        }
        return ans;
    }
};
int fibo(int n) {
    if (n < 2) return n;
    Matrix a({
        {1, 1},
        {1, 0}
    });
    a = Pow(a, n - 2);
    return (a.v[0][0] + a.v[0][1]) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; cin >> n >> MOD;
    LIM = MOD;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    if (n == 2){
        cout << 2;
        return 0;
    }

    Matrix a(
        {{1, 1, 1},
        {1, 0, 0},
        {0, 1, 0}}
    );


    a = Pow(a, n - 3);

    int ans = a.v[0][0] * 4 + a.v[0][1] * 2 + a.v[0][2] * 1;
    ans %= MOD;
    cout << ans;


}