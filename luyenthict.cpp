#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string correctAns, currentAns;
char C[10][10];
bool vis[10][10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int countAns;

bool isInside(int x, int y){

    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

void DFS(int u, int v, int index){

    if (index == correctAns.size()){
        countAns++;
        return;
    }
    
    vis[u][v] = true; 

    currentAns += C[u][v];

    if (currentAns == correctAns) {
        countAns++;
    }

    else {

        for (int i = 0; i<4; i++){
            int x = u + dx[i];
            int y = v + dy[i];

            if (isInside(x, y) && !vis[x][y] && C[x][y] == correctAns[index]) DFS(x, y, index+1); 
        }
    }

    vis[u][v] = false;
    currentAns.pop_back();
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> correctAns;
    

    

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++) cin >> C[i][j];
    }

    
    countAns = 0;

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            if (countAns == 0 && C[i][j] == correctAns[0]) {
                memset(vis, false, sizeof vis);
                currentAns = "";
                DFS(i, j, 1);
            }
        }
    }
    

    if (countAns == 0) cout << "NO"; 
    else cout << "YES";
}