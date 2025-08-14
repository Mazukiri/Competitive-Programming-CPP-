#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
#define II pair<int,int>
#define fi first
#define se second
int n, m, q;
int A[N];
vector<II> adj[N];
int Color[N];
bool flag = true;
bool visited[N];
vector<int> trace;
bool isPossible[N];
int connected_component[N];
int id, Size = 1;

void DFS(int u, int state_color){
    connected_component[u] = id;
    trace.push_back(u);
    if (Color[u] == 0) Color[u] = state_color;
    
    else {
        if (Color[u] != state_color) {
            flag = false;
        }
        if (!isPossible[u]) {
            flag = false;
            id = connected_component[u];
        }
        return;
    } 



    for (II v : adj[u]) {
        
        DFS(v.fi, state_color * v.se);
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m >> q;

   

    for (int i = 1; i<=n; i++) cin >> A[i];

    for (int i = 1; i<=m; i++) {
        int u, v; cin >> u >> v;
        //Cung la banh rang ngoai
        if (A[u] == A[v]) {
            adj[u].push_back({v, -1});
            adj[v].push_back({u, -1});
        }

        else {
        // Cung la banh rang trong
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }
    }

    //Init isPossible = true
    for (int i = 1; i<=n; i++) isPossible[i] = true;


    

    for (int i = 1; i<=n; i++) {
        flag = true;

        if (Color[i] == 0) {
            id = Size; 
            ++Size;
            DFS(i, 1);
        
            if (flag) trace.clear();
        
            else {
                for (int i = 0; i<trace.size(); i++) {
                    isPossible[trace[i]] = false;
                    connected_component[trace[i]] = id;
                }
        
                trace.clear();
            }
        } 
    }
    
    // for (int i = 1; i<=n; i++) cout << Color[i] << " ";

    // cout << '\n';

    // for (int i = 1; i<=n; i++) cout << isPossible[i] << " ";

    for (int i = 1; i <= q; i++) {
        int u, v, g1, g2; cin >> u >> v >> g1 >> g2;
        
        if (isPossible[u] && isPossible[v] ) {

            if (connected_component[u] != connected_component[v]) {
                cout << "YES" << '\n';
                continue;
            }
            //XOR: Giống nhau là ra 0, Khác nhau là ra 1
            if ((Color[u] == Color[v]) ^ (g1 == g2)) cout << "NO" << '\n';
            else cout << "YES" << '\n';
            // if (Color[u] == Color[v] && g1 != g2) cout << "NO" << '\n';
            // if (Color[u] != Color[v] && g1 != g2) cout << "YES" << '\n';                
            // if (Color[u] != Color[v] && g1 == g2) cout << "NO" << '\n';
        }

        else {
            cout << "NO" << '\n';
        }
    }

    // for (int i = 1; i<=n; i++) cout << connected_component[i] << " ";
}
