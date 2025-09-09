#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
const int N = 5e4 + 5;
int q;
string s;
int prefix[N][26];

const int N = 2e5+5, S = 455;
struct query {
    int l, r, id;
    bool operator < (const query &x) {
        if (l / S == x.l / S) return r < x.r;
        return l / S < x.l / S;
    }
} qr[N];

void init() {
    for (int i = 1; i <= s.size(); i++) {
        prefix[i]['a' - 'a'] += prefix[i - 1]['a' - 'a'] + (s[i] == 'a');
        prefix[i]['b' - 'a'] += prefix[i - 1]['b' - 'a'] + (s[i] == 'b');
        prefix[i]['c' - 'a'] += prefix[i - 1]['c' - 'a'] + (s[i] == 'c');
        prefix[i]['d' - 'a'] += prefix[i - 1]['d' - 'a'] + (s[i] == 'd');
        prefix[i]['e' - 'a'] += prefix[i - 1]['e' - 'a'] + (s[i] == 'e');
        prefix[i]['f' - 'a'] += prefix[i - 1]['f' - 'a'] + (s[i] == 'f');
        prefix[i]['g' - 'a'] += prefix[i - 1]['g' - 'a'] + (s[i] == 'g');
        prefix[i]['h' - 'a'] += prefix[i - 1]['h' - 'a'] + (s[i] == 'h');
        prefix[i]['j' - 'a'] += prefix[i - 1]['j' - 'a'] + (s[i] == 'j');
        prefix[i]['k' - 'a'] += prefix[i - 1]['k' - 'a'] + (s[i] == 'k');
        prefix[i]['l' - 'a'] += prefix[i - 1]['l' - 'a'] + (s[i] == 'l');
        prefix[i]['m' - 'a'] += prefix[i - 1]['m' - 'a'] + (s[i] == 'm');
        prefix[i]['n' - 'a'] += prefix[i - 1]['n' - 'a'] + (s[i] == 'n');
        prefix[i]['o' - 'a'] += prefix[i - 1]['o' - 'a'] + (s[i] == 'o');
        prefix[i]['p' - 'a'] += prefix[i - 1]['p' - 'a'] + (s[i] == 'p');
        prefix[i]['r' - 'a'] += prefix[i - 1]['r' - 'a'] + (s[i] == 'r');
        prefix[i]['s' - 'a'] += prefix[i - 1]['s' - 'a'] + (s[i] == 's');
        prefix[i]['t' - 'a'] += prefix[i - 1]['t' - 'a'] + (s[i] == 't');
        prefix[i]['u' - 'a'] += prefix[i - 1]['u' - 'a'] + (s[i] == 'u');
        prefix[i]['v' - 'a'] += prefix[i - 1]['v' - 'a'] + (s[i] == 'v');
        prefix[i]['w' - 'a'] += prefix[i - 1]['w' - 'a'] + (s[i] == 'w');
        prefix[i]['y' - 'a'] += prefix[i - 1]['y' - 'a'] + (s[i] == 'y');
        prefix[i]['z' - 'a'] += prefix[i - 1]['z' - 'a'] + (s[i] == 'z');
        prefix[i]['x' - 'a'] += prefix[i - 1]['x' - 'a'] + (s[i] == 'x');
        prefix[i]['i' - 'a'] += prefix[i - 1]['i' - 'a'] + (s[i] == 'i');
        prefix[i]['q' - 'a'] += prefix[i - 1]['q' - 'a'] + (s[i] == 'q');
    }
}

int solve(int l, int r) {

    int ans = 0;

    for (int i = l; i <= r; i++) {
        char c = s[i];
        c--;
        
        for (c; c >= 'a'; c--) {
            ans += prefix[r][c - 'a'] - prefix[i][c - 'a'];
        }

    }

    return ans;
}

void update(int val, int sign) {
    
}



    

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("inversion.inp", "r")) {
        freopen("inversion.inp", "r", stdin);
        freopen("inversion.out", "w", stdout);
    }

    cin >> q >> s;

    s = " " + s;

    init();

    cin >> q;

    for (int i = 1; i <= q; ++i) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }

    sort(qr + 1, qr + q + 1);
    int u = 1, v = 0;
    for (int i = 1; i <= q; ++i) {
        while (v < qr[i].r) update(a[++v], 1);
        while (u > qr[i].l) update(a[--u], 1);
        while (v > qr[i].r) update(a[v--], -1);
        while (u < qr[i].l) update(a[u++], -1);     
    }

    for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
    
}