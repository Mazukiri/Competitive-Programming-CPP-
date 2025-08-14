#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    while (t--) {

    int n; 
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    sort(A.begin(), A.end()); // Sắp xếp mảng để dễ sử dụng ba con trỏ

    int ans = 0;

    // Duyệt con trỏ thứ ba (`index3`) làm giá trị `b` trong điều kiện a + c = b
    for (int index3 = 2; index3 < n; index3++) {
        int index1 = 0; // Con trỏ đầu tiên (giả sử `a`)
        int index2 = index3 - 1; // Con trỏ thứ hai (giả sử `c`)

        while (index1 < index2) {
            int sum = A[index1] + A[index2];
            if (sum == A[index3]) {
                ans++;
                index1++;
                index2--;
            } else if (sum < A[index3]) {
                index1++; // Tăng `index1` nếu tổng nhỏ hơn `A[index3]`
            } else {
                index2--; // Giảm `index2` nếu tổng lớn hơn `A[index3]`
            }
        }
    }

    cout << ans << '\n';
    }
}
