#include <iostream>
#include <vector>

std::vector<int> constructArray(int n, int x, int y) {
    std::vector<int> a(n, 1);  // Initialize array with 1s
    
    // Set -1 for the suffix part
    for (int i = y; i < n; i++) {
        a[i] = -1;
    }
    
    // Adjust the prefix part if necessary
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += a[i];
        if (sum > 0 && i + 1 < x) {
            a[i + 1] = -1;
            sum--;
        }
    }
    
    return a;
}

int main() {
    
    freopen("_ab.inp", "r", stdin);
    freopen("_ab.out", "w", stdout);
    
    

    int t;
    std::cin >> t;
    
    while (t--) {
        int n, x, y;
        std::cin >> n >> x >> y;
        
        std::vector<int> result = constructArray(n, x, y);
        
        for (int i = 0; i < n; i++) {
            std::cout << result[i] << (i == n - 1 ? '\n' : ' ');
        }
    }
    
    return 0;
}