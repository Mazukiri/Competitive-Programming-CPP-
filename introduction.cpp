#include <bits/stdc++.h>
//std: Standard Library 
using namespace std;
int A[1001][1001];
//sumRow[i] = tong cac phan tu cua hang i
//sumColumn[i] = tong cac phan cua cot i
int sumRow[1000001], sumColumn[1000001]; 
//check[i][j] = true thi in ra A[i][j], check[i][j] = false
bool check[1001][1001];
//
int maxSumRows = 0; int posMaxSumRows;
int maxSumCols = 0; int posMaxSumCols;
//hang 1, cot 5
//Khoi tao cac du lieu can thiet
void init(int n, int m){
    
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++) {
            check[i][j] = true;
            sumRow[i] = 0;
            sumColumn[j] = 0;
        }
    }
}

void enterArray(int n, int m){
    
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++) {
            cin >> A[i][j];
        }
    }
}

void findSumRowsAndColumns(int n, int m){
    //Calculate the sum of Columns and Rows respectively
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++) {
            sumRow[i] += A[i][j];
            sumColumn[j] += A[i][j]; 
        }
    }
}

void findDeletedRowsAndColumns(int n, int m){
    for (int i = 1; i<=n; i++) {
        if (maxSumRows < sumRow[i]){
            
            maxSumRows = sumRow[i];
            posMaxSumRows = i;
        }
    }

    for (int i = 1; i<=m; i++) {
        if (maxSumCols < sumColumn[i]){
            
            maxSumCols = sumColumn[i];
            posMaxSumCols = i;
        }
    }
}

void MarkTheDeletedRowsAndColumns(int n, int m){
    for (int i = 1; i<=m; i++) check[posMaxSumRows][i] = false;
    for (int i = 1; i<=n; i++) check[i][posMaxSumCols] = false;
}

void PrintResult(int n, int m){
    
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++) {
            if (check[i][j]) cout << A[i][j] << " ";
        }

        if ((i == 1) && (!check[1][1])) continue;
        cout << '\n';
    }
}

int main() {
    if (fopen("dp.inp", "r")) {
            freopen("dp.inp", "r", stdin);
            freopen("dp.out", "w", stdout);
        }
    
    int n, m; cin >> n >> m;

    init(n, m);
    enterArray(n, m);
    findSumRowsAndColumns(n, m);
    findDeletedRowsAndColumns(n, m);
    MarkTheDeletedRowsAndColumns(n, m);
    PrintResult(n, m);
}

