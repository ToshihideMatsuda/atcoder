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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll N; cin >> N;
  set<string> S; 
  rep(i,N) {
    string s;
    cin >> s;
    S.insert(s);
  }
  if(S.size() != N) {
    cout << "No" << endl;
    return;
  }

  set<char> one = { 'H' , 'D' , 'C' , 'S' };
  set<char> two = { 'A' , '2' , '3' , '4' , '5' , 
                    '6' , '7' , '8' , '9' , 'T' , 
                    'J' , 'Q' , 'K' };
  for(auto s:S){
    if(!one.count(s[0])) {
    cout << "No" << endl;
    return;
    }

    if(!two.count(s[1])) {
    cout << "No" << endl;
    return;
    }
  }
  cout << "Yes" << endl;
}


int main()
{
  solve();
	return 0;
}