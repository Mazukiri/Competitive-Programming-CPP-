#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 1e6 + 5;
int n;
II A[N];

void sub75(){

    int ans = 0;

    for (int i = 1; i<=n-1; i++){
        for (int j = i+1; j<=n; j++){

            int tempValue = A[j].se - A[i].se;
            int tempCost = abs(A[j].fi - A[i].fi);
            ans = max(ans, tempValue - tempCost);
        }
    }

    cout << ans << '\n';
}

void subAC(){
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;
    
    for (int i = 1; i<=n; i++) {
        cin >> A[i].fi >> A[i].se;
        A[i].fi = A[i].fi - A[i-1].fi;
        A[i].se = A[i].se + A[i-1].se;
    }

    if (n<=5000) sub75();
    else subAC();
}