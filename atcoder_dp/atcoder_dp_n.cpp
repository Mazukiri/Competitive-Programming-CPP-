// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6 + 5;
// int n;
// vector<ll> v;

// signed main() {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     if (fopen("_ab.inp", "r")) {
//         freopen("_ab.inp", "r", stdin);
//         freopen("_ab.out", "w", stdout);
//     }

//     cin >> n;

//     for (int i = 1; i <= n; i++) {
//         ll x; cin >> x;
//         v.push_back(x);
//         if (n == 1) {
//             cout << x;
//             return 0;
//         }
//     }



//     ll ans = 0;
    

//     for (int index = 0; index < 400 && v.size() > 1; index++) {
        
//         ll currCost = v[0] + v[1];
//         int currIndex = 0, currNextIndex = 1;

//         for (int i = 0; i < v.size() - 1; i++) {
            
//             if (v[i] + v[i + 1] < currCost) {
//                 currCost = v[i] + v[i + 1];
//                 currIndex = i; 
//                 currNextIndex = i + 1;
//             }
//         }

//         ans += currCost;
//         v[currIndex] += v[currNextIndex];
//         v.erase(v.begin() + currNextIndex);
//     }

//     cout << ans;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
int n;
ll dp[N][N];
ll prefix[N], A[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        prefix[i] = A[i] + prefix[i - 1];
    }

    //Init base case dp[i][i]
    for (int i = 1; i <= n; i++) dp[i][i] = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + prefix[j] - prefix[i - 1]);
            }
        }
    }

    cout << dp[1][n];
}