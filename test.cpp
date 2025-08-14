#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long A[N];


void sub1(long long n, long long k){
    
    for (int i = 1; i<=N; i++) A[i] = 0;

    for (int i = 1; i<=n; i++){
        
        long long l,r; 
        cin >> l >> r;
        A[l]++; 
        A[r+1]--;
    }

    for (int i = 2; i<=N; i++){
        A[i] = A[i-1] + A[i];
    }

    long long ans = 0;

    for (int i = 1; i<=1000000; i++) if (A[i] == k) ans++;

    cout << ans;
}

void sub2(long long n, long long k){

    long long left, right; cin >> left >> right; 


     for (int i = 2; i<=n; i++){
        
        long long l,r; 
        cin >> l >> r;
        left = max(left, l);
        right = min(right, r);
     }

     if (left>=right) cout << 0;
     if (left < right) cout << right - left + 1;

}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("DC.inp", "r")) {
        freopen("DC.inp", "r", stdin);
        freopen("DC.out", "w", stdout);
    }

    long long n, k; 
    cin >> n >> k;
    
    if (n != k) sub1(n, k); else sub2(n, k);
}