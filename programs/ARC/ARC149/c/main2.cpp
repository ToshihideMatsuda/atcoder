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
  rep(i,2000+5) prime[i] = true;
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
  vector<ll> even; 
  reps(i,1, N*N+1) if(i % 2 == 0) even.push_back(i); else odd.insert(i);

  reverse(even.begin(),even.end()); 
  set<ll> odd2(odd); 

  ll i = 0;
  ll H = 0, W = 0;
  if(N % 2 == 0) { // even
    H = N/2; W = N;
  } else {         // odd
    H = N-1; W = (N+1)/2;
  }

  for(auto e : even) if(e != 8) {
    mp[i/W+1][i%W+1] = e;
    i ++;
  }

  mp[H][W] = 8;
  
  if(N % 2 == 0) { // even
    reps(j,1,N) {
      for(auto o : odd) if(odd2.count(o)) {
        if( prime[ mp[H][j] + o]) continue;
        odd2.erase(o);
        mp[H+1][j] = o;
        break;
      }
    }
  } else if(W == (N+1)/2) { // odd
    mp[H][W+1] = 1;
    mp[H+1][W] = 7;
    odd2.erase(1);
    odd2.erase(7);

    reps(h,1,H) {
      for(auto o : odd) if(odd2.count(o)) {
        if( prime[ mp[h][W] + o]) continue;
        odd2.erase(o);
        mp[h][W+1] = o;
        break;
      }
    }

    reps(w,1,W) {
      for(auto o : odd) if(odd2.count(o)) {
        if( prime[ mp[H][w] + o]) continue;
        odd2.erase(o);
        mp[H+1][w] = o;
        break;
      }
    }
  } 


  vector<ll> o;
  for(auto i : odd2) o.push_back(i);

  ll id = 0;
  reps(h,1,N+1)reps(w,1,N+1) if(mp[h][w] == 0){
    mp[h][w] = o[id++];
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