/*
2. DP trên Segment Tree: 
Đề bài và link nộp: https://oj.vnoi.info/problem/segtree_itmed
Tài liệu tham khảo thêm: https://wiki.vnoi.info/algo/data-structures/segment-tree-extend 
*/
#include <iostream>
#include <vector>
#include <algorithm>
const int INT64_MIN = -1e9 + 7;
using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    int n;

    void build(const vector<long long>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            tree[v] = max(tree[v*2], tree[v*2+1]);
        }
    }

    long long query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return INT64_MIN;
        if (l == tl && r == tr)
            return tree[v];

        int tm = (tl + tr) / 2;
        return max(query(v*2, tl, tm, l, min(r, tm)),
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    void update(int v, int tl, int tr, int pos, long long new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            tree[v] = max(tree[v*2], tree[v*2+1]);
        }
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, INT64_MIN);
    }

    void build(const vector<long long>& a) {
        build(a, 1, 0, n-1);
    }

    long long query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void update(int pos, long long new_val) {
        update(1, 0, n-1, pos, new_val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (k >= n) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                sum += a[i];
            }
        }
        cout << sum << endl;
        return 0;
    }
    
    bool all_non_positive = true;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            all_non_positive = false;
            break;
        }
    }
    
    if (all_non_positive) {
        cout << 0 << endl;
        return 0;
    }
    
    // Quy Hoạch Động với Segment Tree
    vector<long long> dp(n, 0);
    dp[0] = max(0LL, a[0]);  
    SegmentTree st(n);
    st.update(0, dp[0]);
    
    for (int i = 1; i < n; i++) {
        // Dùng Segment Tree để tìm giá trị dp lớn nhất trong khoảng [max(0, i-k), i-1]
        int left = max(0, i - k);
        long long max_prev = st.query(left, i - 1);
        
        // Tính dp[i] 
        dp[i] = max(0LL, a[i] + max(0LL, max_prev));
        st.update(i, dp[i]);
    }
    
    // Tìm ra kết quả
    long long result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, dp[i]);
    }
    
    cout << result << endl;
    
    return 0;
}
