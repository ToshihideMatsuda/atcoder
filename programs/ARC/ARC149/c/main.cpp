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
bool c[2*1000*1000+9];
void elatsWithFactor(ll N){
  rep(i,2000+5) c[i] = true;
  c[0] = false;
  c[1] = false;
	for(ll i= 2; i<N+1;i++){
			for(ll j=2*i;j<N+1;j +=i){
				c[j] =false;
			}
	}
}

ll mp[1000+5][1000+5];
ll N; 

void solve() {
  cin >> N;
  elatsWithFactor(2*N*N + 5);

  vector<ll> perm;
  vector<ll> odd; 
  set<ll> even; 
  reps(i,1, N*N+1) if(i % 2 == 0) even.insert(i); else odd.push_back(i);


  reverse(odd.begin(),odd.end());
  ll i = 0;
  if(N % 2== 1) {
    for(auto o : odd)if(!(o == 7 || o == 1)){
      mp[i/N+1][i%N+1] = o;
      i ++;
    }

    mp[i/N+1][i%N+1] = mp[i/N][i%N+3];
    mp[i/N][i%N+3] = 1;
    i++;

    mp[i/N+1][i%N+1] = 7;
    i++;
  } else {
    for(auto o : odd){
      mp[i/N+1][i%N+1] = o;
      i ++;
    }
  }



    
  set<ll> even2(even);

  rep(_,N) {
    for(auto e : even) if(even2.count(e)) {

      bool ng = false;
      if(mp[i/N+1][i%N] > 0) ng = ng || c[ mp[i/N+1][i%N] + e] ;
      if(mp[i/N][i%N+1] > 0) ng = ng || c[ mp[i/N][i%N+1] + e] ;
        
      if(ng) continue;

      even2.erase(e);
      mp[i/N+1][i%N+1] = e;
      i++;
      break;
    }
  }

  for(auto e : even2){
    mp[i/N+1][i%N+1] = e;
    i ++;
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