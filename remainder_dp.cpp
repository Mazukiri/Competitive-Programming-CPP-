#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll x, n, m;

ll exponential(ll a, ll b){

    if (b == 0) return 0;
    if (b == 1) return a;
    
    ll t = exponential(a, b/2);

    if (b%2 == 0) return ((t%m)*2)%m;
    return ((((t%m)*2)%m) + a)%m;
}

// Hàm nhân hai ma trận 2x2 với nhau theo mô-đun m
vector<vector<ll>> multiplyMatrix(const vector<vector<ll>>& a, const vector<vector<ll>>& b, ll m) {
    vector<vector<ll>> result(2, vector<ll>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] = (result[i][j] + (exponential(a[i][k], b[k][j]) % m)) % m;
            }
        }
    }
    return result;
}

// Hàm tính lũy thừa của ma trận theo mô-đun m
vector<vector<ll>> matrixPower(vector<vector<ll>> base, ll exp, ll m) {
    vector<vector<ll>> result = {{1, 0}, {0, 1}}; // Ma trận đơn vị 2x2
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiplyMatrix(result, base, m);
        }
        base = multiplyMatrix(base, base, m);
        exp /= 2;
    }
    return result;
}

// Hàm chính tính phần dư
ll calculate_remainder(ll x, ll n, ll m) {
    ll len_x = to_string(x).size(); // Độ dài của x
    ll pow10_len_x_mod_m = 1;
    for (int i = 0; i < len_x; i++) {
        pow10_len_x_mod_m = (pow10_len_x_mod_m * 10) % m;
    }

    // Ma trận chuyển đổi A
    vector<vector<ll>> A = {{pow10_len_x_mod_m, x % m}, {0, 1}};

    // Tính A^n
    vector<vector<ll>> An = matrixPower(A, n, m);

    // Kết quả là phần tử ở vị trí (0,1) trong ma trận An
    return An[0][1];
}

int main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        if (fopen("_ab.inp", "r")) {
            freopen("_ab.inp", "r", stdin);
            freopen("_ab.out", "w", stdout);
        }
    
    cin >> x >> n >> m;
    cout << calculate_remainder(x, n, m) << endl;
    return 0;
}
