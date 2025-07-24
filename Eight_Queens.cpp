// https://open.kattis.com/problems/8queens
// 24/07/2025

#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  bool invalid = false;
  char b[8][8];
  int cnt = 0;
  for(int r = 0; r < 8; r++) {
    for(int c = 0; c < 8; c++) {
      cin >> b[r][c];
      if(b[r][c] == '*') cnt++;
    }
  }
  if(cnt != 8) {
    cout << "invalid" << endl;
    return 0;
  }
  for(int r = 0; r < 8; r++) {
    for(int c = 0; c < 8; c++) {
      if(b[r][c] == '*') { //a queen
        //search in that row
        for(int j = 0; j < 8; j++) {
          if((j != c) && (b[r][j] == '*')) invalid = true;
        }
        //search in that column
        for(int i = 0; i < 8; i++) {
          if((i != r) && (b[i][c] == '*')) invalid = true;
        }
        //search in the left_up to right_down diagonal
        //down dir
        for(int i = r+1, j = c+1; (i<8)&&(j<8); i++, j++) {
          if(b[i][j] == '*') invalid = true;
        }
        //up dir
        for(int i = r-1, j = c-1; (i>=0)&&(j>=0); i--, j--) {
          if(b[i][j] == '*') invalid = true;
        }

        //search in the left_down to right_up diagonal
        //down dir
        for(int i = r-1, j = c+1; (i>=0) && (j<8); i--, j++) {
          if(b[i][j] == '*') invalid = true;
        }

        //up dir
        for(int i = r+1, j = c-1; (i<8) && (j>=0); i++, j--) {
          if(b[i][j] == '*') invalid = true;
        }
      }
      if(invalid) break;
    }
    if(invalid) break;
  }

  if(invalid) 
    cout << "invalid" << endl;
  else
    cout << "valid" << endl;
  return 0;
}
