#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("MAXPRO.inp", "r")) {
        freopen("MAXPRO.inp", "r", stdin);
        freopen("MAXPRO.out", "w", stdout);
    }

    
    // cout << -2 % 5 << '\n';


    int a, b, c, M;
    cin >> a >> b >> c >> M;

    int largerThan0 = 0;

    if (a > 0) largerThan0++;
    if (b > 0) largerThan0++;
    if (c > 0) largerThan0++;

    if (largerThan0 == 3) {
        a = abs(a % M); 
        b = abs(b % M); 
        c = abs(c % M); 

        

        int ans = (a * b) % M;
        ans = max(ans, (a * c) % M);
        ans = max(ans, (b * c) % M);
        return cout << ans, 0;
    }

    if (largerThan0 == 2) {
        if (a >= 0 && b >= 0) cout << (a % M) * (b % M) % M;
        if (a >= 0 && c >= 0) cout << (a % M) * (c % M) % M;
        if (c >= 0 && b >= 0) cout << (c % M) * (b % M) % M;
        return 0;
    }

    if (largerThan0 == 1) {
        if (a <= 0 && b <= 0) cout << (a % M) * (b % M) % M;
        if (a <= 0 && c <= 0) cout << (a % M) * (c % M) % M;
        if (c <= 0 && b <= 0) cout << (c % M) * (b % M) % M;
        return 0;
    }

    if (largerThan0 == 0) {
        int smallerThan0 = 0;

        if (a < 0) smallerThan0++;
        if (b < 0) smallerThan0++;
        if (c < 0) smallerThan0++;

        if (smallerThan0 >= 2) {
            
            a = abs(a), b = abs(b), c = abs(c);
            
            a = abs(a % M); 
            b = abs(b % M); 
            c = abs(c % M); 

            

            int ans = (a * b) % M;
            ans = max(ans, (a * c) % M);
            ans = max(ans, (b * c) % M);
            return cout << ans, 0;        
        }

        if (smallerThan0 == 1) {
            cout << 0;
        }
        
    }

    
}