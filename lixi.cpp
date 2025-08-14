#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 1e6 + 5;
II A[N];
int n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n; 

    for (int i = 1; i<=n; i++) cin >> A[i].se >> A[i].fi;
    sort(A + 1, A + 1 + n, greater<II>());
    // for (int i = 1; i<=n; i++) cout << A[i].fi << " " << A[i].se << '\n';

    int chances = 1, ans = 0;

    for (int i = 1; i<=n; i++){
        
        if (chances > 0){
            ans += A[i].se;
            chances = chances + A[i].fi - 1;
        }
    }

    cout << ans;
}