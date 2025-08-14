#include <bits/stdc++.h>

using namespace std;

int num_point, num_edge, test;
vector <int> relation[1006];

int main() {

    freopen("_ab.inp", "r", stdin);
    freopen("_ab.out", "w", stdout);

    cin >> num_point >> num_edge;

    for (int i = 1; i <= num_edge; i++) {

        int p1, p2;
        cin >> p1 >> p2;

        relation[p1].push_back(p2);
        relation[p2].push_back(p1);
    }
        
    cin >> test;

    while (test--) {

        int p1, p2, ans = 0;
        bool p1_list[1006];
        cin >> p1 >> p2;

        for (int i = 0; i <= 1005; i++) p1_list[i] = false;

        // for (int i = 0; i < relation[p1].size(); i++) p1_list[relation[p1][i]] = true;

        for (int x : relation[p1]) p1_list[x] = true;        

        for (int x : relation[p2]){
            if (p1_list[x]) ans++;
        }

        // cout << relation[p1][2] << '\n';
        cout << ans << '\n';
    }
}