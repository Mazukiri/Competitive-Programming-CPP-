#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

int bs(int value){

    int left = 1, right = n;

    while (left <= right) {

        int mid = (left + right)/2;

        if (A[mid])
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;
    
    for (int i = 1; i<=n; i++) cin >> A[i];
    for (int i = 1; i<=n; i++) B[i] = A[i];
    
    sort(A + 1, A + 1 + n);

    int index = 1;
    int ans = 0;

    for (int i = 1; i<=n; i++){

        int ansIndex = bs(A[i]);
    }

    

}