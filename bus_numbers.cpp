// Bus Numbers
// https://open.kattis.com/problems/busnumbers
// 25/07/2025

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  vector <int> bnv;

  //Input
  cin >> n;
  while(n--) {
    int bn;
    cin >> bn;
    bnv.push_back(bn);
  }
  bnv.push_back(INT_MAX); // max value of 'int' .. invalid bus number
                          // done so that the last number in the actual input will also be taken care.

  sort(bnv.begin(), bnv.end());
  //for(auto x : bnv) { cout << x << " "; }
  //cout << endl;

  //input : 141 142 143 174 175 180 INT_MAX
  //output: 141-143 174 175 180
  int x = bnv[0];  
  int d = 1;       //diff
  cout << x;
  for(int i = 1; i < bnv.size(); i++) {
    if(bnv[i] == x + d) {
      d++;
    }
    else {
      if(d > 2) {
        cout << "-" << x + d-1; 
        d = 1;
      }
      if(d == 2) {
        cout << " " << x + d-1; 
        d = 1;
      }
      if((d == 1) && (i!=bnv.size()-1)) {
        cout << " " << bnv[i];
      }
      x = bnv[i];
      d = 1;
    }
  }
  cout << endl;

  return 0;
}

// ALTERNATE SOLUTION: 
//  // Bus Numbers
//  // https://open.kattis.com/problems/busnumbers
//  // 25/07/2025
//  
//  #include <bits/stdc++.h>
//  using namespace std;
//  int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//  
//    int n;
//    cin >> n;
//    vector <int> b(n);
//    for(int i = 0; i < n; i++) 
//      cin >> b[i];
//  
//    sort(b.begin(), b.end());
//  
//    for(int i = 0; i < n;  ) {
//      int j = i;
//      while(((j+1)<n) && (b[j+1] == b[j]+1)){
//        j++;
//      }
//      if((j-i+1) > 2) {
//        cout << b[i] << "-" << b[j] << " ";
//      }
//      else {
//        if(i==j){
//          cout << b[i] << " ";
//        }
//        else {
//          cout << b[i] << " " << b[j] << " ";
//        }
//      }
//      i = j+1;
//    }
//  
//    return 0;
//  }
