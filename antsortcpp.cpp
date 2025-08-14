#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const long long N = 1e6 + 5;

int n, A[N], B[N];

int f(int t){
    //Kiểm tra xem, sau t giây có tạo được cấu hình kiến như mong đợi không

    for (int i = 1; i<=n; i++) A[i] = B[i];

    A[1] = A[1] - t;

    for (int i = 2; i<=n; i++){ //Sắp xếp lại con kiến thứ i

        //A[i] < A[i-1]: Bắt buộc phải dịch A[i] sang phải cho tới khi cách A[i-1] +1 đơn vị
        // A[i] > A[i-1]: Dịch sang trái nhiều bước nhất có thể sao cho A[i] - steps < A[i-1] (steps <= t)

        if (A[i] < A[i-1]){

            int dist = A[i-1] + 1 - A[i];
            if (dist <= t) A[i] = A[i-1] + 1;
            //Không thể di chuyển tới được
            else {
                return false;
            }

        }

        else {
            if (A[i] == A[i-1]){
                A[i]++;
                if (t == 0) return false;
            }

            

            else {
                A[i] = max(A[i-1] + 1, A[i] - t);
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
 
    cin >> n;

    for (int i = 1; i<=n; i++) cin >> B[i];

    int l = 0, r = 1e18, ans = 0;

    while (l<=r){

        int mid = (l+r)/2;

        if (f(mid)) {
            
            ans = mid;
            r = mid - 1;
        }

        else l = mid + 1;
    }

    f(ans);

    //So giay toi thieu ma lu kien can ,Cau hinh kien cuoi cung
    cout << ans << '\n';
    for (int i = 1; i<=n; i++) cout << A[i] << " ";
}