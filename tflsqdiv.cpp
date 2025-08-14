#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
const int INF = 1e18 + 7;
int n, r, k;
int A[N], B[N];
int prefixSum[N];

int check(int x) {
    
    memset(prefixSum, 0, sizeof prefixSum);

    int plantedStation = 0;
    int currStation = 0;
    
    for (int i = 1; i <= n; i++) {
        prefixSum[i] += prefixSum[i - 1];

        if (A[i] + prefixSum[i] < x) {
            
            currStation = x - A[i] - prefixSum[i];
            prefixSum[i] += currStation;
            prefixSum[min(i + 2*r + 1, n + 1)] -= currStation;
            plantedStation += currStation;
            if (plantedStation > k) return k+1;
        }
    }

    return plantedStation;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("SQDIV.inp", "r")) {
        freopen("SQDIV.inp", "r", stdin);
        freopen("SQDIV.out", "w", stdout);
    }

    cin >> n;

    for (int i = 2; i<=round(sqrt(n)); i++) {
        if (n % (i * i) == 0) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    
}



