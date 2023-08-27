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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

struct Edge {
	pair<double,double> xy;
	Edge* next;
};

int main()
{
	ll N; cin >> N;
	vector<pair<double,double>> XY(N);
	rep(i,N) {
		double x, y; cin >> x >> y;
		XY[i] = {x,y};
	}

	Edge *path = new Edge, *end = new Edge;
	path->xy = XY[0];
	path->next = end;
	end->xy = XY[N-1];
	end->next = 0;

	reps(i,1,N-1) {
		Edge* min = 0;
		double dif = INF_LL;
		auto [x,y] = XY[i];

		Edge* head = path;
		while(head->next) {
			auto [x0,y0] = head->xy;
			auto [x1,y1] = head->next->xy;

			double d  = sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
			double d1 = sqrt((x0-x)*(x0-x)   + (y0-y)*(y0-y));
			double d2 = sqrt((x-x1)*(x-x1)   + (y-y1)*(y-y1));


			if( d1+d2-d < dif) {
				min = head;
				dif = d1+d2 -d;
			} 

			head = head->next;
		}

		Edge *e = new Edge;
		e->xy = XY[i];
		e->next = min->next;
		min->next = e;

	}

	ll p = 1;
	double s = 0;
	{
		Edge* head = path;
		while(true) {

			Edge* max = 0;
			double dif = 0;
			while(head->next->next) {
				auto [x0,y0] = head->xy;
				auto [x1,y1] = head->next->xy;
				auto [x2,y2] = head->next->next->xy;

				double d0_1 = sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
				double d1_2 = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
				double d0_2 = sqrt((x0-x2)*(x0-x2) + (y0-y2)*(y0-y2));

				if( dif <  d0_1 + d1_2 - d0_2) {
					max = head;
					dif = d0_1 + d1_2 - d0_2;
				} 

				head = head->next;
			}

			if(p < dif) {
				s += p;
				p *= 2;
				max->next = max->next->next;
			} else {
				break;
			}

		}
	}

	{
		Edge* head = path;
		while(head->next) {
			auto [x0,y0] = head->xy;
			auto [x1,y1] = head->next->xy;
			double d  = sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
			s += d;
			head = head->next;
		}
	}
	outd(s);






	return 0;
}