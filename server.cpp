// Server
// https://open.kattis.com/problems/server
// 25/07/2025

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, T;
  int s = 0, o = 0;
  cin >> n >> T;

  while(n--) {
    int t;
    cin >> t;
    s += t;
    if(s <= T) o++;
  }

  cout << o << endl;

  return 0;
}
