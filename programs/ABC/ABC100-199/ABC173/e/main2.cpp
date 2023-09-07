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
	vector<pair<ll,ll>> A;
	ll p = 0, m  = 0,z = 0;
	rep(i,N){
		ll a;cin>> a;
		if(a == 0) {
			A.push_back({0,0});
			z ++;
		} else {
			A.push_back({abs(a), a});
			if(a > 0) p++;
			else m++;
		}
	}

	sort(A.begin(),A.end(),greater<pair<ll,ll>>());

	if(m==N) { //全項目マイナス
		mint ans=1;
		rep(i,K) ans *= A[A.size()-1-i].second;
		out(ans.val())
		return 0;
	}


	ll cnt = 0;
	mint ans=1;
	rep(i,K) {
		ans *= A[i].second;
		if( A[i].second < 0) cnt++;
	}

	if(cnt % 2 == 0) {
		out(ans.val())
		return 0;
	}

	ll lastm = 1, lastp = -1;

	rep(i,K) {
		if(A[i].second >= 0) lastp = A[i].second;
		else lastm = A[i].second;
	}

	if(lastp == -1) {
		//0未満のものしかない
		ans = ans / lastm;
		reps(i,K,N) if(A[i].second >= 0) { 
			ans *=A[i].second;
			break;
		}
		out(ans.val())
		return 0;
	}

	ll nextm = 1, nextp = -1;

	reps(i,K,N) {
		if(A[i].second >= 0 && nextp == -1) { 
			nextp = A[i].second;
		} else if(nextm==1){
			nextm = A[i].second;
		}

		if(nextp != -1 && nextm != 1) break;
	}

	if(nextm == 1) { // 後ろに0未満はない
		ans = ans / lastm * nextp;
	} else if(nextp == -1) { //後ろに0以上はない
		ans = ans / lastp * nextm;
	} else {
		if( abs(nextp * nextm)  < abs(lastp * lastm) ) { // nextp/lastm < lastp/nextm
			ans = ans / lastp * nextm;
		} else {
			ans = ans / nextp * lastm;
		}
	}
	
	out(ans.val())
	return 0;
}
