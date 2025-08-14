#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 1e6 + 5;
int n, q;
int type, L, R, K, changeIndex, newValue;
int A[N], prefix[N];

// struct q2{
//     int l, r, k;
// }

// vector<II> Queries1;
// vector<q2> Queries2;

bool check(int x){

    if (x % K == 0) return true;

    while (x > 0){
        int currentDigit = x%10;
        
        if (currentDigit == K) return true;

        x /= 10;
    }

    return false;

}

void sub1(){
    
    while (q--){
    
    cin >> type;

    if (type == 1){
        cin >> changeIndex >> newValue;
        A[changeIndex] = newValue;
    }

    else {
        cin >> L >> R >> K;

        int ans = 0;

        for (int i = L; i<=R; i++){
            if (check(i)) ans += (2 * A[i]); else ans += A[i];
        }

        cout << ans << '\n';
    }

    }
}

// void sub4(){
//     sub1();
//     //À há, bất ngờ chưa. Anh chả nghĩ ra sub4 làm thế nào, nhưng mà chương trình thì 
//     //vẫn phải chạy nhỉ :">"
// }

// //void sub2(){

//     int currentSum = 0;

//     for (int i = 0; i<Queries2.size(); i++){

//         //Tổng ban đầu, chưa cộng thêm các phần tử được x2 lên
//         currentSum = [Queries2[i].r] - prefix[Queries2[i].l - 1];

//         /*
//         Ta nhận ra các tổng được x2 lên có thể được tính nhanh bằng công thức sau
//         Xác định số a1 = L + (L % K);
//         Xác định số an (số cuối cần update): an = R - (R % K);
//         Ta có công sai d = K
//         Công thức sẽ là: [(a1 + an) * ((an - a1)/d + 1)))]/2;

//         Bên cạnh đó, các số được x2 là các số chứa chữ số k trong nó

//         */

//     }
// }

// void sub3(){
//     int currentAns = 0;


// }

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i<=n; i++) cin >> A[i];

    //init prefixA
    for (int i = 1; i<=n; i++) prefix[i] = prefix[i-1] + A[i];

    sub1();

    // while (q--){
    //     cin >> type;

    //     if (type == 1){
        
    //     cin >> changeIndex, newValue;
    //     Queries1.push_back({changeIndex, newValue});
    // }

    // else {
    //     cin >> L >> R >> K;

    //     Queries2.push_back({L, R, K});
    // }
    
    // }

    // if (Queries1.size() == 0) sub2();

    // int numsKequals1 = 0;

    // for (auto x: Queries2) if (x.k == 1) numsKequals1++;

    // if (numsKequals1 == Queries2.size()) sub3();

    // else sub4();

    
}