#include <bits/stdc++.h>
#include <atcoder/all>

using namespace atcoder;
using namespace std;

// 多倍長テンプレ（デバッグだとダメかも）
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

// 任意長整数型
using bll = mp::cpp_int;

// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using real = mp::number<mp::cpp_dec_float<1024>>;

typedef long long ll;

#define rep(i,n) for(ll i = 0; i < n; i++ )
#define reps(i,m,n) for(ll i = m; i < n; i++ )
#define rev(i,n) for(ll i = n; i > -1; i--)
#define revs(i,m,n) for(ll i = m; i > n; i--)
#define MAX(a,b) (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b) (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out0(s) cout << s;
#define out(s) cout << s << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) pushback(s)

#define SORT(A,R) std::sort((A).begin(),(A).end(), [](auto const& x, auto const& y) { return x R y; });
#define OUT(A,separate) for(auto a : A) { cout << a << separate; }

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define MAX_N (2*100000+5)

/* 双方向リストライブラリ */
class Node {
public:
    ll data;
	ll id;
    ll next;
    ll back;
};


int main() {

    Node header; // ダミーノード
	header . id = -1;
	header . data = -1;
	header . next = -1;
	header . back = -1;
	Node* hp = &(header);

    ll N; cin >> N;

	vector<Node*> ref(N);
	
	map<ll, set<Node*>> mp; // ポインタ型のセットを使う

    rep(i, N) {
        ll a; cin >> a;

		Node* A = new Node;
		A->data = a;
		A->next = -1;
		A->back = hp->id;
		A->id = i;

		ref[i] = A;

		hp->next = A->id;
		hp = A;
		mp[a].insert(A);
    }


	ll id = N;

    ll Q; cin >> Q;
    rep(i, Q) {
        ll t; cin >> t;
        if (t == 1) {
            ll x, y; cin >> x >> y;
            for (Node* n : mp[x]) {
				Node* Y = new Node;
				Y -> data = y;
				Y -> id = id++;
				ref.push_back(Y);

				Y -> next = n->next;
				Y -> back = n->id;
				if(n->next >= 0) {
					ref[n->next]->back = Y -> id;
				}

				n->next = Y -> id;

				mp[y].insert(Y);
            }
        }
        else {
            ll x; cin >> x;
            for (Node* n : mp[x]) {
                if(n->back >= 0) {
					ref[n->back] -> next = n->next;
				}

                if(n->next >= 0) {
					ref[n->next] -> back = n->back;
				}

            }
            mp.erase(x);
        }
    }

    ll p = header.next; // ダミーノードの次から開始
    while (p >= 0) {
		Node* n = ref[p];
        out0(n->data); out0(" ");
		if(n->next >= 0) {
		p = ref[n->next]->id;
		}
    }

    return 0;
}