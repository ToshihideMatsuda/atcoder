#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define MAX_N 2*100000+5


vector<ll> G[MAX_N];
bool ch[MAX_N];
bool ex = false;

/** 使用方法: 頂点に1からNの番号がついた N頂点 N辺の連結な単純無向グラフG 
 * rep(i,N) {
 *   ll u, v; cin >> u >> v;
 *   G[u].push_back(v);
 *   G[v].push_back(u);
 * }
 * 
 * vector<ll> pre{0};
 * vector<ll> cycle = getcycle(1,pre);
**/
vector<ll> getcycle(ll p, vector<ll>& pre){
  vector<ll> empty;
  if(ex) return empty;

  ch[p] = true;
  for(auto g : G[p]) if(g != pre.back()){
    if(ch[g]) {
      bool start = false;
      vector<ll> cycle;
      for(auto pp : pre) { 
        if(pp == g)
          start = true;

        if(start) {
          cycle.push_back(pp);
        }
      }
      cycle.push_back(p);
      ex = true;
      return cycle;
    }

    pre.push_back(p);
    vector<ll> ret = getcycle(g, pre);
    pre.pop_back();

    if(ret.size() > 0) {
      return ret;
    }
  }
  return empty;
}