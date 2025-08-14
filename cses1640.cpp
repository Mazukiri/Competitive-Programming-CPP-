#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, x;
#define II pair<int,int>
#define fi first
#define se second
II A[N];  // store both value and original index

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cin >> A[i].fi;
        A[i].se = i;
    }

    // for (int i = 1; i <= n; i++) cout << A[i].first << " " << A[i].second << '\n';

    sort(A + 1, A + n + 1);  // sort by values

    // cout << '\n';

    // for (int i = 1; i <= n; i++) cout << A[i].first << " " << A[i].second << '\n';

    int left = 1, right = n;
    while (left < right) {
        int sum = A[left].fi + A[right].fi;
        if (sum == x) {
            cout << A[left].se << " " << A[right].se;
            return 0;
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }

    cout << "IMPOSSIBLE";
}
