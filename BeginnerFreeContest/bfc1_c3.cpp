#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int dem[N];
int A[N];


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n, k; cin >> n >> k;

    int ans = 0;

    for (int i = 1; i<=n; i++) {
        cin >> A[i];
        int sum = A[i] * A[i];
        if (dem[k - sum] != 0) ans += dem[k - sum];
        dem[A[i]]++;
    }

    cout << ans;


    
}