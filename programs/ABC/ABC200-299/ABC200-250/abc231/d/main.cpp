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

#define maxN 100005
 
vector<int> G[maxN];
bool checked[maxN];
 
 
 
int edge = 0;
int ver = 0;
bool dfs(int v, int s, int d) {
    checked[v] = true;
    for(auto u : G[v]) {
        if(d > 1)
        {
            if(s == u) {
                return true;
            }   
        }
        if(checked[u] == false) {
            bool ret = dfs(u, s, d+1);
            if(ret == true)
                return true;
        }
    }
 
    return false;
}
 
int main (){
 
    int N, M;
    cin >> N >> M ;
 
    rep(i,M){
        int a,b;
        cin >> a >> b;
        
        G[a].push_back(b);
        G[b].push_back(a);
    }
 
    //全ての要素が2 or 1
    for(auto v: G) {
        if(v.size() >= 3) {
            cout << "No";
            return 0;
        }
    }
 
    for(int i=1;i<=N;i++) {
        edge = 0;
        ver = 0;
        if(checked[i] == false) {
            bool loop = dfs(i, i, 0);
            if(loop) {
                cout << "No";
                return 0;
            }
        }
    }
 
    cout << "Yes";
	return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; i ++)

#define maxN 100005

vector<int> G[maxN];
bool checked[maxN];



int edge = 0;
int ver = 0;
bool dfs(int v, int s, int d) {
    checked[v] = true;
    for(auto u : G[v]) {
        if(d > 1)
        {
            if(s == u) {
                return true;
            }   
        }
        if(checked[u] == false) {
            bool ret = dfs(u, s, d+1);
            if(ret == true)
                return true;
        }
    }

    return false;
}

int main (){

    int N, M;
    cin >> N >> M ;

    rep(i,M){
        int a,b;
        cin >> a >> b;
        
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //全ての要素が2 or 1
    for(auto v: G) {
        if(v.size() >= 3) {
            cout << "No";
            return 0;
        }
    }

    for(int i=1;i<=N;i++) {
        edge = 0;
        ver = 0;
        if(checked[i] == false) {
            bool loop = dfs(i, i, 0);
            if(loop) {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";
	return 0;
}