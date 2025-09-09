#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int A, B;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> A >> B;

    int sqrtA = ceil(sqrt(A));
    int sqrtB = floor(sqrt(B));

    cout << (B - A + 1) - (sqrtB - sqrtA + 1);

    
} 