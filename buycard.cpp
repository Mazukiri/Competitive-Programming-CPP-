#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int C, p, n1, n2, t1, t2;

bool check(int num){
    //(p/n1)*t1 + (p/n2) *t2 <= C

    int totalFee = num * p;
    totalFee += ((num/n1) * t1);
    totalFee += ((num/n2) * t2);


    if (totalFee <= C) return true;
    return false;
}

int BS(){
    int l = 1, r = C/p;

    while (l<=r){
        int mid = (l+r)/2;

        if ((check(mid)) && (!check(mid + 1))) return mid;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    while (t--){
        cin >> C >> p >> n1 >> n2 >> t1 >> t2;
        int ans = BS(); //Binary Search
        cout << ans << '\n';
    }
}