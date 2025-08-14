#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int dp[N]; //dp[i]: Số tiền tối đa thu được tại cuộc họp i

struct person{
    int a;
    int b;
    int c;
};

bool cmp(person x, person y){
    return x.a < y.a;
}

bool canTake(person x, person y){
    
    if (x.b <= y.a) return true;
    return false;
}

person A[N];

int n; 



signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i<=n; i++) {
        cin >> A[i].a >> A[i].b >> A[i].c;
    }

    sort(A + 1, A + n + 1, cmp);

    for (int i = 1; i<=n; i++){
        dp[i] = A[i].c;
    }

    // for (int i = 1; i<=n; i++) cout << A[i].a << " " << A[i].b << " " << A[i].c << '\n';

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<i; j++){

            if (canTake(A[j], A[i])) dp[i] = max(dp[i], dp[j] + A[i].c);
        }
    }

    int ans = 0;

    for (int i = 1; i<=n; i++) ans = max(ans, dp[i]);

    cout << ans;
    
}