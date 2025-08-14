#include <bits/stdc++.h>
using namespace std;
#define int long long

int mu(int base, int exp){

    if (exp == 0) return 1;
    if (exp == 1) return base;

    int t = mu(base, exp/2);

    if (exp % 2 == 0) return t*t;
    else return t*t*base;
} 

int cnp(int base, int target){

    int left = 1;
    int right = 60;

    while (left <= right){

        int mid = (left + right)/2;

        if (mu(base, mid) == target) return mid;
        if (mu(base, mid) < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

bool isPrime(int n){
    for (int i = 2; i<=ceil(sqrt(n)); i++) {
        if (n%i == 0) return false;
    }

    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; 

    while (cin >> n){

        if (n == 0) return 0;

        int record = 0;

        if (isPrime((n))) {
            cout << 1 << '\n';
            continue;
        }

        for (int base = 2; base<=ceil(sqrt(n)); base++) {

            int exp = cnp(base, n);
            if (exp == -1) continue;
            else {
                cout << exp << '\n';
                record++;
                break;
            }
        }

        if (record == 0) cout << 1 << '\n';
    }
    
}