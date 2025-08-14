#include <bits/stdc++.h>
using namespace std;
#define int long long

int fiboRecursion(int n) {
    if (n == 1 || n == 2) return 1;
    return fiboRecursion(n-2) + fiboRecursion(n-1);
}

int fiboWithoutRecursion(int n)  {
    if (n <= 2) return 1;
    int a = 1, b = 1, c; 

    for (int i = 3; i<=n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

//In ra dạng biểu diễn nhị phân: Đệ quy và không đệ quy
void BinaryRecursive(int n) {
    if (n > 1) {
        BinaryRecursive(n / 2);
    }
    cout << (n % 2);
}

void BinaryIterative(int n) {
    stack<int> s;
    while (n > 0) {
        s.push(n % 2);
        n /= 2;
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

// Hàm sinh số ngẫu nhiên trong khoảng [low, high]
int randomInt(int low, int high) {
    return low + rand() % (high - low + 1);
}

// Sinh dữ liệu ngẫu nhiên cho bài toán
void generateKnapsackData(int n, int &M, vector<int> &weights, vector<int> &values) {
    weights.resize(n);
    values.resize(n);

    for (int i = 0; i < n; i++) {
        weights[i] = randomInt(1, 100);  // Trọng lượng từ 1 đến 100
        values[i] = randomInt(1, 200);   // Giá trị từ 1 đến 200
    }

    // Chọn một số phần tử ngẫu nhiên để đảm bảo bài toán có nghiệm
    M = 0;
    int items = randomInt(1, n); // Chọn số lượng phần tử ngẫu nhiên để lấy tổng trọng lượng
    vector<int> selected_indices;
    while (selected_indices.size() < items) {
        int idx = randomInt(0, n - 1);
        if (find(selected_indices.begin(), selected_indices.end(), idx) == selected_indices.end()) {
            selected_indices.push_back(idx);
            M += weights[idx];
        }
    }
}

// Hàm đệ quy giải bài toán xếp balo
int knapsack(int n, int M, vector<int>& weights, vector<int>& values) {
    if (n == 0 || M == 0)
        return 0;
    if (weights[n-1] > M)
        return knapsack(n-1, M, weights, values);
    
    return max(knapsack(n-1, M, weights, values),
               values[n-1] + knapsack(n-1, M - weights[n-1], weights, values));
}



signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(0));

    vector<int> test_sizes = {5, 10, 15, 20, 25, 30};
    ofstream outFile("benchmark_results.csv");
    outFile << "n,time(ms)\n";

    for (int n : test_sizes) {
        int M;
        vector<int> weights, values;
        generateKnapsackData(n, M, weights, values);

        double totalTime = 0;
        for (int times = 1; times <= 30; times++) { 
            auto start = chrono::high_resolution_clock::now();
            
            knapsack(n, M, weights, values);

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, std::milli> duration = end - start;
            totalTime += duration.count();
        }
        
        outFile << n << "," << totalTime/30 << "\n";
    }

    outFile.close();
    cout << "Benchmark results saved to benchmark_results.csv\n";
    return 0;
}
