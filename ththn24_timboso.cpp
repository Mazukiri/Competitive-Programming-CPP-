#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

bool isPrime(int n){
    int sqrt_n = ceil(sqrt(n));
    
    for (int i = 2; i<=sqrt_n; i++) 
        if (n%i == 0) return false;
    
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    if (n == 1 || n == 0) {
        cout << 0;
        return 0;
    }

    if (n == -1){
        cout << 2;
        return 0;
    }

    if (n>0) {

        if (isPrime(n)){

            cout << abs(n - 1);
            return 0;
        }

        else {

            int ans = n + 20;

            int sqrt_n = ceil(sqrt(n));

            for (int i = 1; i<=sqrt_n; i++){

                if (n%i == 0){

                    int a = i;
                    int b = n/i;

                    ans = min(ans, abs(a - b));
                }
            }

            cout << ans;
            return 0;
        }
    }

    else {

        int abs_n = abs(n);

        if (isPrime(abs_n)){

            cout << abs_n + 1;
            return 0;
        }

        else {

            int sqrt_n = ceil(sqrt(abs_n));
            int ans = abs_n + 20;

            for (int i = 2; i<=sqrt_n; i++) {

                if (abs_n % i == 0){

                    int a = i;
                    int b = n/i;
                    ans = min(ans, abs(a - b));
                }
            }

            cout << ans;
            return 0;
        }
    }

    
}
