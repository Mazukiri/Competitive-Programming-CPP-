#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, k, x;
int A[N];
int prefix[10][N];

void sub1(){
    int ans = 0;

    if (k >= 2) {
        cout << n;
        return;
    }

    //Cố định đèn A[i]
    for (int i = 1; i<=n; i++) {
        int count_changes = 0; //Đếm số lần thay đổi

        for (int j = i + 1; j<=n; j++) {

            if (A[j] != A[i]) count_changes++;

            if (count_changes > x) break;

            ans = max(ans, j - i + 1);
        }
    }

    cout << ans;
}

void sub3() {

    int ans = 0;

    for (int color = 1; color <= 9; color++) {
        //Tạo 9 mảng prefix sum bằng vòng lặp này
        vector<int> prefix(n + 1, 0);

        for (int i = 1; i<=n; i++) {
            prefix[i] = prefix[i-1] + (A[i] != color);
        }

        //Đã tạo mảng kiểm tra số lần biến đổi cần thiết
        // giữa hai đoạn l --> r bất kỳ. 
        // Số lần biến đổi cần thiết có thể được tính bằng
        // công thức prefix[mid] - prefix[l - 1] 
        
        for (int i = 1; i<=n; i++) {
            
            int l = i, r = n, endIntervalIndex = i - 1;

            while (l<=r) {
                int mid = (l + r)/2;

                //so lan bien doi
                if (prefix[mid] - prefix[l-1] <= x) {
                    endIntervalIndex = mid;
                    l = mid + 1;
                }

                else {
                    r = mid - 1;
                }
            }

            ans = max(ans, endIntervalIndex - i + 1);
        }
    }

    cout << ans;
}

void sub4() {

    int ans = 0;

    for (int i = 1; i<=n; i++) {
        for (int number = 1; number <= 9; number++) {
            prefix[number][i] = prefix[number][i - 1] + (A[i] == number);
        }

        //prefix[number][i]: Số lượng number trong đoạn
        //từ 1 --> i
    }

    for (int i = 1; i <= n; i++) {
        
        int l = i, r = n, endIndexInterval = i;

        while (l <= r) {
            int mid = (l + r)/2;

            int howManyNumbers = 0;

            for (int number = 1; number <= 9; number++) {
                //Dem xem co bao nhieu con number trong doan tu i --> mid
                howManyNumbers += (prefix[number][mid] - prefix[number][i - 1] > 0);
            }

            if (howManyNumbers <= x) {
                ans = max(ans, mid - i + 1);
                l = mid + 1;
            }

            else {
                r = mid - 1;
            }
        }
    }

    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("DENLONG.inp", "r")) {
        freopen("DENLONG.inp", "r", stdin);
        freopen("DENLONG.out", "w", stdout);
    }

    cin >> n >> k >> x;

    for (int i = 1; i<=n; i++) cin >> A[i];

    if (n<=1000) sub1();
    if (n>1000 && k == 1) sub3();
    else sub4();
}