#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m;
int A[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m; 
    for (int i = 1; i<=n; i++) cin >> A[i];

    for (int i = 1; i<=n; i++){
        
        if (A[i] <= m) A[i] = i;

         
    }

    for (int i = 1; i<=n; i++) cout << A[i] << " ";


}