#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）
/* ---------------------- ここから ---------------------- */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using bll = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */

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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

//Trie<26,'a'> trie, Trie<26,'A'>　trie で初期化する
template <ll char_size, char base>
struct Trie {
    struct Node { // 頂点を
        vector<ll> next;         // 子の頂点番号を格納。存在しなければ-1
        vector<ll> acceptWordId; // 末端がこの頂点になるwordId
        ll c;                    // base からの間隔をll型で表現したもの
        ll childWordCnt;         // いくつの文字列がこの頂点を共有しているか
        Node(ll c_)  {
            c = c_;
            childWordCnt = 0;
            next.assign(char_size, -1);
        }
    };

    vector<Node> nodes;  // trie 木本体
    ll root; // 根
    Trie() {
        // 初期化。はじめは根しか無い
        root = 0;
        nodes.push_back(Node(root));
    }

public:
    //単語wordの挿入
    void insert(const string &word) {
        //
        _insert(word, nodes[0].childWordCnt);
    }


    // wordと完全一致する
    bool search(const string &word) {
        return _search(word, false);
    }
    // prefix を持つ単語が存在するかの検索
    bool start_with(const string &prefix) {
        return _search(prefix, true);
    }
    // 挿入した単語の数
    ll count() const {
        return (nodes[0].childWordCnt);
    }
    // Trie木のノード数
    ll size() const {
        return ((ll)nodes.size() -1);
    }

    // 単語とprefixの検索
    ll common_word_length(const string &word) {
        ll node_id = 0;
        ll length = 0;
        rep(i,word.size()) {
            ll c = (ll)(word[i] - base);
            ll &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ終了
                return -1;
            }
            if(nodes[next_id].childWordCnt >= 2) {
                length = i+1;
            }
            node_id = next_id;
        }
        return  length;
    }

	ll sum_common_word_length(const string &word) {
        ll node_id = 0;
		ll ret = 0;
        rep(i,word.size()) {
            ll c = (ll)(word[i] - base);
            ll &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ終了
                return ret;
            }
            node_id = next_id;
			if(nodes[node_id].childWordCnt > 0) {
				ret += nodes[node_id].childWordCnt;
			}
        }
        return ret;
	}

private:

    // 単語とprefixの検索
    bool _search(const string &word, bool prefix = false) {
        ll node_id = 0;
        rep(i,word.size()) {
            ll c = (ll)(word[i] - base);
            ll &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ終了
                return false;
            }
            node_id = next_id;
        }
        return (prefix) ? true : nodes[node_id].acceptWordId.size() > 0;
    }

    void _insert(const string &word, ll word_id) { // 単語:str と 単語の番号: str_id
        ll node_id = 0;
        rep(i,word.size()) {
            ll c = (ll)(word[i] - base);
            
            //次の頂点を取得
            ll &next_id = nodes[node_id].next[c];

            if (next_id == -1) {  // 次の頂点が存在しなければ追加
                next_id = (ll)nodes.size();
                nodes.push_back(Node(c));
            }
            //インクリメント
            nodes[node_id].childWordCnt ++;

            //現在の頂点を更新
            node_id = next_id;
        }
        nodes[node_id].childWordCnt++;
        nodes[node_id].acceptWordId.push_back(word_id); // 単語の終端なので、頂点に番号を入れておく
    }


};


int main()
{
	ll N; cin >> N;
	vector<string> S(N);
	Trie<26,'a'> trie;
	ll ans = 0;

	rep(i,N) cin >> S[i];
	for(int i = N-1; i > -1; i --) {
		ans += trie.sum_common_word_length(S[i]);
		trie.insert(S[i]);
	}
	out(ans)

	return 0;
}