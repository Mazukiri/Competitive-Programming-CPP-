#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n, m;
vector<int> customers;
multiset<int> tickets;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 0; i<n; i++){
        int x; cin >> x;
        tickets.insert(x);
    }
    
    for (int i = 0; i<m; i++) {
        int x; cin >> x;
        customers.push_back(x);
    }

    

    for (int it: customers){

        int value = it;
        auto ind = tickets.upper_bound(value);

        if (ind == tickets.begin()) cout << -1 << '\n';
        else {
            
            ind--;
            cout << *ind << '\n';
            tickets.erase(ind);
            
        }
    }

    
}