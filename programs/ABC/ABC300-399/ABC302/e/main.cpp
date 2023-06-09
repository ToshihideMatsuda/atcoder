#include <bits/stdc++.h> 
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
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*1000+5)
vector<ll>G[MAX_N];

ll d[25][25];

ll S = (1 << 20) + 5;
ll best[25][(1 << 20) + 5];
int main()
{
	ll H,W,T;cin>>H>>W>>T;
	
	vector<pair<ll,ll>>P;
	ll s,g;
	
	char A[H+2][W+2];
	rep(h,H+2)rep(w,W+2)A[h][w]='#';
	reps(h,1,1+H)reps(w,1,W+1){
		cin>> A[h][w];
		if(A[h][w]=='o'){
			P.push_back({h,w});
		}else if(A[h][w]=='G'){
			P.push_back({h,w});
			g=P.size()-1;
		}else if(A[h][w]=='S'){
			P.push_back({h,w});
			s=P.size()-1;
		}
	}

	ll dx[4]={1,-1,0,0};
	ll dy[4]={0,0,1,-1};
	rep(i,P.size()){
		auto p=P[i];
		ll D[H+2][W+2];
		rep(h,H+2)rep(w,W+2)D[h][w]=INF_LL;
		queue<tuple<ll,ll,ll>>Q;
		Q.push({p.first,p.second,0});
	
		while(Q.size()>0){
			ll ph,pw,d;
			tie(ph,pw,d)=Q.front();Q.pop();
			if(d<D[ph][pw]){
				D[ph][pw]=d;
				rep(i,4) if(d+1<D[ph+dx[i]][pw+dy[i]] && A[ph+dx[i]][pw+dy[i]]!='#') {
					Q.push({ph+dx[i], pw+dy[i],d+1 });
				}
			}
		}
		
		rep(j,P.size()){
			d[i][j]=D[P[j].first][P[j].second];
		}
	}
	
	
	int ans =-1;
	queue<tuple<ll,ll,ll>>Q;
	Q.push({s,(1 << s),0});

	rep(i,25) rep(j,S) best[i][j] = INF_LL;
	best[s][(1 << s)] = 0;

	while(Q.size()>0){
		ll p, cost, path;
		tie(p,path,cost) =Q.front();Q.pop();

		ll size = 0;
		rep(i,P.size()) if((path & (1 << i) ) > 0) size ++;
		size--;

		if(best[p][path] < cost) {
			continue;
		}

		rep(i,P.size()) if((path & (1 << i) ) == 0) {
			ll nx = path | (1 << i);
			ll nxCost = cost+d[p][i];
			if(nxCost <= T  && nxCost <= best[i][nx]){
				best[i][nx] = MIN(best[i][nx],nxCost);
				if(i!=g) Q.push({i,nx,nxCost});
				if(i==g && ans < size){
					ans=size;
				}
			}
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
	
}