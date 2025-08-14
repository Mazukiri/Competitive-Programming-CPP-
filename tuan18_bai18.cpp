#include <bits/stdc++.h>
using namespace std;

const long long N = 1e6+5;
string A[N];

int main() {

    if (fopen("_ab.inp", "r")) {
            freopen("_ab.inp", "r", stdin);
            freopen("_ab.out", "w", stdout);
        }
    

    int count_ = 0;
    string words = "";
    string s;
    getline(cin, s);
    s += ' '; // Thêm khoảng trắng để đảm bảo từ cuối cùng được xử lý

    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') {
            words += s[i];
        } else {
            if (!words.empty()) { // Chỉ thêm từ khi không phải là chuỗi rỗng
                A[count_++] = words;
                words = "";
            }
        }
    }

    bool Dem[count_];
    fill(Dem, Dem + count_, false); // Khởi tạo mảng Dem với giá trị false

    for(int i = 0; i < count_; i++) {
        for(int j = i + 1; j < count_; j++) {
            if(A[i] == A[j]){
                Dem[j] = true;
            }
        }
    }

    for(int i = 0; i < count_; i++) {
        if(!Dem[i]) {
            cout << A[i] << " ";
        }
    }
    
    return 0;
} 
