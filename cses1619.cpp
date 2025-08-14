#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    vector<pair<int, int>> customers;

    for (int i = 1; i<=n; i++) {
        int start, end;
        cin >> start >> end;
        customers.push_back({start, 1});
        customers.push_back({end, -1});
    }

    sort(customers.begin(), customers.end());

    // for (int i = 0; i < customers.size(); i++){
    //     cout << customers[i].first << " " << customers[i].second << '\n';
    // }

    int actualCustomers = 0;
    int maxCustomers = 0;

    for (int i = 0; i<customers.size(); i++){
        actualCustomers += customers[i].second;
        maxCustomers = max(maxCustomers, actualCustomers);
    }

    cout << maxCustomers;


}