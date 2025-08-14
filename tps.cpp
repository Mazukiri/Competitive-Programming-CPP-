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

    vector<int> temp;

    for (int i = 1; i<=n-1; i++){

        for (int j = i+1; j<=n; j++){

            int ans = min((A[i] + (1000000 - A[j])/2), (A[i] + A[j])/2);
            temp.push_back(abs(ans - A[i] + 1));
        }
    }

    for (auto x: temp) cout << x << " ";
}