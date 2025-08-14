/*
The overall problem requires us to count how many number that has value x also exsits x times
in a specific range [l, r]. 
We realize that there will be at most sqrt(n) distinct value, hence:
- We create a cnt[value] that count the apperances of a value. If the value > cnt[value],
we'll simply discard the number. Hence, the number that we will have to build the prefixSum
will be at most O(sqrt(n)) and range from [1, n].
The complexity will be closed to n * sqrt(n) ~ 10^8, hence we should pay attention while implementing
Bad practices such as #define int long long, ... should be discarded to lower the mem req!

- For all value x that occurs at least x times in the range [1, n], we should divide them into
blocks. Blocks storing will be 2D vector: On the first dimession, we store a number that represents
a possible value (any value x >= cnt[x]). On the second dimension, we'll store the range [1, n] as 
a prefixSum of occurences.

- Therefore, the query will be handled by utilizing the prefixSum of occurences of all the possible
values that we've built.
*/

#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, q;
int A[N];
int value[N];
int cnt[N];
vector< vector<int> > prefixSum;
vector<int> appearances;
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
 
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] <= n) cnt[A[i]]++;
    }
  
    //prefixsum
    for (int i = 1; i <= n; i++) {
        if (i > cnt[i]) continue;
 
        appearances.push_back(i);
        
        prefixSum.push_back(vector<int>(n + 5));
        
        for (int j = 1; j <= n; j++) {
            prefixSum.back()[j] = prefixSum.back()[j - 1] + (A[j] == i);
        }
    }
 
    //
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        int ans = 0;
        for (int index = 0; index < appearances.size(); index++) {
            if (prefixSum[index][r] - prefixSum[index][l - 1] == appearances[index]) ans++;
        }
        cout << ans << '\n';
    }
 
    string x = "ódajkods" -> f(x) -> "132"
    #has
}