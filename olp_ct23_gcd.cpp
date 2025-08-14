#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int a, b, M;

int fib(int x){
    
    if ((x == 1) || (x == 2)) return 1;
    
    int temp1 = 1, temp2 = 1, fib_x = 0;

    for (int i = 3; i<=x; i++){
        fib_x = temp1 + temp2;
        temp2 = temp1;
        temp1 = fib_x;
    }

    return fib_x;
}

void sub1(){

    int ans = gcd(fib(a), fib(b));
    ans %= M;
    
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> a >> b >> M;

    sub1();


    //Dung nhan ma tran de tinh not phan con lai
}