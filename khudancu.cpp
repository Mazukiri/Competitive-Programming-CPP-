#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int M, N, D, K;
int countMarkets[1000005];
int diff[1000005];
char A[1000005];

void update(int i){

    int min_update = max(i - D, 1LL);
    int max_update = min(i + D, N);

    diff[min_update]++;
    diff[max_update + 1]--;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> M >> N >> D >> K;

    //Đọc các vị trí mà Market xuất hiện. Sau đó dùng hàm update(i) để 
    // cập nhật mảng countMarkets từ i - D --> i + D
    for (int i = 1; i<=N; i++){
        {
            cin >> A[i];
            if (A[i] == 'M') update(i);
        }
    }

    for (int i = 1; i<=N; i++) diff[i] = diff[i-1] + diff[i];

    int ans = 0;

    for (int i = 1; i<=N; i++) {

        if (A[i] == 'P' && diff[i] >= K) ans++;
    }

    cout << ans;

    
    
}