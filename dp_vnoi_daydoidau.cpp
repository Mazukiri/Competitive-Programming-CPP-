#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int n, U, L;
vector<int> Q(N, 1);
vector<int> P(N, 1);
int A[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> U >> L;
    for (int i = 1; i<=n; i++) cin >> A[i];

    for (int i = 2; i<=n; i++){
        for (int j = 1; j<i; j++){

            if (A[j] < A[i] && abs(i - j) >= L && abs(A[i] - A[j]) <= U){
                P[i] = max(P[i], P[j] + 1);
            }

            if (A[j] > A[i] && abs(i - j) >= L && abs(A[i] - A[j]) <= U){
                Q[i] = max(Q[i], Q[j] + 1);
            }
        }
    }

    int ans = 1;

    for (int i = 1; i<=n; i++) {
        ans = max(ans, max(Q[i], P[i]));
    }

    cout << ans;
}