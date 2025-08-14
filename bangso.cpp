#include <bits/stdc++.h>
using namespace std;
long long n, x;
const long long N = 1e6 + 5;
bool visited[N];

void sub1(){
    
    long long ans = 0;
    
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++) if (i*j == x) ans++;
    }

    cout << ans;
}

void sub2(){

    long long ans = 0;

    //visited[i] = false 
    for (int i = 1; i<=n; i++) visited[i] = false;

    //loop through to count
    for (int i = 1; i<=n; i++){
        
        if (((x%i == 0) && (x/i <=n)) && (!visited[i]) && (!visited[x/i])){
            
            if (x/i != i) ans += 2; else ans += 1;
            visited[i] = true;
            visited[x/i] = true;
        } 
    }

    cout << ans;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("BS.inp", "r")) {
        freopen("BS.inp", "r", stdin);
        freopen("BS.out", "w", stdout);
    }

     cin >> n >> x;
     if (n<=1000) sub1(); else sub2();
}