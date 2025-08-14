#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

void solve1(int n, int a, int b, int c)  {

    int ans = 0;


    for (int i = 1; i <= n; i++) {

        if ((i % a == 0 || i % b == 0) && (i % c != 0)) ans += (n/i);
    }

    cout << ans << '\n';
}

int calc(int n) {

    int ans = 0;

    for (int i = 1; i <= sqrt(n); i++) {
        ans += i * (n/i - n/(i + 1)); 
        if (i * i != n) ans += n/i;
    }

    // 5 3 2 2 1 
    // 2 * (5 - 3) + 3 *(3 - 2) + 4 * (2 - 2) = 4 + 3 + 10 + 5 

    return ans;
}



signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int q; cin >> q;

    for (int i = 1; i <= q; i++) {
        int n, a, b, c;
        // cin >> n >> a >> b >> c;
        //solve(n, a, b, c);
    }

    /*
    
    
    */

    cout << calc(9) << " ";
}
