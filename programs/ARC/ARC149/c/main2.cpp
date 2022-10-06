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
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 2*100000+5

//c[i] = true -> 素数
bool prime[2*1000*1000+9];
void elatsWithFactor(ll N){
  rep(i,2*1000*1000+5) prime[i] = true;
  prime[0] = false;
  prime[1] = false;
	for(ll i= 2; i<N+1;i++){
			for(ll j=2*i;j<N+1;j +=i){
				prime[j] =false;
			}
	}
}

ll mp[1000+5][1000+5];
ll N; 

void solve() {
  cin >> N;
  elatsWithFactor(2*N*N + 5);

  set<ll> odd; 
  set<ll> even; 
  reps(i,1, N*N+1) if(i % 2 == 0) even.insert(i); else odd.insert(i);

  ll surface = 0;
  if(N%2==1) {
    surface = (N*N-1)/2 + 1;
    mp[surface/N + 1][surface % N    ] = 7;
    mp[surface/N    ][surface % N + 1] = 1;
    odd.erase(7);odd.erase(1);

    mp[surface/N + 1][surface % N + 1] = 8;
    mp[surface/N + 2][surface % N    ] = 2;
    even.erase(8);even.erase(2);
  } else {
    surface = N*N/2;
  }


  set<ll> odd_ex; 
  set<ll> even_ex; 
  ll limit = N;

  if(N%2==1) {
    limit--;
  } 
  for(ll i = 0; i < limit; i++) {
    ll ii = surface-1-i;
    if(N%2==1) {
      ii--;
    } 
    if(mp[ii/N + 1][ii%N + 1] != 0) continue;
    for(auto o : odd) if(!odd_ex.count(o)){
      for(auto e : even) if(!even_ex.count(e)) {
        if(prime[o+e] == false) {
          mp[ii/N + 1][ii%N + 1]  = o;
          mp[ii/N + 2][ii%N + 1]  = e;
          odd_ex.insert(o);
          even_ex.insert(e);
          goto next;
        }
      }
    }
    next:
    continue;
  }

  ll i = 0;

  for(auto o : odd) if(!odd_ex.count(o)){
    mp[i/N + 1][i%N + 1]  = o;
    i++;
  }

  i =  (N*N-1)/2  + (N + 1);

  for(auto e : even) if(!even_ex.count(e)){
    mp[i/N + 1][i%N + 1]  = e;
    i++;
  }
  reps(x,1,N+1){
    reps(y,1,N+1) cout <<  mp[x][y] << " ";
    cout << endl;
  }
}


int main()
{
  solve();
	return 0;
}