#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first 
#define se second
#define ii pair<ll,ll>

const long long N = 1e6+5;
ii A[N];
ll DP[N];

bool cmp(ii a, ii b){
    return a.se < b.se;

}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    int n; cin >> n;
    
    //So cuoc hop toi thieu tai cuoc hop thu i la 1
    for (int i = 1; i<=n; i++) DP[i] = 1;

    for (int i = 1; i<=n; i++) {
        cin >> A[i].fi >> A[i].se;
    }

    sort(A + 1, A+n+1, cmp);

    //DP[i] = Số cuộc họp đã hoàn tới cuộc họp thứ i
    //VD: Tại cuộc họp thứ 7 sau khi sắp xếp, có thể có nhiều cuộc họp đã được thực hiện trước đó
    //DP[i] = max(dp[i], dp[j] + 1) để tính xem có thể tổ chức tối đa bao nhiêu cuộc họp trước cuộc họp i

    for (int i = 2; i<=n; i++){
        for (int j = 1; j<i; j++){
            //neu cuoc hop j co the sap xep truoc cuoc hop i
            if (A[j].second <= A[i].first) DP[i] = max(DP[i], DP[j] + 1);
        }
    }

    ll ans = 0;

    for (int i = 1; i<=n; i++) ans = max(DP[i], ans);

    cout << ans;

    
    
}