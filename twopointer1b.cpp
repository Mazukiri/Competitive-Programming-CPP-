#include <bits/stdc++.h>
using namespace std;

vector<int> A;
vector<int> B;


int main() {
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
    
    int n, m,x;
    cin >> n >> m;
    
    for(int i=0;i<n;i++)
    {
        cin>>x;
        A.push_back(x);
    }
    
    for(int i=0;i<m;i++)
    {
        cin>>x;
        B.push_back(x);
    }
    
    int index1 = 0;
    int index2 = 0;

    while (index2 < m){
        while (A[index1] < B[index2] && index1 < n) index1++;
        cout << index1 << " ";
        index2++;
    }

}