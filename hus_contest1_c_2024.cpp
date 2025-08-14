#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int A[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    while (t--){
        int n; cin >> n;

        int C[n+1], D[n+1];

        //There are two ways to form a sequence
        //We may pick A[1] is min(1, B[1]) and pick A[2] = max(1, B[2]) and vice versa
        
        for (int i = 1; i<=n; i++) cin >> A[i];

        int ans1 = 0, ans2 = 0;

        for (int i = 1; i<=n; i++){

            if (i % 2 == 0) {
                C[i] = A[i];
                D[i] = 1;
            }

            else {
                C[i] = 1;
                D[i] = A[i];
            }
        }

        //Find what is the right case
        for (int i = 2; i<=n; i++){
            ans1 += abs(C[i] - C[i-1]);
            ans2 += abs(D[i] - D[i-1]);    
        }

        cout << max(ans1, ans2) << '\n';

    }
}