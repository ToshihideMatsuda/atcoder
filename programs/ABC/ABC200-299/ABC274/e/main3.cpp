#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 2*100000+5

struct Node {
  ll val = -1;
  ll back = 0;
};

void solve() {
  ll Q; cin >> Q;
  vector<Node> nodes;
  ll idx = 0;
  Node head;
  nodes.push_back(head);
  map<ll,ll> mp;
  vector<ll> X;
  rep(_,Q) {
    string s; cin >> s;
    if(s[0] == 'A') {
      ll x; cin >> x;
      Node next;
      next.val = x;
      next.back = idx;
      nodes.push_back(next);
      idx = nodes.size() - 1;
    } else if(s[0] == 'D') {
      idx = nodes[idx].back;
    } else if(s[0] == 'S') {
      ll y; cin >> y;
      mp[y] = idx;
    } else {
      ll z; cin >> z;
      idx = mp[z];
    }
    cout << nodes[idx].val << " ";
  }
  cout << endl;
}


int main()
{
  solve();
	return 0;
}