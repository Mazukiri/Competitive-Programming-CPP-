#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;

int n, m;
char s[][];

pii nxtR[][], nxtL[][], nxtU[][], nxtD[][];
void buildNxt(){
    for (int row = 1 -> n) {
        nxtR[row][m] = NaN;
        for (col = m-1 -> 0)
            nxtR[row][col] = (s[row][col+1] is datlien) 
                ? {row, col+1} 
                : nxtR[row][col + 1];
    }
}

int group[][], cntGr;
void bfs(pii pos, int groupIndex) {
    // bfs tat ca o dat lien cung tplt
    // gan tat ca o group[x][y] = groupIndex
}

vector<int> graph[];
void buildGraph() {
    for (row = 1 -> n)
    for (col = 1 -> n) {
        // check LRUD
        if (nxtR[row][col] != NaN){
            pii nxt = nxtR[row][col]
            if group[row][col] != group[nxt.x][nxt.y]
                int u = group..., v....
                graph[u].pb(v), graph(v, u)
        }
            // tạo cạnh giữa group[] và ggroup[]
            graph[]

    }


    group[@] ----bfs----> group[#]
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    return 0;
}