#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5


vector<pair<char,ll>> AB;

void sort(vector<ll>&p, ll k){
  while(true) {
    rep(i,p.size()-1) {
      if(p[i] > p[i+1]) {
        swap(p[i],p[i+1]);
        AB.push_back({'B',k+2*i});
        goto next;
      }
    }
    return;

    next:
    continue;
  }
}

void sortOddEven(vector<ll>&p, ll k, ll t){
  while(true) {
    rep(i,p.size()-1) {
      if(p[i] % 2 == (1-t) && 
         p[i+1] % 2 == t) {
        swap(p[i],p[i+1]);
        AB.push_back({'B',k+2*i});
        goto next;
      }
    }
    return;

    next:
    continue;
  }
  
}



void solve() {
  ll N; cin >> N;
  vector<ll> P[2];
  rep(i,N) {
    ll p;
    cin >> p;
    if(i % 2==0) {
      P[0].push_back(p);
    } else {
      P[1].push_back(p);
    }  
  }

  sortOddEven(P[0],1,0);
  sortOddEven(P[1],2,1);


  rep(i,N/2) {
    if((P[0][i] % 2) == 0 && (P[1][i] % 2) ==1) {
      swap(P[0][i],P[1][i]);
      AB.push_back({'A', i*2+1});
    }
  }

  sort(P[0],1);
  sort(P[1],2);

  cout << AB.size() << endl;
  rep(i,AB.size()) cout << AB[i].first << " " << AB[i].second << endl;
}


int main()
{
  solve();
	return 0;
}