#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
vector<II> tasks;

bool cmp(II a, II b){
    
    if (a.fi == b.fi){
        return a.se < b.se;
    }

    return a.fi > b.fi;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; cin >> n;

    for (int i = 1; i<=n; i++){
        int ket_thuc, point; 
        cin >> point >> ket_thuc;
        tasks.push_back({point, ket_thuc});
    }

    sort(tasks.begin(), tasks.end(), cmp);

    for (int i = 0; i<tasks.size(); i++) cout << tasks[i].fi <<  " " << tasks[i].se << '\n';

    int time = 0;
    int ans = 0;

    for (int i = 0; i<tasks.size(); i++){
        if (time <= tasks[i].se) {
            //Co the them cong viec nay vao
            ans += tasks[i].fi;
            time++;
        }
    }

    cout << ans;

}