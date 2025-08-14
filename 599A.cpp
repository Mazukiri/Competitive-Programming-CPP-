#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int d1, d2, d3; cin >> d1 >> d2 >> d3;

    int min_path_to_1 = min(d1, d3 + d2);
    int min_path_to_2 = min(d3, d2 + d1);
    int min_path_to_home = min(d2, d3 + d1);
    int total_travel_path = min_path_to_1 + min_path_to_2 + min_path_to_home;
    
    cout << total_travel_path;
}