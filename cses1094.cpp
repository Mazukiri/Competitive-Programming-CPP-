#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int A[N];
int n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i<=n; i++) cin >> A[i];

    int moves = 0;

    for (int i = 2; i<=n; i++) {
        if (A[i] <  A[i-1]) {
            moves += abs(A[i] - A[i-1]);
            A[i] = A[i-1];
    }}

    cout << moves;
}