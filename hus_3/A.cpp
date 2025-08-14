#include <bits/stdc++.h>
using namespace std;
#define int long long
int grid[20][20];
int choice;
const int n = 4;

bool isInside(int x, int y){

    return 1<=x && x<=4 && 1<=y && y<=4;
}

bool canSlideLeft(int x, int y){
    return (isInside(x, y-1) && (grid[x][y-1] == 0 || grid[x][y-1] == grid[x][y]));
}

bool canSlideRight(int x, int y){
    return (isInside(x, y+1) && (grid[x][y+1] == 0 || grid[x][y+1] == grid[x][y]));
}

bool canSlideUp(int x, int y){
    return (isInside(x - 1, y) && (grid[x - 1][y] == 0 || grid[x - 1][y] == grid[x][y]));
}

bool canSlideDown(int x, int y){
    return (isInside(x + 1, y) && (grid[x + 1][y] == 0 || grid[x + 1][y] == grid[x][y]));
}

void updateGridLeft(){
    for (int i = 1; i<=n; i++){
        for (int j = n - 1; j>=1; j--){
            if (grid[i][j] == 0 && grid[i][j+1] != 0) {
                grid[i][j] = grid[i][j+1]; 
                grid[i][j+1] = 0;
            }
        }
    }
}

void updateGridUp(){
    for (int i = 2; i<=n; i++){
        for (int j = 1; j<=n; j++){
            if (grid[i][j] == 0 && grid[i + 1][j] != 0) {
                grid[i][j] = grid[i + 1][j]; 
                grid[i + 1][j] = 0;
            }
        }
    }
}

void updateGridRight(){
    for (int i = 1; i<=n; i++){
        for (int j = n ; j>=2; j--){
            if (grid[i][j] == 0 && grid[i][j-1] != 0) {
                grid[i][j] = grid[i][j-1]; 
                grid[i][j-1] = 0;
            }
        }
    }
}

void updateGridDown(){
    for (int i = 2; i<=n; i++){
        for (int j = 1; j<=n; j++){
            if (grid[i][j] == 0 && grid[i - 1][j] != 0) {
                grid[i][j] = grid[i - 1][j]; 
                grid[i - 1][j] = 0;
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

    for (int i = 1; i<=4; i++){
        for (int j = 1; j<=4; j++){
            cin >> grid[i][j];
        }
    }

    cin >> choice;

    if (choice == 0) {
        for (int i = 1; i<=n; i++){
            for (int j = n; j>=1; j--) {
                if (canSlideLeft(i, j)) {
                    grid[i][j-1] += grid[i][j];
                    grid[i][j] = 0;
                }
            }
        }
        updateGridLeft();
    }

    if (choice == 1){
        for (int i = 2; i<=n; i++){
            for (int j = 1; j<=n; j++) {
                if (canSlideUp(i, j)) {
                    grid[i - 1][j] += grid[i][j];
                    grid[i][j] = 0;
                }
            }    
        }
        updateGridUp();
    }

    if (choice == 2){
        for (int i = 1; i<=n; i++){
            for (int j = 1 ; j<=3; j++) {
                if (canSlideRight(i, j)) {
                    grid[i][j+1] += grid[i][j];
                    grid[i][j] = 0;
                }
            }    
        }
        updateGridRight();
    }

    if (choice == 3){
        for (int i = 4; i>=2; i--){
            for (int j = 1; j<=n; j++) {
                if (canSlideDown(i, j)) {
                    grid[i - 1][j] += grid[i][j];
                    grid[i][j] = 0;
                }
            }    
        }
        updateGridDown();
    }

    for (int i = 1; i<=4; i++){
        for (int j = 1; j<=4; j++){
            cout << grid[i][j] << " ";
        }

        cout << '\n';
    }



    
}