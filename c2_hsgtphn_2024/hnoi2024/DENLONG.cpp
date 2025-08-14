#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, K, X;
int A[N];

void sub1() {

    int ans = 0;

    for (int i = 1; i<=n; i++) {

        int vaccancyLeft = K;

        for (int j = i + 1; j<=n; j++) {
            if (A[j] != A[i] && vaccancyLeft > 0) vaccancyLeft--;
            if (A[j] != A[i] && vaccancyLeft == 0) {
                ans = max(ans, j - i);
            }
        }

        if (vaccancyLeft > 0) ans = max(ans, n - i + 1);
    }

   cout << ans;
}

void sub2(){
        
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("DENLONG.inp", "r")) {
        freopen("DENLONG.inp", "r", stdin);
        freopen("DENLONG.out", "w", stdout);
    }

    cin >> n >> K >> X;
    for (int i = 1; i<=n; i++) cin >> A[i];

    sub1();
    

        
}