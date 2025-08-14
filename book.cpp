#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int A[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; cin >> n; 
    int sum = 0;

    for (int i = 1; i<=n; i++) 
    {
        cin >> A[i];
        sum += A[i];
    }



    sort(A + 1, A + n + 1, greater<int>());

    for (int i = 1; i<=n; i++) 
    {
        cout << A[i] << " ";
    }

    cout << '\n';

    for (int i = 1; i<=n; i++){
        
        if (i%3 == 0) sum -= A[i];
    }

    cout << sum;
}