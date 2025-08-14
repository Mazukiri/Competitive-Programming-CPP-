#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    // for (int i = 1; i<n; i++){
    //     if (i%2 == 0) sochan++; else sole++;
    // }

    // cout << sochan << " " << sole;

    //2 = 2
    //3 = 3
    //4 = 2 + 2
    //5 = 2 + 3
    //6 = 2 + 2 + 2
    //7 = 2 + 2 + 3
    //8 = 2 + 2 + 2 + 2
    //9 = 2 + 2 + 2 + 3
    //10 = = 2 + 2 + 2 + 2 + 2
    //11 = = 2 + 2 + 2 + 2 + 3
    //12 = 2 + 2 + 2 + 2 + 2 + 2
    //13 =  2 + 2 + 2 + 2 + 2 + 3

    //Neu so do la so chan -> n/2 so 2
    //Neu so do la so le -> 1 so 3 va (n-3)/2 so 2

    int n; cin >> n;

    int nums2 = 0;
    int countFactors = 0;

    if (n%2 == 0) {
        nums2 = n/2;
        countFactors = nums2;
    }

    else {
        nums2 = (n-3)/2;
        countFactors = nums2 + 1;
    }


    cout << countFactors << '\n';
    
    for (int i = 1; i<=nums2; i++) cout << 2 << " ";
    if (n%2 != 0) cout << 3;
}