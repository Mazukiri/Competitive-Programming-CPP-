#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
#define ll long long 
using namespace std;
const int N = 1e6 + 5;
int n;
bool isPrime[N];
vector<int> primeIndex;

ll A[N], prefix[N];

void prepprocess() {

    memset(isPrime, true, sizeof isPrime);

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            for (int j = 2; j < N/i; j++) isPrime[i * j] = false;
            primeIndex.push_back(i);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i =1 ; i <=n; i++) {
        cin >> A[i];
        prefix[i] += (prefix[i - 1] + A[i]);
    }

    prepprocess();

    ll ans = -INFINITY, minL = prefix[1];

    //cout << ans << '\n';


    for (int i = 0; i < primeIndex.size(); i++) {
        if (primeIndex[i] > n) {
            break;
        }

        minL = min(minL, prefix[primeIndex[i] - 1]);
        ans = max(ans, prefix[primeIndex[i]] - minL);
    }

    cout << ans;

    
    //for (int i = 0; i < 10; i++) cout << primeIndex[i] << " ";

}