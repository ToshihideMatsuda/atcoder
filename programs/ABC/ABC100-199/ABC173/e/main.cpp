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

#define MOD (1000000007)

using mint = modint1000000007;

int main(){
	ll N,K;cin>> N>>K;
	vector<ll> pA,mA;
	ll zero = 0;
	rep(i,N){
		ll a;cin>> a;
		if(a>0)		pA.push_back(a);
		else if(a<0)mA.push_back(a);
		else zero ++;
	}
	
	mint ans=1;
	if(pA.size()+mA.size()<K){
		ans = 0;
	} else if(pA.size()+mA.size()==K){
		if(mA.size() % 2 == 1 && zero > 0) { ans = 0; }
		else {
			for(auto p:pA) ans*=p;
			for(auto m:mA) ans*=m;
		}
	} else{
		sort(pA.begin(),pA.end(),greater<ll>());
		sort(mA.begin(),mA.end());
		if(pA.size()==0 && K%2==1){
			rep(i,K) ans *= mA[N-1-i];
			if(zero > 0) ans = 0;
		} else {
			
			mint tmp = 1;
			long double logtmp=0;
			vector<mint>p(K+1);
			vector<long double>logp(K+1);

			p[0]=1;
			logp[0]=0;
			long double maxlog = 0;
			rep(j, MIN(K, pA.size())){
				p[j+1] = p[j]*pA[j];
				logp[j+1]=logp[j]+log2l(pA[j]);
			}

			for(int i=0; i<=MIN(mA.size(),K); i+=2){

				if(i>0){
					tmp *= mA[i-2];
					tmp *= mA[i-1];
					logtmp += log2l(-mA[i-1])+log2l(-mA[i-2]);
				}

				if( K - i <= pA.size()) {
					mint tmp2 = (tmp*p[ K-i]);
					long double logtmp2=logtmp+logp[K-i];
					if(maxlog<logtmp2){
						ans=tmp2;
						maxlog=logtmp2;
					}
				}
			}
		}
	}
	
	cout<<(ans.val());
    return 0;
}
