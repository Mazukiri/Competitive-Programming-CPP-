#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
string s;

int nums[1000];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> s;
    string number = ""; int index = 0;
    
    //stoi = string to integer


    //Tìm ra các số trong sâu. Lưu nó vào trong một mảng số
    for (int i = 0; i<s.size(); i++){

        while (s[i] >= '0' && s[i] <= '9') {
            number += s[i];
            i++;
        }
        
        if (number != ""){
            index++;
            nums[index] = stoi(number);
            number = "";
        }
        
    }

    //Sắp xếp các số đã lọc được theo thứ tự tăng dần
    sort(nums, nums + index + 1);

    //Khởi tạo lại index
    index = 0;



    //Xóa số cũ và cập nhật số mới vào xâu
    for (int i = 0; i<s.size(); i++){

        if (s[i] >= '0' && s[i] <= '9'){

            int first = i, last = i;
            
            i++;
            
            while (s[i] >= '0' && s[i] <= '9') {
                last++;
                i++;
            }

            s.erase(first, last - first + 1);
            index++;

            string new_number = to_string(nums[index]);

            s.insert(first, new_number);

            i = first + new_number.size() - 1;   
        }
    }

    //In ra kết quả
    cout << s;
}