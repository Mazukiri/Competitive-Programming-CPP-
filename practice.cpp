#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 1e6 + 5;
int n, c; 
II A[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> c;

    for (int i = 1; i<=n; i++){
        cin >> A[i].fi >> A[i].se;
    }

    sort(A + 1, A + 1 + n);

    int ans = 0;

    for (int i = 1; i<=n; i++){
        if (c>=A[i].fi){
            ans++;
            c += A[i].se;
        }
    }

    cout << ans;

    
}