#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

void findSum(int n){

    int temp = n; //temp = 28
    vector<int> factors;
    vector<int> powerOfFactors;

     
    for (int i = 2; i<= ceil(sqrt(n)); i++){
        //Khoi tao 2 bien thừa số và số mũ
        int factor = -1;
        int powerOfFactor = 0;

        //Thuc hien kiem tra 
        while ((temp != 1) && (temp % i == 0)) {
            powerOfFactor++;
            factor = i;
            temp = temp/i;
        }

        //Đẩy vào mảng thừa số và mảng mũ
        if (factor != -1) factors.push_back(factor);
        //indexFactors++;
        //factors[indexFactors] = factor;
        if (powerOfFactor != 0) powerOfFactors.push_back(powerOfFactor);
    }

    //Nếu temp != 1, tức là ta chưa phân tích hết nó thành các thừa số nguyên tố
    //temp chính là số nguyên tố còn lại mà vòng for không chạm đến
    //Vì vậy, ta phải thêm vào mảng thừa số (factors) temp và số mũ của nó (1)
    if (temp != 1) {
            factors.push_back(temp);
            powerOfFactors.push_back(1);
    }

    //vector factors: luu thua so
    //vector mu: dung de luu mu cua thua so o vi tri tuong ung

    long long ans = 1;
    long long ans1 = 1;

    //Áp dụng công thức để nhân
    for (int i = 0; i<factors.size(); i++){
        
        long long temp = pow(factors[i], powerOfFactors[i] + 1) - 1;
        temp /= (factors[i] - 1);
        ans *= temp;

        ans1 *= (powerOfFactors[i]+1);
    }

    cout << ans1 << " " << ans << '\n';
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    //Ptich no ra thua so nguyen to
    //Cong thuc de tinh: (a*(n+1) - 1 / a - 1 ) * ...
    //n = 10^9, 100 test -- > 10^5 * 10^2 = 10^7 < 10^8

    int t; cin >> t;

    while (t--){
        int n; cin >> n;
        findSum(n);
    }
    
}