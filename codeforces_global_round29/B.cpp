#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    // 1 2 3 2 1 3
    // 1 2 3 4 2 3 1 4
    // 1 2 3 4 5 3 2 4 1 5
    // 1 2 3 4 5 6 

    int n; cin >> n;

    for (int i = n; i >= n/2; i--) {
        nums[i] = i;
        nums[i * 2] = i;
    }
}