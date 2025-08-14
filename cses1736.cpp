#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q;
int A[N];

int getSum(int l, int r) {
    int sum = 0;
    
    for (int i = l; i<=r; i++) sum += A[i];
    return sum;
}

void update(int l, int r) {

    int currRunningSum = 1;

    for (int i = l; i<=r; i++) {
        A[i] +=currRunningSum;
        currRunningSum++;
    }
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;
    
    for (int i = 1; i<=n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i<=q; i++) {
        int typ, l, r; cin >> typ >> l >> r;
        if (typ == 1) {
            
            update(l, r);
        }

        else cout << getSum(l, r) << '\n';
    }
} 