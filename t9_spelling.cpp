// T9 Spelling
// https://open.kattis.com/problems/t9spelling
// 24/07/2025

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string key[10] = {
    " ", //0
    "", //1
    "abc", //2
    "def", //3
    "ghi", //4
    "jkl", //5
    "mno", //6
    "pqrs", //7
    "tuv", //8
    "wxyz", //9
  };

  int n;
  cin >> n;

  
  for(int c = 1; c <= n; c++) {
    string is, os; //input string, output string
    // cin >> is; //doesn't work if there is a space in a line
    if(c==1) cin.ignore(); //to discard '\n'
    getline(cin, is); 

    int pk = 1; //'previous key'

    for(int i = 0; i < is.length(); i++) {
      //search for the character is[i]
      bool found = false;
      for(int k = 0; k < 10; k++) { //keys
        for(int p = 0; p < key[k].length(); p++) { //presses
          if(key[k][p] == is[i]) {
            found = true;
            if(k == pk) os += " ";
            for(int r = 0; r <= p; r++) {
              os += to_string(k);
            }
            pk = k;
          }
          if(found) break;
        }
        if(found) break;
      }
    }

    cout << "Case #" << c << ": " << os << endl;

  }

  return 0;
}
