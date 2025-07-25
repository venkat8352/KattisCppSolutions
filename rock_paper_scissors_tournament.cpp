// Rock-Paper-Scissors Tournament
// https://open.kattis.com/problems/rockpaperscissors
// 25/07/2025

#include <bits/stdc++.h>
using namespace std;

int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  //cout.tie(0);

  bool first = true;

  while(true) {
    int n;
    cin >> n;
    if(n == 0) break;
    int k; 
    cin >> k;

    if(first) {
      first = false;
    }
    else {
      cout << endl;
    }

    // 'n' players, each play 'k' number of games with each other
    // number of pairs : n * (n-1) / 2
    // number of games : k * pairs  :    (k * n * (n-1))/2
    int g = (k * n * (n-1)) / 2;
    vector <int> w(n+1, 0); // n+1 int's (due to 1-based input), all initialized to 0
    vector <int> l(n+1, 0);
    while(g-- > 0){
      int p1, p2;
      string c1, c2;
      cin >> p1 >> c1 >> p2 >> c2;
      if(c1 == c2) {
        continue;
      }
      else if( 
        ( (c1 == "paper"   ) && (c2 == "rock"    ) ) ||
        ( (c1 == "scissors") && (c2 == "paper"   ) ) ||
        ( (c1 == "rock"    ) && (c2 == "scissors") )
        ) {
        w[p1] += 1;
        l[p2] += 1;
      }
      else {
        l[p1] += 1;
        w[p2] += 1;
      }
    }
    for(int i = 1; i < w.size(); i++) {
      double wa;
      if((w[i] + l[i]) == 0) {
        cout << "-" << endl;
      }
      else {
        wa = double(w[i]) / double(w[i] + l[i]);
        printf("%.3lf\n", wa);
      }
    }
  }

  return 0;
}
