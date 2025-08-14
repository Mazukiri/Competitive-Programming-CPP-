#include <bits/stdc++.h>
using namespace std;
int A[100005];

bool BS(int left, int right, int x){

    int mid = (left + right)/2;
    if (A[mid] == x) return true;
    if (A[mid] > x) right = mid - 1; else left = mid+1;
    if (left <= right) BS(left, right, x);
    if (left > right) return false;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    //Bubble: Bong bóng
    //Bubble sort: Sắp xếp nổi bọt

    int n, x; cin >> n >> x;
    for (int i = 1; i<=n; i++) cin >> A[i];

    for (int i = 1; i<=n; i++){
        for (int j = i+1; j<=n; j++) 
        {
            if (A[i] > A[j]) swap(A[i], A[j]);
             
        }
    }

    //bool BS(int left, int right, int x){
    cout << BS(1, n, x);  
}