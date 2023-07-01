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
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


vector<string>crop(vector<string>&A){
	ll H =A.size(),W=A[0].size();
	ll l=INF_LL;
	ll r=0;
	ll t=INF_LL;
	ll b=0;
	rep(i,H)rep(j,W){
		if(A[i][j]=='#'){
			l=MIN(l,j);
			r=MAX(r,j);
			t=MIN(t,i);
			b=MAX(b,i);
		}
	}
	
	vector<string>B;
	reps(i,t,b+1){
		string s;
		reps(j,l,r+1)s+=A[i][j];
		B.push_back(s);
	}
	
	return B;
}
 
int main()
{
	ll Ha,Wa,Hb,Wb,Hx,Wx;
	
	cin>>Ha>>Wa;
	vector<string>A(Ha);
	rep(i,Ha)cin>>A[i];
	A=crop(A);
	Ha=A.size();Wa=A[0].size();
	
	
	cin>>Hb>>Wb;
	vector<string>B(Hb);
	rep(i,Hb)cin>>B[i];
	B=crop(B);
	Hb=B.size();Wb=B[0].size();
	
	cin>>Hx>>Wx;
	vector<string>X(Hx);
	rep(i,Hx)cin>>X[i];
	
	// Hb:20,20
	rep(xa,Hx-Ha+1)rep(ya,Wx-Wa+1)
	rep(xb,Hx-Hb+1)rep(yb,Wx-Wb+1){
		char C[Hx][Wx] ;
		rep(i,Hx)rep(j,Wx)C[i][j]='.';
		rep(i,Ha)rep(j,Wa)C[xa+i][ya+j]=A[i][j];
		
		rep(i,Hb)rep(j,Wb)
		if(B[i][j]=='#'||C[xb+i][yb+j]=='#'){
			C[xb+i][yb+j]='#';
		}else C[xb+i][yb+j]='.';
		/*
		cout<<xa<<","<<ya<<"  "<<xb<<","<<yb<<endl;
		
		rep(i,Hx){
			rep(j,Wx) cout<<C[i][j];
			cout<<endl;
		}
		*/
		rep(i,Hx)rep(j,Wx)
		if(C[i][j]!=X[i][j]){
			goto next;
		}
		
		out("Yes")
		return 0;
		next: 
		continue;
		
	}
	
	out("No")
	
	return 0;
}