#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    void add(int &x, const int &y) {
        x += y;
        if (x >= MOD) x -= MOD;
    }
    
    struct matrix {
        vector<vector<int>> v;
        int NumRow, NumColumn;
        matrix(int _NumRow = 0, int _NumColumn = 0) {
            NumRow = _NumRow;
            NumColumn = _NumColumn;
            v.assign(NumRow + 5, vector<int>(NumColumn + 5, 0));
        }
    };
    
    matrix operator * (const matrix &one, const matrix &two) {
    
        matrix result(one.NumRow, two.NumColumn);
        for (int i = 1; i <= one.NumRow; i++) {
            for (int j = 1; j <= two.NumColumn; j++) {
                for (int k = 1; k <= one.NumColumn; k++) {
                    add(result.v[i][j], one.v[i][k] * two.v[k][j] % MOD);
                }
            }
        }
        return result;
    
    }
    
    matrix power(matrix x, int n) {
        if (n == 1) return x;
        matrix tmp = power(x, n / 2);
        if (n % 2 == 0) return tmp * tmp;
        else return tmp * tmp * x;
    }
}