#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
int n, q;
int BLOCKSIZE = 450;
const int N = 2e5 + 5;
vector<vector<int>> pos(N - 4);

int MFQ_BLOCK[505][505];
int A[N];


int find(int val, int l, int r) {
    int left = lower_bound(pos[val].begin(), pos[val].end(), l) - pos[val].begin();
    int right = upper_bound(pos[val].begin(), pos[val].end(), r) - pos[val].begin() - 1;
    
    return max(0, right - left + 1);
}

void preprocess() {

    int numBlocks = n/BLOCKSIZE;

    for (int i = 0; i < numBlocks; i++) {
        for (int j = i; j < numBlocks; j++) {
            
            int left = BLOCKSIZE * j + 1, right = min(BLOCKSIZE * (j + 1),  n);

            for (int index = left; index <= right; index++) {
                MFQ_BLOCK[i][j] = max(MFQ_BLOCK[i][j - 1], 
                                        find(A[index], left, right));
            }   
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i <=n; i++) {
        cin >> A[i];
        pos[A[i]].push_back(i);
        
    }

    preprocess();

    int MOD = n;

    int lastAns = 0;

    for (int i = 1; i <= q; i++) {

        int x, y; cin >> x >> y;

        int l = (x + lastAns) % MOD + 1;
        int r = (y + lastAns) % MOD + 1;

        if (l > r) swap(l, r);

        if (l / BLOCKSIZE == r / BLOCKSIZE) {
            int currAns = 0;
            
            for (int index = l; index <= r; index++) {
                currAns = max(currAns, find(A[index], l, r));
            }

            lastAns = currAns;

            cout << lastAns << '\n';
        }

        else {

            int currAns = 0;

            //loop through leftover on the left segment
            for (int i = l; i < (l / BLOCKSIZE + 1) *BLOCKSIZE; i++) {
                currAns = max(currAns, find(A[i], l, r));
            }

            //loop through leftover on the right segment
            for (int i = 1 + BLOCKSIZE * (r/BLOCKSIZE); i <= r; i++) {
                currAns = max(currAns, find(A[i], l, r));
            }

            //for through all the sub-segments
            currAns = max(currAns, MFQ_BLOCK[l / BLOCKSIZE + 1][r/BLOCKSIZE]);

            lastAns = currAns;

            cout << lastAns << '\n';
        }
    }

    
}