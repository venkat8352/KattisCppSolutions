// Path Tracing
// https://open.kattis.com/problems/pathtracing
// 25/07/2025

#include <bits/stdc++.h>
using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int x = 0, y = 0;
  int minX = 0, maxX = 0, minY = 0, maxY = 0;
  vector <int> vx, vy;
  
  //Take origin(0,0) as the start point
  vx.push_back(x);
  vy.push_back(y);

  string s;
  while(cin >> s) {
    if(s == "up")    y += 1;
    if(s == "down")  y -= 1;
    if(s == "left")  x -= 1;
    if(s == "right") x += 1;
    vx.push_back(x);
    vy.push_back(y);
    if(x < minX) minX = x;
    if(x > maxX) maxX = x;
    if(y < minY) minY = y;
    if(y > maxY) maxY = y;
  }

  //for boundary with #
  minX -= 1; maxX += 1; 
  minY -= 1; maxY += 1; 

  vector<string> vs;

  //(0,0) is S   (x,y) is E
  for(int r = maxY; r >= minY; r--) {
    string rs;
    for(int c = minX; c <= maxX; c++) {
      if((r == minY) || (r == maxY) || (c == minX) || (c == maxX)) {
        rs += '#';
        continue;
      }
      if((r == 0) && (c == 0)) {
        rs += 'S';
      }
      else if((r == y) && (c == x)) {
        rs += 'E';
      }
      else {
        //search if current point is in the path
        bool found = false;
        for(int i = 0; i < vx.size(); i++) {
          if((r==vy[i]) && (c==vx[i])) {
            found = true;
            break;
          }
        }
        if(found) rs += '*';
        else      rs += ' ';
      }
    }
    vs.push_back(rs);
  }
  
  for(auto p: vs) {
    cout << p << endl;
  }

  return 0;
}
