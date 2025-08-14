#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int t;
string A[N];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> t;

    for (int i = 1; i<=t; i++) cin >> A[i];

    int ans = 0;

    for (int i = 1; i<=t; i++) {
        int currAns = 0;
        
        while (A[i] == "ONLINE") {
            currAns++;
            i++;
        }
        
        ans = max(ans, currAns);
    }

    cout << ans;
}

