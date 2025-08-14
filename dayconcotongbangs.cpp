#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int A[N];
int L[N];
int n, S;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("CANDY.inp", "r")) {
        freopen("CANDY.inp", "r", stdin);
        freopen("CANDY.out", "w", stdout);
    }

    cin >> n;

    S = 0;

    for (int i = 1; i<=n; i++) {
        cin >> A[i];
        S += A[i];
    }

    L[0] = 1;

    for (int i = 1; i<=n; i++){
        for (int t = S/2; t >= A[i]; t--){

            if (L[t - A[i]] == 1) L[t] = 1;
        }
    }

    int ans;

    for (int i = 1; i<=S/2; i++){

        if (L[i] == 1 && L[S - i] == 1) {
            ans = S - 2*i;
        }
    }

    cout << ans;

    


}