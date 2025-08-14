#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int pre[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int x; cin >> x;

    for (int i = 1; i<=x; i++) {
        pre[i] = pre[i-1] + i;
    }

    vector<int> sums;

    for (int i = 1; i<=x; i++){
        for (int j = 0; j<i; j++) {
            sums.push_back(pre[i] - pre[j]);
        }
    }

    for (int i = 0; i<sums.size(); i++) cout << sums[i] << " ";
}