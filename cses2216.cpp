#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n;
int A[1000005];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i<=n; i++) cin >> A[i];

    int ans = 0;
    int curr;
    for (int i = 1; i<=n-1; i++){
        curr = A[i];
        if (curr > A[i+1]) ans++;
    }

    cout << ans;
}