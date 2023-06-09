#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
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
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)
ll ch[2][26+1];


int main()
{
	string S[2];cin>> S[0]>>S[1];
	
	rep(s,2)rep(i,S[s].size())if(S[s][i]=='@')ch[s][26]++;else ch[s][S[s][i]-'a']++;
	
	int atcoder0=0;
	int atcoder1=0;
	
	
	rep(i,26){
	if(
	i+'a'=='a' ||
	i+'a'=='t' ||
	i+'a'=='c' ||
	i+'a'=='o' ||
	i+'a'=='d' ||
	i+'a'=='e' ||
	i+'a'=='r'){
		if(ch[0][i]>ch[1][i])
		    atcoder0+=abs(ch[0][i]-ch[1][i]);
		else
		    atcoder1+=abs(ch[0][i]-ch[1][i]);
	}else{
		if(ch[0][i]-ch[1][i]!=0){
			cout<<"No";return 0;
		}
	}
	}
	
	
	if(atcoder0<=ch[1][26]&&
	   atcoder1<=ch[0][26])cout<<"Yes";
	else cout <<"No";
	return 0;
}
