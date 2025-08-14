#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
int K;

int lcm(int a, int b) {
    return a * b / __gcd(a, b); 
}

int inclusion_exclusion(int value) {
    int A = value/3;
    int B = value/5;
    int C = value/7;

    int A_B = value/lcm(3, 5);
    int A_C = value/lcm(3, 7);
    int B_C = value/lcm(5, 7);

    int A_B_C = value/lcm(lcm(3, 5), 7);

    return A + B + C - A_B - A_C - B_C + A_B_C;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
    
    cin >> K;

    int left = 1, right = 1e18;

    while (left <= right) {
        int mid = (left + right) / 2;
        int pos = inclusion_exclusion(mid);
        
        if (pos == K && (mid % 3 == 0 || mid % 5 == 0 || mid % 7 == 0)) {
            return cout << mid << '\n', 0;
            
        }

        if (pos == K  && (mid % 3 != 0 || mid % 5 != 0 || mid % 7 != 0)) {
            
            int should_a = mid % 3;
            int should_b = mid % 5;
            int should_c = mid % 7;

            int ans = mid - min(min(should_a, should_b), should_c);

            return cout << ans << '\n', 0;
            break;
        }

        if (pos < K) {
            left = mid + 1;
        }

        else {
            right = mid - 1;
        }
    }
    
}