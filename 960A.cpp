#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    while (t--){

        int n; cin >> n;
        int A[n];

        for (int i = 0; i<n; i++) cin >> A[i];
        sort(A, A+n);

        for (int i = n-1; i>=0; i = i - 2){
            
            if (i == 0) {
                cout << "YES" << '\n'; 
                break;
            }

            if ((i-1 == 0) && (A[i-1] < A[i])) {
                cout << "YES" << '\n';
                break;
            }

            if ((i-1 == 0) && (A[i-1] >= A[i])) {
                cout << "NO" << '\n';
                break;
            }


            int Alice = A[i];
            int Bob = A[i-1];
        

            if (Alice > Bob) {
                cout << "YES" << '\n';
                break;
            }

            else if (Alice < Bob) {
                cout << "NO" << '\n';
                break;
            }        
    }
}
}