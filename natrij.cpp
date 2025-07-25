// Natrij
// https://open.kattis.com/problems/natrij
// 25/07/2025

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string ct; //current time
  string et; //explosion time
  string tr; //timer value

  cin >> ct;
  cin >> et;

  int cth = stoi(ct.substr(0, 2)); //stoi : string to int,   substr(<start_index>, <length>)
  int ctm = stoi(ct.substr(3, 2));
  int cts = stoi(ct.substr(6, 2));
  int eth = stoi(et.substr(0, 2)); 
  int etm = stoi(et.substr(3, 2));
  int ets = stoi(et.substr(6, 2));
  int trh = eth - cth;
  int trm = etm - ctm;
  int trs = ets - cts;

  if(trs < 0) {
    // trs = ets - cts
    // trs = [00:59] - [00:59]
    // trs = [-59:59]
    trm--;     // borrow 1 minute
    trs += 60; // 1 minute = 60 seconds
  }
  if(trm < 0) {
    // trm = etm - ctm
    // trm = [00:59] - [00:59]
    // trm = [-59:59]
    trh--;     // borrow 1 hour
    trm += 60; // 1 hour = 60 minutes
  }
  if(trh < 0) {
    // trh = eth - cth
    // trh = [00:23] - [00:23]
    // trh = [-23:23]
    trh += 24; // borrow 1 day .. 1 day = 24 hours
  }

  //if exact same time next day, it would be 24 hours
  if((trh == 0) && (trm == 0) && (trs == 0)) trh += 24;

  //printf("%02d:%02d:%02d", trh, trm, trs);
  cout << setw(2) << setfill('0') << trh << ":";
  cout << setw(2) << setfill('0') << trm << ":";
  cout << setw(2) << setfill('0') << trs << endl;

  return 0;
}
