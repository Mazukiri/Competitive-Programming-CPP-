/*
3. Bài toán Balo sử dụng kỹ thuật đảo nhãn + Quy Hoạch Động Bitmask

Khi sử dụng các kỹ thuật Quy Hoạch Động để giải bài toán cái túi, mọi người đã quen sử dụng
bảng 2 chiều (tabulation) hoặc bảng 1 chiều để lưu trữ kết quả của các bài toán con.

Tuy nhiên, với cách làm này, khi Balo có cân nặng lớn hơn dung lượng tối đa của mảng hoặc
CTDL (thường là 10^6 - 10^8), ta cần phải sử dụng các kỹ thuật khác để có thể lưu 
trữ kết quả các bài toán con. Ở trong bài tập này, tôi sẽ sử dụng kỹ thuật "Đảo nhãn", hay
sẽ Quy Hoạch Động trên cái túi (N <= 18) nhưng vẫn thực hiện được yêu cầu của đề bài. 

Bài tập này cũng sử dụng Quy Hoạch Động bitmask để sinh ra toàn bộ các hoán vị túi (2^N), 
với N <= 18 nằm trong giới hạn cho phép. Chi tiết về Quy Hoạch Động bitmask có thể được
đọc thêm tại đây: https://wiki.vnoi.info/vi/algo/dp/dp-bitmask

Đề bài và Link nộp: https://lqdoj.edu.vn/problem/knapsack3
Đọc thêm: https://wiki.vnoi.info/algo/dp/Mot-so-ky-thuat-toi-uu-hoa-thuat-toan-Quy-Hoach-Dong

*/
#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long W[N], V[N];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    long long n, m ; 
    cin >> n >> m;

    for (int i = 0; i<n; i++){
        cin >> W[i] >> V[i];
    }

    int totalMask = (1 << n); //2^n

    long long ans = 0; //ans: gia tri lon nhat satisfy m
    long long truyvet;

    for (int mask = 0; mask < totalMask; mask++){

        long long weight = 0, value = 0;

        for (int i = 0; i<n; i++){

            if (mask >> i & 1) {

                weight += W[i];
                value += V[i];
            }
        }

        if (weight <= m) {

            if (value > ans){
                ans = max(ans, value);
                truyvet = mask;
            }
        }
    }

    cout << __builtin_popcount(truyvet) << '\n';

    for (int i = 0; i<n; i++){
        if ((truyvet >> i) & 1) cout << i+1 << " ";
    }
}
