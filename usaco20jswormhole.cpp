#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, id = 1;
int ring[N], par[N], sz[N];
vector<int> cycle[N];

struct edge {

    int u, v, c;

    edge(int u, int v, int c) : u(u), v(v), c(c){}

    bool operator<(edge &other) {
        return c > other.c;
    }
};

vector<edge> edges;

void CycleFinding(){
    
    for (int cow = 1; cow<=n; cow++) {

        if (cow == ring[cow]) continue; 
        cycle[id].push_back(cow);

        while (cow != ring[cow]) {//Chua o dung chuong
        
            cycle[id].push_back(ring[cow]);
            
            //Doi cho con bo hien tai toi vi tri chinh xac
            swap(ring[cow], ring[ring[cow]]); 
        }
        id++;
    }
}

//Uư tiên trả lời các truy vấn K > trước. 
//Ví dụ: Với truy vấn có K>=4 thì add hết các cạnh lớn hơn trước
//Join các cạnh rồi Lấy luôn kết quả
// Giữ nguyên con trở ở cái bước trước đó, for trong danh sách cạnh trước đó. Giữ nguyên con trỏ. 

int find(int u) {
    return (u == par[u]? u: find(par[u]));
}

void join(int u, int v) {
    int a = find(u);
    int b = find(v);

    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

void build_dsu(int index) {
    for (int i = 1; i<=n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i<=index; i++) {
        join(edges[i].u, edges[i].v);
    }
}

bool isVerified(){
    for (int i = 1; i<id; i++) {
        
        int flag = find(cycle[i][0]);

        for (int v: cycle[i]) {
            if (find(v) != flag) {
                return false;
            }
        }
    }

    return true;
}


 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i<=n; i++) {
        cin >> ring[i];
    }

    

    for (int i = 1; i<=m; i++) {
        int u, v, c; cin >> u >> v >> c;
        edges.push_back(edge(u, v, c));
    }

    sort(edges.begin(), edges.end());


    bool flag = false;

    for (int i = 1; i<=n; i++) {
        if (ring[i] != i) flag = true;
    }

    if (!flag) return cout << -1, 0;

    CycleFinding();

    int ans = -1;


    int l = 0, r = m - 1;

    while (l <= r) {
        int mid = (l + r)/2;
        build_dsu(mid);
        
        if (isVerified()) {
            ans = mid;
            r = mid - 1;
        }

        else l = mid + 1;
    }

    cout << edges[ans].c;   
}


int dem[128]

for (char x: s) {
    dem[x]++;
}

for () {
    if (dem[i] > 0) {
        cout << i << " " << demn[i];
    }
}

dem['a'] 