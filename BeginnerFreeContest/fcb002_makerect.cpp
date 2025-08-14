#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
int A[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i<=n; i++) cin >> A[i];

    sort(A + 1, A + 1 + n);

    int chieudai = 0, chieurong = 0;

    for (int i = n; i > 1; i--) {
        if (A[i] == A[i-1] && chieudai == 0) {
            chieudai = A[i];
            i -= 2;
        }

        if (A[i] == A[i-1] && chieudai != 0) {
            chieurong = A[i];
            break;
        }
    }

    cout << chieudai * chieurong;


    
}