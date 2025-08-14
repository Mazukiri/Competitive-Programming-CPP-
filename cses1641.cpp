#include <bits/stdc++.h>
using namespace std;
#define II pair<int,int>
#define fi first
#define se second
int n; long long target; 
int const N = 1e6 + 5;
II A[N];

bool check(int index1, int index2, int mid){
    if (A[index1].fi + A[index2].fi + A[mid].fi == target) return true;

    return false;
}

int bs(int index1, int index2){

    int left = index2 + 1, right = n;

    while (left <= right){
        
        int mid = (left + right)/2;
        if (check(index1, index2, mid)) return mid;
        if (A[index1].fi + A[index2].fi + A[mid].fi <= target) left = mid + 1;
        else right = mid - 1;
         
    }

    return -1;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> target;

    for (int i = 1; i<=n; i++) {
        cin >> A[i].fi;
        A[i].se = i;
    }

    sort(A + 1, A + 1 + n);

    for (int i = 1; i<=n-2; i++){
        for (int j = i+1; j<=n-1; j++){

            int k = bs(i, j);
            if (k != -1) {
                
                cout << A[i].se << " " << A[j].se << " " <<A[k].se;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";

    

    
}