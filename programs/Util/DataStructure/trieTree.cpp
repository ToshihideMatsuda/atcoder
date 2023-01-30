#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


typedef long long ll;
#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 

//Trie<26,'a'> trie, Trie<26,'A'>　trie で初期化する
template <ll char_size, char base>
struct Trie {
    struct Node { // 頂点を
        vector<ll> next;         // 子の頂点番号を格納。存在しなければ-1
        vector<ll> acceptWordId; // 末端がこの頂点になるwordId
        ll c;                    // base からの間隔をll型で表現したもの
        ll common;               // いくつの文字列がこの頂点を共有しているか
        Node(ll c_)  {
            c = c_;
            common = 0;
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
        _insert(word, nodes[0].common);
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
        return (nodes[0].common);
    }
    // Trie木のノード数
    ll size() const {
        return ((ll)nodes.size() -1);
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
            nodes[node_id].common ++;

            //現在の頂点を更新
            node_id = next_id;
        }
        nodes[node_id].common++;
        nodes[node_id].acceptWordId.push_back(word_id); // 単語の終端なので、頂点に番号を入れておく
    }


};

int main() {
    Trie<26, 'A'> trie;
    cout << trie.count() << endl;  // 1 を返す
    trie.insert("FIRE");
    cout << trie.search("FIRE") << endl;  // 1 を返す
    cout << trie.search("FI") << endl;    // 0 を返す
    trie.insert("FIREMAN");
    trie.insert("FIREARM");
    trie.insert("FIREWORK");
    trie.insert("ALGO");
    cout << trie.search("FIRE") << endl;  // 1 を返す
    cout << trie.search("FI") << endl;    // 0 を返す
    
    cout << trie.start_with("FIREARM") << endl;  // 1 を返す
    cout << trie.search("FIREARM") << endl;  // 1 を返す
    return 0;
}