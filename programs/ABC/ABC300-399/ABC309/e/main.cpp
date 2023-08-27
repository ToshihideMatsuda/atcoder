#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out0(s) cout << s;
#define out(s) out1(s)
#define out1(s) cout << s << endl;
#define out2(s,t) cout << s << t << endl;
#define out3(s,t,r) cout << s << t << r << endl;
#define out4(s,t,r,u) cout << s << t << r << u << endl;
#define out5(s,t,r,u,o) cout << s << t << r << u << o << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD (1000000000+7)
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)


long long modPow(long long x, long long a) {
  if (a == 0) return 1;
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1)) % MOD;
  long long t = modPow(x, a / 2);
  return (t * t) % MOD;
}


long long modInv(long long x) {
  return modPow(x, MOD - 2);
}

int main(){
	ll N,K;cin>> N>>K;
	vector<ll> pA,mA;
	rep(i,N){
		ll a;cin>> a;
		if(a>0)pA.push_back(a);
		else mA.push_back(a);
	}
	
	sort(pA.begin(),pA.end(),greater<ll>());
	sort(mA.begin(),mA.end());
	mA.push_back(0);
	pA.push_back(0);
	
	ll i=0,j=0;
	ll ans=1;
	while(i+j<N){
		if(pA[i]>=mA[j]){
			ans*=pA[i];
			ans%=MOD;
			i++;
		} else{
			ans*=-mA[j];
			ans%=MOD;
			j++;
		}
	}
	
	if(j%2==0){
		//nop
	}else{
		if(i==pA.size()-1] {
			//only p-=1; m+=1
			ans *= modInv(pA[i-1]);
			ans %= MOD;
			ans *= -mA[j];
			ans %= MOD;
		} else if(j==mA.size()-1) {
			//only 
			ans *= modInv(-mA[j-1]);
			ans %= MOD;
			ans *= pA[i];
			ans %= MOD;
		} else {
			// p-=1; m+=1
			ll d1 = pA[i-1];
			ll p1 = -mA[j];
			
			// p+=1; m-=1
			ll d2 = -mA[j-1];
			ll p2 = pA[i];
			if(p1*d2 < p2*d1) {
				
			}





		}
	}
	
	
	cout<<(ans);
    return 0;
}
