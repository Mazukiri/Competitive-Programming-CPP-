#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
string S[N];
int n;

bool isNegative(string s){
    if (s[0] == '-') return true;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    int cntNegative = 0, cntPositive = 0;

    for (int i = 1; i<=n; i++) {
        cin >> S[i];
        if (S[i] == "0") continue;
        if (isNegative(S[i])) cntNegative++;
        else cntPositive++;
    }

    cout << cntNegative << " " << cntPositive;
}