#include <bits/stdc++.h> 

using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）

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
#define pb(s) push_back(s)
/*
	vector<ll> X = {4,7,3,1,7,9,4};
	SORT(X, <)
	OUT(X,",") //1,3,4,4,7,7,9,

	SORT(X, >)
	OUT(X," ") //9 7 7 4 4 3 1
*/
#define SORT(A,R) std::sort((A).begin(),(A).end(), [](auto const& x, auto const& y) { return x R y; });
#define OUT(A,separate) for(auto a : A) { cout << a << separate; }


#define INF (2147483647)
#define MINF (-2147483648)
#define INF_LL  (9223372036854775807LL)
#define MINF_LL (-9223372036854775808LL)
#define MOD 998244353

#define MAX_N 1000001



int main()
{
	ll N; cin >> N;

	vector<ll> A;
    vector<ll> C(MAX_N);
	rep(i,N) {
        ll a = 0; cin >> a;
        C[a] ++;
        A.push_back(a);
    }

    reps(i,1,MAX_N) C[i] += C[i-1];

	ll ans = 0;

    vector<bool> s(MAX_N,false);

    rep(i,A.size()) {

        ll a = A[i];
        if(s[a]) continue;
        s[a] = true;

        ll add = 0;
		for(int k = a; k < MAX_N; k+= a) {
            if(C[k-1] == N) break;
            add ++;
            ans += (C[a] - C[a-1]) * (C[MIN(k+a,MAX_N)-1] - C[k-1]) * add;
		}
        ans -= (C[a] - C[a-1]) * ((C[a] - C[a-1]) + 1) / 2;        
	}

	out(ans)
	return 0;
}