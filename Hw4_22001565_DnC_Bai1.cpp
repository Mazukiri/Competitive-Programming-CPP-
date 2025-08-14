#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Matrix vector<vector<int>> 
#define II pair<int,int>
#define fi first
#define se second
using namespace chrono;

// 1. Tìm min và max bằng chia để trị. Độ phức tạp: O(n).

II findMinMax(vector<int>& A, int l, int r) {
    if (l == r) return {A[l], A[l]};
    if (r == l + 1) return {min(A[l], A[r]), max(A[l], A[r])};
    
    int mid = (l + r) / 2;
    auto leftRes = findMinMax(A, l, mid);
    auto rightRes = findMinMax(A, mid + 1, r);
    return {min(leftRes.fi, rightRes.fi), max(leftRes.se, rightRes.se)};
}

// 2. Nhân ma trận Strassen. Độ phức tạp O(n^(log2_7))
Matrix multiplyMatrix(Matrix& A, Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int newSize = n / 2;
    Matrix A11(newSize, vector<int>(newSize)), A12(newSize, vector<int>(newSize)),
           A21(newSize, vector<int>(newSize)), A22(newSize, vector<int>(newSize)),
           B11(newSize, vector<int>(newSize)), B12(newSize, vector<int>(newSize)),
           B21(newSize, vector<int>(newSize)), B22(newSize, vector<int>(newSize));
    
    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j]; A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j]; A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j]; B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j]; B22[i][j] = B[i + newSize][j + newSize];
        }
    
    Matrix C11 = multiplyMatrix(A11, B11);
    Matrix C12 = multiplyMatrix(A12, B12);
    Matrix C21 = multiplyMatrix(A21, B21);
    Matrix C22 = multiplyMatrix(A22, B22);
    
    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j] + C12[i][j];
            C[i][j + newSize] = C11[i][j] + C12[i][j];
            C[i + newSize][j] = C21[i][j] + C22[i][j];
            C[i + newSize][j + newSize] = C21[i][j] + C22[i][j];
        }
    return C;
}

// 3. QuickSort. Độ phức tạp O(n logn). Tệ nhất: O(n^2)
void quickSort(vector<int>& A, int l, int r) {
    if (l >= r) return;
    int pivot = A[r], i = l;

    for (int j = l; j < r; j++)
        if (A[j] < pivot) swap(A[i++], A[j]);
    swap(A[i], A[r]);
    quickSort(A, l, i - 1);
    quickSort(A, i + 1, r);
}

// 4. MergeSort. Độ phức tạp O(n logn)
void merge(vector<int>& A, int l, int m, int r) {
    vector<int> L(A.begin() + l, A.begin() + m + 1);
    vector<int> R(A.begin() + m + 1, A.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size())
        A[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    while (i < L.size()) A[k++] = L[i++];
    while (j < R.size()) A[k++] = R[j++];
}
void mergeSort(vector<int>& A, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(A, l, m);
    mergeSort(A, m + 1, r);
    merge(A, l, m, r);
}

// 5. Kiểm tra phần tử chiếm đa số trong mảng đã sắp xếp
bool isMajority(vector<int>& A, int x) {
    int n = A.size();
    int first = -1;
    
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            first = i;
            break;
        }
    }

    if (first == -1) return false;

    return (first + n / 2 < n && A[first + n / 2] == x);
}

//6. Tìm median của mảng đã sắp xếp. 
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    int n = n1 + n2;
    int i = 0, j = 0, count = 0;
    int mid1 = -1, mid2 = -1;

    while (count <= n / 2) {
        int val;
        if (i < n1 && (j >= n2 || nums1[i] < nums2[j])) {
            val = nums1[i++];
        } else {
            val = nums2[j++];
        }

        if (count == n / 2 - (n % 2 == 0)) mid1 = val;
        if (count == n / 2) mid2 = val;
        
        count++;
    }

    return (n % 2 == 1) ? mid2 : (mid1 + mid2) / 2.0;
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return 0;
}
