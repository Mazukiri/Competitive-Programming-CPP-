#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, t;
int A[N];
int prefixSum[N];
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> t;

    for (int i = 1; i<=n; i++) cin >> A[i];    
    for (int i = 1; i<=n; i++) prefixSum[i] = prefixSum[i-1] + A[i];

    int ans = 0;

    int l = 1, r = 1;

    while (r <= n){

        while (r <= n && prefixSum[r] - prefixSum[l-1]  < t) r++;

        if (r <= n){
            ans += (abs(n - r) + 1);
            l++;
        }
    }
    cout << ans;
}