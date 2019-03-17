#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void run(int, int);

int main() {
  //n=書的數量 m=動作次數
  int n, m;
  //第一行 決定書量/動作數
  cin >> n >> m;
  
  run(n ,m);
}

//動作執行
void run (int n, int m) {
  stack<int> box;
  vector<int> output;
  int book = 65; //A = 65
  int k = 0; //輸出拿出的動作數

  for (int i = 0; i < m; i++) {
    char d; //放入or拿出
    cin >> d; //(輸入的第1值)
    
    //放入書
    if (d == 'a'){
      int t;  //放入的書量
      cin >> t; //(輸入的第2值)
      for (int j = 0; j < t; j++) {
        if (book <= n + 64) {
          box.push(book); //放入 書名
          //cout << box.top();
          book++;
        }
      } 
    }
    //拿出書
    else if (d == 'b') {
      int t; //拿出的書量
      cin >> t; //(輸入的第2值)
      for (int j = 0; j < t; j++) {
        if (box.empty() != true) {
          //取最上面的書名,並放入輸出的vector
          output.push_back(box.top()); 
          //cout << box.top();
          //把最上面的書拿出
          box.pop();
          k++;
        }
      }
    }
  }

  //輸出
  for (int i = 0; i < k; i++) {
    cout << (char)output[i]; //書名以A~Z命名
    if (i != k - 1) {
      cout << " ";
    }
  }
}
  
