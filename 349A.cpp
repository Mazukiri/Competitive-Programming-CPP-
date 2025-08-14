#include <bits/stdc++.h>
using namespace std;
long long A[1000005];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    long long n; cin >> n;

    for (int i = 1; i<=n; i++) cin >> A[i];

    long long balance = 0;

    for (int i = 1; i<=n; i++){

        if (A[i] == 25) balance+=A[i];
        if (A[i] == 50 || A[i] == 100) balance = balance - (A[i] - 25);
        if (balance >= 0) balance += A[i];
    }

    if (balance >=0) cout << "YES"; else cout << "NO";
}