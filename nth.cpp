#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int a, b, N;

int check(int x){
    
    int ans = x/a;
    ans += (x/b);
    
    int lcm = a*b/__gcd(a, b);
    
    ans -= (x/lcm);

    return ans;
}

int BS(){

    int l = 1, r = max(a, b) * N;

    int ans = 0;

    while (l<=r){
        int mid = (l+r)/2;

        if (check(mid) >= N){
            ans = mid;
            r = mid - 1;
        }

        else l = mid+1;
    }

    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    while (t--){
        cin >> a >> b >> N;
        int ans = BS();
        cout << ans << '\n';
    }    
}