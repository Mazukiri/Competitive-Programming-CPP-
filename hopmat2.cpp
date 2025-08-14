#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first 
#define se second
#define ii pair<ll,ll>

struct thuephong{
    
    long long x, y, z;
};


const long long N = 1e6+5;
thuephong A[N];
ll DP[N];

bool cmp(thuephong a, thuephong b){
    return a.y < b.y;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    int n; cin >> n;
    for (int i = 1; i<=n; i++) {
        cin >> A[i].x >> A[i].y >> A[i].z; 
    }

    sort(A + 1, A+n+1, cmp);
    
    for (int i = 1; i<=n; i++) DP[i] = A[i].z;

    

    //DP[i] = Tổng số tiền nhiều nhất khi tổ chức xong cuộc họp thứ i
    //VD: Tại cuộc họp thứ 7 sau khi sắp xếp, có thể có nhiều cuộc họp đã được thực hiện trước đó
    //DP[i] = max(dp[i], dp[j] + A[i].z) để tính xem có thể tổ chức tối đa bao nhiêu cuộc họp trước cuộc họp i

    for (int i = 2; i<=n; i++){
        for (int j = 1; j<i; j++){
            //neu cuoc hop j co the sap xep truoc cuoc hop i
            if (A[j].y <= A[i].x) {
                DP[i] = max(DP[i], DP[j] + A[i].z);
        }
    }
}

    ll ans = 0;

    for (int i = 1; i<=n; i++) {
        ans = max(DP[i], ans);
    }

    cout << ans;

    
       
    
}