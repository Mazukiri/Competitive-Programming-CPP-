#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6;
int n, K;

bool isSatisfy(int startIndex, int X) {
    
    int stations = 0;

    for (int i = 1; i <= n; i++) {
        int mid = 
    }
}

bool check(int X) {

    //Thử cả 10^3 trạm, nếu ta đặt trạm đầu tiên từ một trạm bất kỳ
    //Chỉ cần tồn tại duy nhất một cách đặt hợp lệ (tức sô trạm đặt <= K),
    //phương án X này là khả thi

    for (int i = 1; i <= n; i++) {
        if (isSatisfy(i, X)) return true;
    }

    return false;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + 1 + n);

    cin >> K;



    int left = 1, right = N;

    int ans;

    while (left <= right) {
        int mid = (left + right) >> 1;
        
        if (check(mid) <= K) {
            ans = mid;
            right = mid - 1;
        } 

        else {
            left = mid + 1;
        }
    }

    cout << ans;
}