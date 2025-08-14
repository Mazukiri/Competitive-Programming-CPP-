#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int A[N], B[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
        int b;
        for (int i = 1; i<=n; i++) cin >> A[i];
        cin >> b;



        int flag = true;

        for (int i = 1; i<=n-1; i++) {
            if (A[i] > A[i+1]) flag = false;
        }

        if (flag) {
            cout << "YES";
            cout << '\n';
            continue;
        }

        flag = true;

        A[0] = -1000000000000;

        for (int i = 1; i<=n-1; i++) {
            if (A[i] <= A[i+1] && b - A[i] <= A[i + 1] && b - A[i] >= A[i - 1]) {
                A[i] = b - A[i];
            }

            if (A[i] <= A[i + 1] && b - A[i] > A[i + 1]) continue;

            if (A[i] > A[i + 1] && b - A[i] <= A[i + 1] && b - A[i] >= A[i - 1]) {
                A[i] = b - A[i];
            }
        }

        for (int i = 1; i<=n-1; i++) {
            if (A[i] > A[i+1]) flag = false;
        }

        if (flag) cout << "YES"; else cout << "NO";
        cout << '\n';


    }

    


}