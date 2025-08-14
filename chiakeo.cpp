#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
int A[N];
int L[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    int t = 0;

    for (int i = 1; i<=n; i++) {
        cin >> A[i];
        t += A[i];
    }

    L[0] = 1;

    for (int i = 1; i<=n; i++)
        for (int j = t; j>=A[i]; j--){

            if (L[j - A[i]] == 1) L[j] = 1;
    }

    int ans = t + 20;

    for (int i = 1; i<=t; i++){
        if (L[t - i] == 1 && L[i] == 1){

            int a = t - i;
            int b = i;

            ans = min(ans, abs(a- b));
        }
    }

    cout << ans;

    
}