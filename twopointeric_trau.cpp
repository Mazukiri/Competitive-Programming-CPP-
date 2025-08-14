#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m;
int A[N], B[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    //Dem bao nhieu cap A[i] == B[j]

    cin >> n >> m;

    int countPairs = 0;

    for (int i = 1; i<=n; i++) cin >> A[i];
    for (int i = 1; i<=m; i++) cin >> B[i];

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){

            if (A[i] == B[j]) countPairs++;
        }
    }

    cout << countPairs;


}