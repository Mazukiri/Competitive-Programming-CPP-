#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
long long n,d;
long long A=0,B=1;
vector<pair<int ,int>>lixi;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;
    
    for (int i=0;i<n;i++)
    {   
        int x, y;
        cin >> x >> y;
        lixi.push_back({y, x});
    }
    
    sort(lixi.begin(), lixi.end(), greater<pair<int,int>>());
    
    for (int i=0; i<n; i++)
    {
        if(B!=0)
        {
            A += lixi[i].second;
            B += lixi[i].first;
            B = B - 1;
        }
    }
    
    cout<<A;


}
