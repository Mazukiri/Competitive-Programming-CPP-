#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }s

    int t; cin >> t;

    for (int i = 1; i<=t; i++){

        long long a, b, c; cin >> a >> b >> c;
        long long n; cin >> n;

        long long max_xu = max(max(a,b), c);

        n = n - (max_xu - a);
        n = n - (max_xu - b);
        n = n - (max_xu - c);

        if ((n%3 == 0 && (n>=0))) cout << "YES" << '\n'; else cout << "NO" << '\n';
   
    }
    
}