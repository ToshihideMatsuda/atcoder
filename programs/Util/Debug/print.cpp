
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

/*
Usage

  vector<ll> d{la,ra,lb,rb};
  printVectorLL("(ll la, ll ra, ll lb, ll rb) =", d, false);
  vector<ll> d2{val};
  printVectorLL(",,, val=", d2, true);

*/

void printVectorLL(string prefix,vector<ll> A, bool cr) {
  cout << "printVectorLL:";
  if(prefix.size() > 0) {
    cout << prefix << " ";
  }
  for(ll a : A) {
    cout << a << ",";
  }
  if(cr) cout << endl;
}

void printVectorStr(string prefix,vector<string> A, bool cr) {
  cout << "printVectorLL:";
  if(prefix.size() > 0) {
    cout << prefix << " ";
  }
  for(auto a : A) {
    cout << a << ",";
  }
  if(cr) cout << endl;
}