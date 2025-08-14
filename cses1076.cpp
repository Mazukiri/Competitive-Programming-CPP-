#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
int n, k;
vector<int> v;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int median, median1, median2, left, right;

    for (int i = 1; i <=k; i++) {
        v.push_back(A[i - 1]);
    }

    if (k == 1) return
    if (k == 2 ) return 
    if (k > 2 && k % 2 == 1) {
        median = v[v.size() / 2];
        medianRight = v[v.size()/2 + 1];
        medianLeft = v[v.size()/2 - 1];
        left = right = v.size()/2 - 0;
    }

    

    
}