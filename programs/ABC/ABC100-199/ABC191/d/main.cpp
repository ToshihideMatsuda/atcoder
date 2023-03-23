#include <bits/stdc++.h> 
#include <unordered_map>
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

/*
    string中の特定文字列をstringで置換する
*/
std::string ReplaceString
(
      std::string String1   // 置き換え対象
    , std::string String2   // 検索対象
    , std::string String3   // 置き換える内容
)
{
    std::string::size_type  Pos( String1.find( String2 ) );
 
    while( Pos != std::string::npos )
    {
        String1.replace( Pos, String2.length(), String3 );
        Pos = String1.find( String2, Pos + String3.length() );
    }
 
    return String1;
}

ll manbai(string X) {
	ll l = X.find(".");
	if(l == -1) {
		return stoll( ReplaceString((X + "0000"), ("."),""));
	} else if(l == X.length() - 1){
		//return stoll( ReplaceString((X + "00"), ("."),""));
	} else if(l == X.length() - 2){
		return stoll( ReplaceString((X + "000"), ("."),""));
	} else if(l == X.length() - 3){
		return stoll( ReplaceString((X + "00"), ("."),""));
	} else if(l == X.length() - 4){
		return stoll( ReplaceString((X + "0"), ("."),""));
	}
	return stoll( ReplaceString((X + ""), ("."),"")); 	
}
 

int main()
{
	ll const man = 10000;
	double Xs, Ys, Rs; cin >> Xs >> Ys >> Rs;
	ll X = round(Xs * man);
	ll Y = round(Ys * man);
	ll R = round(Rs * man);



	ll y   = R+Y; //中心の真上の(X,y)
	ll y_m = -R+Y; //中心の真下の(X,y)

	//1万未満を切り捨て
	y /= man;
	y *= man; 
	
	y_m /= man;
	y_m *= man;

	ll ans = 0;
	while(y_m <= y) {

		ll dx = sqrtl(R*R - (y-Y)*(y-Y));

		ll x_p =  X + dx-10000;
		ll x_m =  X - dx+10000;

		
		x_p /= man;
		x_p *= man;
		while((y-Y)*(y-Y) + ((x_p+man) - X)*((x_p+man) - X) <= R*R) x_p += man;
	
		x_m /= man;
		x_m *= man;
		while((y-Y)*(y-Y) + ((x_m-man) - X)*((x_m-man) - X) <= R*R) x_m -= man;

		if(x_m <= x_p) {
			ans += ((x_p - x_m)/man + 1);
		}

		y -= man;
	}
	out(ans)

	//31415920098
	//31415939325


	return 0;
}