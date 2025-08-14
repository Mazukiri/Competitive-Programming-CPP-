#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
int A[N];

string finish_Time(int x){

    if (x<10) {

        string ans = "08:0";
        ans += to_string(x);
        return ans;
    }

    if (x>=10 && x<=59) {

        string ans = "08:";
        ans +=to_string(x);
        return ans;
    }

    if (x>=60 && x<=69){

        string ans = "09:0";
        ans += to_string(x%60);
        return ans;
    }

    else {

        string ans = "09:";
        ans += to_string(x%60);
        return ans;
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("TG.inp", "r")) {
        freopen("TG.inp", "r", stdin);
        freopen("TG.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i<=n; i++) {
        cin >> A[i];
        cout << finish_Time(A[i]) << '\n';
    }
    

    
}