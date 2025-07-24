// Toilet Seat
// https://open.kattis.com/problems/toilet
// 24/07/2025

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;
  //s[0] indicates initial position of toilet seat. 'U' for up, 'D' for down
  //s[1] .. s[n-1] contain the preferences

  //policy_1 : while leaving, always up
  //policy_2 : while leaving, always down
  //policy_3 : while leaving, as per preference
  char p1s = s[0], p2s = s[0], p3s = s[0]; //state of seat
  int p1 = 0, p2 = 0, p3 = 0;

  for(int i = 1; i < s.length(); i++) {
    //adjust before use, as per preference
    if(p1s != s[i]) {
      p1s = s[i];
      p1++;
    }
    if(p2s != s[i]) {
      p2s = s[i];
      p2++;
    }
    if(p3s != s[i]) {
      p3s = s[i];
      p3++;
    }

    //adjust after use, as per policy
    if(p1s != 'U') {
      p1s = 'U';
      p1++;
    }
    if(p2s != 'D') {
      p2s = 'D';
      p2++;
    }
    if(p3s != s[i]) { //redundant; but for readability
      p3s = s[i];
      p3++;
    }
  }

  cout << p1 << endl;
  cout << p2 << endl;
  cout << p3 << endl;

  return 0;
}
