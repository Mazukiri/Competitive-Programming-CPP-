#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

bool isPrime(int x){

    if (x <= 1) return false;
    
    //truncc, ceil, round, ...
    for (int i = 2; i<=round(sqrt(x)); i++){
        if (x % i == 0) return false;
    }

    return true;
}

bool checkPerfectPrime(int n){

    if (!isPrime(n)) return false;

    int sumDigits = 0;

    while (n > 0){
        int digit = n%10;
        if (!isPrime(digit)) return false;
        
        sumDigits += digit;

        n = n /10;
    }

    if (!isPrime(sumDigits)) return false;

    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    /*
    - Bản thân số n là số nguyên tố
    - Tổng các chữ số của nó là số nguyên tố
    - Từng số một là số nguyên tố
    */

    int a, b; cin >> a >> b;

    int ans = 0;

    for (int i = a; i<=b; i++){

        if (checkPerfectPrime(i)) {
            cout << i << '\n';
            ans++;
        }
    }

    cout << ans;

}