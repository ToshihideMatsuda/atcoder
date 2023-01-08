#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

// l~rの範囲の乱数を生成
ll Mesenne_twister(ll l, ll r) {
  //64bit メルセンヌ ツイスター
  random_device seed_gen;
  mt19937_64 engine(seed_gen());

  ll ret = 0;
  do {
    ret = engine() % r;
  } while(ret <  l);
  return ret;

}