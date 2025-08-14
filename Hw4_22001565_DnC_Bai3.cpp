#include <bits/stdc++.h> 
using namespace std;

int t = 1;

void tileGrid(vector<vector<int>> &g, int n, int x, int y, int hx, int hy) {
    if (n == 1) return;
    
    int h = n / 2, ox = hx >= x + h, oy = hy >= y + h;
    int xx = x + h - 1 + ox, yy = y + h - 1 + oy;
    
    for (int dx = 0; dx <= 1; dx++)
        for (int dy = 0; dy <= 1; dy++)
            if (dx != ox || dy != oy) g[x + h - 1 + dx][y + h - 1 + dy] = t;
    
    t++;
    tileGrid(g, h, x, y, xx, yy);
    tileGrid(g, h, x, y + h, xx, y + h);
    tileGrid(g, h, x + h, y, x + h, yy);
    tileGrid(g, h, x + h, y + h, hx, hy);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
    int n, sz, hx, hy;

    cin >> n;
    sz = 1 << n; //Dịch bit của 2^n
    
    vector<vector<int>> g(sz, vector<int>(sz));
    
    cin >> hx >> hy;
    
    tileGrid(g, sz, 0, 0, hx, hy);
    
    for (auto &row : g) {  
        for (auto &cell : row) {  
            if (cell == 0)
                cout << setw(4) << "X";  // Ô thoát nước
            else
                cout << setw(4) << cell;  // Số thứ tự của viên gạch
        }
        cout << "\n";
    }
}
