#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

int sumDigits(int n){

    int ans = 0;
    
    while (n>0){
        int temp = n%10;
        ans += temp;
        n /= 10;
    }

    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int a, b; cin >> a >> b;
    int x = __gcd(a, b);
    int ans = 0;

    for (int i = 1; i<=ceil(sqrt(x)); i++){
        if (x%i == 0){
            ans = max(ans, sumDigits(i));
            ans = max(ans, sumDigits(x/i));
        }
    }

    cout << ans;

}