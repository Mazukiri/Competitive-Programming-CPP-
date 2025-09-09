#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int t, n;
string s[N];

struct TrieNode {
    TrieNode *child[10];
    int cnt;
    TrieNode() {
        for (int i = 0; i < 10; ++i)
            child[i] = NULL;
        cnt = 0;
    }
};

void TrieInsert(TrieNode *root, const string &s) {
    TrieNode *p = root;
    for (int i = 0; i < (int)s.size(); ++i) {
        int nxt = s[i] - '0';
        if (p->child[nxt] == NULL)
            p->child[nxt] = new TrieNode();
        p = p->child[nxt];
    }
    ++p->cnt;
}

bool TrieFind(TrieNode *root, const string &s) {
    TrieNode *p = root;
    for (int i = 0; i < (int)s.size(); ++i) {
        int nxt = s[i] - '0';
        if (p->child[nxt] == NULL)
            return false;
        p = p->child[nxt];

        // Nếu có chuỗi đã kết thúc trước khi hết s → chuỗi đó là prefix
        if (p->cnt > 0 && i != (int)s.size() - 1)
            return true;
    }

    // Nếu node cuối có con → s là prefix của số khác
    for (int i = 0; i < 10; ++i)
        if (p->child[i] != NULL) return true;

    return p->cnt > 0; // trùng hoàn toàn
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
    
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> s[i];

        bool isIntegrity = true;
        TrieNode *root = new TrieNode();

        for (int i = 0; i < n; i++) {
            if (TrieFind(root, s[i])) {
                isIntegrity = false;
                break;
            }
            TrieInsert(root, s[i]);
        }

        cout << (isIntegrity ? "YES" : "NO") << '\n';
    }
}
