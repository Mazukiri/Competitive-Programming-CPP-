#include <bits/stdc++.h>
using namespace std;
#define int long long



void quickSort(vector<int>& A, int l, int r) {
    int i = l;
    int j = r;
    int pivot = A[(l+r)/2];

    while (i <= j){
        while (A[i]<pivot) i++;
        while (A[j]>pivot) j--;

        if (i<=j) {
            int tam = A[i]; 
            A[i] = A[j];
            A[j] = tam;
            i++; 
            j--;
        }
    }

    if (i<r) quickSort(A, i, r);
    if (l<j) quickSort(A, l, j);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    vector<int> s = {10, 100, 1000, 10000, 100000, 10000000, 10000000};

    ofstream outFile("benchmark_results.csv");
    outFile << "n,time(ms)\n";

    for (int n : s) {

        double totalTimes = 0;

        /*
        Bỏ dòng này nếu một lần chạy lâu và in ra duration.count() để đo thời gian chạy. 
        Thay vào đó, hãy cố gắng tạo bộ dữ liệu "ngẫu nhiên" hết sức có thể và tiến hành đo 3-5 lần!
        Hoặc chỉ đơn giản là giảm cỡ mẫu!
        */

        for (int times = 1; times <= 30; times++) {
            vector<int> A(n + 1);
            for (int j = 1; j <= n; j++) A[j] = rand();

            auto start = chrono::high_resolution_clock::now();
            quickSort(A, 1, n);
            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, std::milli> duration = end - start;
            totalTimes += duration.count();
        }
        
        outFile << n << "," << totalTimes/30 << "\n";

    }

    outFile.close();
    cout << "Benchmark results saved to benchmark_results.csv\n";

    return 0;
}
