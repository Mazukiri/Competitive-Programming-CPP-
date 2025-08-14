#include <bits/stdc++.h>
using namespace std;
long long Factorial[100]; //F[i] = i!
//F = Factorial[i]

long long gt(int n){

    long long ans = 1;

    for (int i = 1; i<=n; i++) ans*=i;
    return ans;
}

bool check(int n){

    long long value = n;
    long long ans = 0;
    
    //phantichso
    while (n>0){

        int digit = n%10;
        ans += Factorial[digit];
        n = n/10;
    }

    return (ans == value);
}


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    int a,b; cin >> a >> b;
    
    //init F[i]
    for (int i = 1; i<=9; i++) Factorial[i] = gt(i);

    //khoi tao bien dem ket qua
    long long ans = 0;

    //kiem tra tu a --> b co bao nhieu so thoa man ham check
    for (int i = a; i<=b; i++) {
        
        if (check(i)) cout << i <<" ";
    }
    
}