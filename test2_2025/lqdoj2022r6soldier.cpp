#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 5e3 + 5;
II A[N];
int n, k;
bool useLess[N], dp[N];

bool isImportant(int index) {

    if (index == -1 || index = n) return false;

    memset(dp, 0, sizeof dp);

    dp[0] = 1;

    ll currValue = A[index].fi;

    A[index].fi = 0;

    for (int index = 0; index < n; index++) {
        for (int runningSum = k - 1; runningSum >= A[index].fi; runningSum--) {
            if (dp[runningSum - A[index].fi]) dp[runningSum] = true;
        }
    }

    A[index].fi = currValue;

    int answer = 0;

    for (int ans = k - 1; ans >= 0; ans--) if (dp[ans]) {
        answer = ans;
        break;
    }

    if (answer + currValue >= k) return true;

    return false;
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("SOLDIER.inp", "r")) {
        freopen("SOLDIER.inp", "r", stdin);
        freopen("SOLDIER.out", "w", stdout);
    }

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> A[i].fi;
        A[i].se = i;
    }

    string ans = "";

    for (int i = 0; i < n; i++) ans += '9';

    sort(A, A + n);

    int left = 0, right = n - 1;

    int startIndex = n;

    while (left <= right) {
        
        int mid = (left + right) >> 1; 
        
        bool isGoodMid = isImportant(mid);

        if (isGoodMid) {
            startIndex = mid;
            right = mid - 1;
        }

        else {
            left = mid + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i < startIndex) ans[A[i].se] = '0';
        else ans[A[i].se] = '1';
    }

    cout << ans;
}