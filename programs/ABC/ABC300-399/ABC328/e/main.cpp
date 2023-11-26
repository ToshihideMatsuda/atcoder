#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
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


#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353



typedef long long ll;

typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
template <typename Iterator>
inline bool next_combination(const Iterator first, Iterator k, const Iterator last)
{
   /* Credits: Thomas Draper */
   if ((first == last) || (first == k) || (last == k))
      return false;
   Iterator itr1 = first;
   Iterator itr2 = last;
   ++itr1;
   if (last == itr1)
      return false;
   itr1 = last;
   --itr1;
   itr1 = k;
   --itr2;
   while (first != itr1)
   {
      if (*--itr1 < *itr2)
      {
         Iterator j = k;
         while (!(*itr1 < *j)) ++j;
         iter_swap(itr1,j);
         ++itr1;
         ++j;
         itr2 = k;
         rotate(itr1,j,last);
         while (last != j)
         {
            ++j;
            ++itr2;
         }
         rotate(k,itr2,last);
         return true;
      }
   }
   rotate(first,k,last);
   return false;
}

int main()
{
	ll ans = INF_LL;
	ll N, M, K;
	cin >> N >> M >> K;
	vector<tuple<ll,ll,ll>> P;
	rep(i,M) {
		ll u, v, w; 
		cin >> u >> v >> w;
		w %= K;
		P.push_back({u,v,w});
	}

	vector<ll> pattern(M);
	rep(i,M) pattern[i] = i;


	do {


		
		ll tmp = 0;
		vector<ll> G[N+1];
		rep(i,N-1) {
			auto [u,v,w] = P[pattern[i]];
			tmp += w;
			tmp %= K;

			G[u].push_back(v);
			G[v].push_back(u);

		} 
		
		queue<ll> Q;
		Q.push(1);
		set<ll> visited = {1};
		while(Q.size() > 0) {
			auto q = Q.front(); Q.pop();
			for(auto g : G[q]) if(visited.count(g) == false) {
				visited.insert(g);
				Q.push(g);
			}
		}

		if(visited.size() == N) {
			ans = MIN(ans,tmp);
		}

	} while(next_combination(pattern.begin(), pattern.begin() + N-1, pattern.end()));



	out(ans)





	return 0;
}