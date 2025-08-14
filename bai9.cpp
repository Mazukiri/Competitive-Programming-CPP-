#include <bits/stdc++.h>
using namespace std;

long long sum(long long l, long long r){
    
    if (l ==  r) return l;
    
    long long ans = (l+r);
    ans *= (r-l+1);
    ans /= 2;
    
    return ans;
}

void sub1(){
    long long ans = sum(l, r+1);
    long long indexAns = 0;

    for (int i = l; i<=r; i++){
        
        long long prevAns = ans;
        ans = min(ans, abs(sum(l, i) - sum(i+1, r)));
        if (prevAns != ans) indexAns = i;
    }

    cout << ans << " " << indexAns;
}

void sub2(){
    
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    
    long long l, r; cin >> l >> r;

    if (r<=1000) sub1();
    else sub2();

    

    
}