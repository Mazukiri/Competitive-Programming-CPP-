#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
map<int, int> ans;
int A[N], B[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; cin >> n;
    for (int i = 1; i<=n; i++) cin >> A[i];
    for (int i = 1; i<=n; i++) B[i] = A[i];
    sort(A + 1, A + 1 + n);

    for (int i = 1; i<=n; i++) {
       if (A[i] == A[i-1]) ans[A[i]] = ans[A[i - 1]];
       else ans[A[i]] = i - 1;
    }

    for (int i = 1; i<=n; i++){
        cout << ans[B[i]] << " ";
    }

    
}