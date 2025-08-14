#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int n, m, k;

int f(int x){
    //Kiểm tra xem có bao nhiêu số được tạo thành từ công thức
    //i*i + j*j <= x
    //x = 29
    //5 + 5 + 4  = 14 

    int cnt = 0;

    for(int i = 1; i<=n; i++){
        
        //Tỉm ra con j lớn nhất thỏa mãn cấu hình i*i + j*j <= x
        int l = 1, r = m, j = 0;

        while (l<=r){
            
            int mid = (l+r)/2;
            
            if (i*i + mid*mid <= x){

                j = mid;
                l = mid + 1;   
            }

            else r = mid - 1;

        }

        cnt += j;

    }

    return cnt;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m >> k;

    if (n>m) swap(n, m);

    int l = 2, r = n*n + m*m, ans = 0;

    while (l<=r){

        int mid = (l+r)/2;

        if (f(mid) >= k){
            ans = mid;
            r = mid - 1;
        }

        else l = mid + 1;
    }

    cout << ans;
}