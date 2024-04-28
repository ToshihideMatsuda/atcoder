#include <bits/stdc++.h> 

using namespace std;
typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out0(s) cout << s;
#define out(s)  cout << s << endl;
#define outd(s) cout << setprecision(15) << s << endl;

int main()
{
	ll N, M; cin >> N >> M;
	vector<bool> ok(N);
	ll cnt = 0;
	rep(i,M) {
		ll a, b;
		cin >> a >> b;
		a--;b--;
		if(ok[(a-b+N)%N]) {
			cnt++;
			continue;
		}

		ok[(a-b+N)%N] = true;
	}

	if(cnt > 0) {
		rep(j,N)if(ok[j] == false) {
			cnt--;
			ok[j] = true;
			if(cnt == 0) break;
		}
	}


	out(N*M);
	rep(i,N) if(ok[i]) {
		
		ll a = i, b = 0;
		
		rep(_,N){
			cout << (a+1) << " " << (b+1) << endl;
			a++; a%=N;
			b++; b%=N;
		}

	}



	return 0;
}