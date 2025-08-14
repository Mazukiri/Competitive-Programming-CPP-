#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k;
int A[N], prefixSum[N];
//prefixSum[i] = A[1] + A[2] + ... + A[i]


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> k;

    for (int i = 1; i<=n; i++) cin >> A[i];
    
    //init prefixSum arr
    for (int i = 1; i<=n; i++) prefixSum[i] = prefixSum[i-1] + A[i];

    int ans = 0;

    for (int i = k; i<=n; i++){
        
        ans = max(ans, prefixSum[i] - prefixSum[i - k]);
    }

    cout << ans;
    



    
}