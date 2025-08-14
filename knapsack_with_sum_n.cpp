#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
const int N = 25;
int n, T;
int A[N];
int cnt[N];
vector<int> occurences;
char f[N];

int gcd(int a, int b) {
    return __gcd(a, b);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> T;
    
    for (int i = 1; i <= T; i++) f[i] = '0';

    int t = 0;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (cnt[A[i]] == 0) {
            occurences.push_back(A[i]);
        }

        cnt[A[i]]++;
        //f[A[i] * cnt[A[i]]] = '1';

        t+= A[i];

    }

    for (int i = 1; i <= T; i++) cout << i << " " << f[i] << '\n';
    cout << '\n';

    f[0] = '1';

    
    for (int currValue : occurences) {            
            
        for (int value = currValue; value <= t; value++) {
            if (f[value - currValue] == '1') f[value] = '1';
        }
    }
    

    string ans = "";

    for (int i = 1; i <= T; i++) ans += f[i];

    cout << ans;


}