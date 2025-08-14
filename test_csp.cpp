#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
vector<int> primes;
bool prime[N];
int B[N];
int n, k;

void snt() {
    
    for (int i = 1; i<=N; i++) prime[i] = true;

    for (int i = 2; i < N; i++) {
       if (prime[i]) for (int j = i * i; j < N; j += i) prime[j] = false;
    }

    for (int i = 2; i<N; i++) if (prime[i]) primes.push_back(i);
}

int subfull(int n) {
    for (int i = 8; i <= n; i += 2) {
        for (int j = 1; j * 2 < i; j++) {
            if (prime[i / 2 + j] && prime[i / 2 - j] && (i / 2 - j != 2 && i / 2 + j != 2)) {
                B[i] = j;
                break;
            }
        }
    }

    unsigned long long ans = 1;

    for (int i = 1; i < primes.size(); i++) {
        int value = n - 2 - primes[i];
        if (value < 0) break;
        if (B[value] != 0) {
            int a = 2;
            int b = primes[i];
            int c = value / 2 + B[value];
            int d = value / 2 - B[value];

            if (b == c || b == d) continue;

            unsigned long long product = (unsigned long long) 2ULL * c * d * b;
            ans = max(ans, product);
        }
    }

    if (ans != 1) return cout << ans, 0;
    return cout << -1, 0;
}



signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // if (fopen("_ab.inp", "r")) {
    //     freopen("_ab.inp", "r", stdin);
    //     freopen("_ab.out", "w", stdout);
    // }

    /*
    - 
    - Lấy một số: value = n - 2 - primes[i] -> Value chẵn
    - Cần tìm hai số nguyên tố lẻ sao cho tổng = value
    - ~78.408 primes (O(n^2))
    */

    cin >> n >> k;

    snt();

    //for (int i = 2; i<= 50; i++) cout << i << " " << prime[i] << '\n';

    if (k == 1) {
        if (prime[n]) return cout << n, 0;
        return cout << -1, 0;
    }

    int ans = 1;

    if (k == 2) {
        for (int i = 2; i * 2 < n; i++) {
            if (prime[i] && prime[n - i]) ans = max(ans, i * (n - i));
        }
        
        if (ans != 0) return cout << ans, 0;

        return cout << -1, 0;
    }

    if (k == 3) {
        n -= 2;

        for (int i = 2; i * 2 < n; i++) {
            if (prime[i] && prime[n - i]) ans = max(ans, 2LL * i * (n - i));
        }
        
        if (ans != 0) return cout << ans, 0;

        return cout << -1, 0;

    }

    //k = 4, Tính một B[i] là tính lớn nhất có tổng là i được tạo bởi 2 snt

    //k = 4, Tính một B[i] là tính lớn nhất có tổng là i được tạo bởi 2 snt

    //subfull(n);

    for (int i = 1; i<=20; i++) {
        subfull(i);
    }

    
}
