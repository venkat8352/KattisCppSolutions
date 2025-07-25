// Mandelbrot
// https://open.kattis.com/problems/mandelbrot
// 25/07/2025

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  //  z(0)    = 0
  //  z(n)    = zx + i * zy
  //  z(n+1)  = z(n)**2 + c
  //  z(n+1)  = z(n)**2 + x + i * y
  //  z(n+1)  = (zx + i * zy)**2 + x + i * y
  //  z(n+1)  = ((zx)**2 - (zy)**2 + x ) + i * (2 * zx * zy + y)
  // | x + i*y | = sqrt(x**2 + y**2)
  int c = 1;
  double x, y;
  int r;
  while(cin >> x >> y >> r) {
    double zx  = 0.0;
    double zx_ = 0.0; //backup of old zx
    double zy  = 0.0;
    double zmod = 0.0;
    bool diverge = false;
    for(int i = 0; i < r; i++) {
      zx_  = zx;
      zx   = zx*zx - zy*zy + x;
      zy   = 2*zx_*zy + y; //caution : wrong answer if 'zx' (new value) is used instead of 'zx_' (old value)
      zmod = sqrt(zx*zx + zy*zy);
      if(zmod > 2.0) {
        diverge = true;
        break;
      }
    }
    if(diverge) {
      cout << "Case " << c << ": OUT" << endl;
    }
    else {
      cout << "Case " << c << ": IN" << endl;
    }
    c++;
  }
  return 0;
}
