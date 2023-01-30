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
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)

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

void solve() {
  ll N; cin >> N;
  vector<string> S(N);
  Trie<26,'a'> trie;
  rep(i,N) {
    cin >> S[i];
    trie.insert(S[i]);
  }

  rep(i,N) out(trie.common_word_length(S[i]))
    
}


int main()
{
  solve();
	return 0;
}