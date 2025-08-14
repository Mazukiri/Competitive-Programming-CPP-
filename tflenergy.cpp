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

    if (fopen("ENERGY.inp", "r")) {
        freopen("ENERGY.inp", "r", stdin);
        freopen("ENERGY.out", "w", stdout);
    }

    cin >> n >> r >> k;

    for (int i = 1; i<=n; i++) {
        cin >> B[i];
    }

    for (int i = 1; i<=n; i++) {
        A[max(i - r, 1LL)] += B[i];
        A[min(i + r , n) + 1] -= B[i]; 
    }

    for (int i = 1; i<=n; i++) A[i] += A[i-1];

    // for (int i = 1; i<=n; i++) cout << A[i] << " ";


    int ans = 0;

    int left = 0, right = *max_element(A + 1, A + n +1) + k;

    while (left <= right) {
        int mid = left + right >> 1;

        int planted = check(mid);

        if (planted <= k) {
            ans = mid;
            left = mid + 1;
        }

        else {
            right = mid - 1LL;
        }
    }

    cout << ans;
}



