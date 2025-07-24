// A Different Problem
// https://open.kattis.com/problems/different
// 24/07/2025

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  //'int' : mostly signed 32-bit 
  //range : -(2**31) to +((2**31)-1)
  //roughly can take 2**10 as 1000 (instead of 1024)
  //hence range is -(2 * 10**9) to +(2 * 10**9)
  //problem description says input range is 0 to 10**15
  //hence better to take 'long long' instead of 'int'

  long long a, b;

  while(cin >> a >> b) { //read till EOF
    //cout << abs(a-b) << endl;
    cout << ((a > b) ? (a-b) : (b-a)) << endl; 
  }

  return 0;
}
