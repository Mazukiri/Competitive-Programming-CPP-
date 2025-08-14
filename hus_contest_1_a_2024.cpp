#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int A[N];
int prefix[N];
int hasOccur[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    while (t--) {
        int d, n; cin >> d >> n;

        for (int i = 1; i <= n; i++) cin >> A[i];

        // Calculate sums of all possible prefixes
        prefix[0] = 0; // Initialize prefix sum for empty prefix
        for (int i = 1; i <= n; i++) {
            prefix[i] = (prefix[i - 1] + A[i]) % d;
        }

        int ans = 0;
        for (int i = 1; i<=n; i++){

            hasOccur[i] = -1;
        }

        // Initially, add the prefix sum 0 at index 0
        hasOccur[0] = 0;

        for (int i = 1; i <= n; i++) {
            
            if hasOccur[i] = 
        }

        cout << ans << '\n';
    }
}
