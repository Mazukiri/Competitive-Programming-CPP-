#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n){

    for (int i = 2; i<=round(sqrt(n)); i++) if (n%i == 0) return false;
    return true;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    if (fopen("dp.inp", "r")) {
            freopen("dp.inp", "r", stdin);
            freopen("dp.out", "w", stdout);
        }
    
    int n; cin >> n;
    int A[n+1];

    for (int i = 1; i<=n; i++) cin >> A[i];


    long long max_ = A[1];
    long long index_lon_nhat_max = 1;

    for (int i = 2; i<=n; i++){
        if (max_<=A[i]){
            max_ = A[i];
            index_lon_nhat_max = i;
        }
    }

    long long min_ = A[1];
    long long index_lon_nhat_min = 1;

    for (int i = 2; i<=n; i++){
        if (min_>=A[i]){
            min_ = A[i];
            index_lon_nhat_min = i;
        }
    }

    cout << max_ << " " <<index_lon_nhat_max << '\n';
    cout << min_ << " " <<index_lon_nhat_min << '\n';

    

    
}