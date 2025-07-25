// Cold-puter Science
// https://open.kattis.com/problems/cold
// 25/07/2025

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int o = 0;
  int n;
  cin >> n;
  while(n--) {
    int t;
    cin >> t;
    if(t < 0) o++;
  }
  cout << o;

  return 0;
}
