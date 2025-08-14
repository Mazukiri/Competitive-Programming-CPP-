#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    int n; cin >> n;

    long long A[n+2]; //A[0] va A[n+1]

    A[0] = 10000000000; 
    A[n+1] = 10000000000;

    for (int i = 1; i<=n; i++) cin >> A[i];
    sort(A+1, A+n+1);

    for (int i = 1; i<=n; i++){
        //mini = so sanh A[i]-A[i-1] va A[i+1]-A[i]
        long long mini = min(abs(A[i] - A[i+1]), abs(A[i] - A[i-1]));
        long long maxi = max(abs(A[i] - A[1]), abs(A[i] - A[n]));
        cout << mini << " " << maxi << '\n';
    }


    
}