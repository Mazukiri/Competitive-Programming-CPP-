#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
int n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    vector<II> movies;


    for (int i = 1; i<=n; i++) {
        int start, end;
        cin >> start >> end;
        movies.push_back({start, 1});
        movies.push_back({end, -1});

    }

    sort(movies.begin(), movies.end());

    int actualFilms = 0;

    int ans = 0;

    for (int i = 0; i<movies.size(); i++){

        actualFilms += movies[i].se;
        if (actualFilms == 1) ans++;
    }

    cout << ans;
}