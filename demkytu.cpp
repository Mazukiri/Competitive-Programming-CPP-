#include <bits/stdc++.h>
using namespace std;
#define int long long

string clean(string s){

    //Chuẩn hóa xâu về dạng bình thường.

    while (s[0] == '0' && s.size() > 1) s.erase(0, 1);

    return s;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("MM.inp", "r")) {
        freopen("MM.inp", "r", stdin);
        freopen("MM.out", "w", stdout);
    }

    string s; getline(cin, s);

    //Mảng lưu trữ các số được bóc tách ra từ xâu
    vector<string> ans; 

    //Bóc tách các số ra từ xâu và chuẩn hóa chúng
    //Trước khi cho vào mảng và kiểm tra trùng lặp
    
    for (int i = 0; i<s.size(); i++){

        //Phát hiện số đầu tiên của một số
        if (s[i] >= '0' && s[i] <= '9'){

            //Khởi tạo biến number dùng để lưu số đó
            string number = "";
            number += s[i];
            i++;

            //thêm hết các chữ số ở sau đó (nếu có) vào trong biến number
            while (s[i] >= '0' && s[i] <= '9') {
                number += s[i];
                i++;
            }

            //chuẩn hóa biến number
            number = clean(number);
            //thêm biến number vào trong mảng ans. 
            //Nếu sử dụng mảng, thao tác này tương đương ans[index] = number và tăng biến i lên (i++)
            ans.push_back(number);
        }
    }

    //tạo biến đếm kết quả cuối cùng
    int final_ans = 0;
    

    for (int i = 0; i<ans.size(); i++){
        
        int count_multiples = 0; //Đếm các xâu trùng nhau trong mảng
        for (int j = i+1; j<ans.size(); j++){

            if (ans[i] == ans[j] && i != j) count_multiples++; ///phát hiện xâu trùng nhau!!!
        }

        if (count_multiples == 0) final_ans++; //Nếu không phát hiện xâu trùng nhau, tăng đáp án lên
    }

    cout << final_ans;


}