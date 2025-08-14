#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 1505;
char SwanLake[N][N];
vector<II> swans;
queue<II> bangtan;
int n, m;

void BFS(int )

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){

            cin >> SwanLake[i][j];
            if (SwanLake[i][j] == 'L'){
                swans.push_back(II(i, j));
                unfrozen_days[i][j] = 0;
                

            }

            if (SwanLake[i][j] == '.'){
                unfrozen_days[i][j] = 0;
            }
        }
    }

    


}