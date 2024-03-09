#include <bits/stdc++.h>
using namespace std;

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
#define pb(s) pushback(s)

/* 双方向リストライブラリ */
template<typename T>
class LinkedList {
public:
    T data;
    LinkedList<T>* next; // ポインタ型を使う
    LinkedList<T>* back;

	//初期化
    LinkedList(T v) {
        data = v;
        next = nullptr;
        back = nullptr;
    }

	// this <---> next の間にvalue値の新ノードを挿入
    LinkedList<T>* insert_next(T value) {
        LinkedList<T>* next = new LinkedList<T>(value); // 動的に確保
		if (has_next()) {
			this->next->back = next;
		}
        next->next = this->next;
        next->back = this;

        this->next = next;

		return this->next;
    }

	// back <---> this の間にvalue値の新ノードを挿入
	LinkedList<T>* insert_back(T value) {
        LinkedList<T>* back = new LinkedList<T>(value); // 動的に確保
		if (has_back()) {
			this->back->next = back;
		}
        back->next = this;
        back->back = this->back;
        this->back = back;
		return this->back;
    }

	//このノードを削除する
    void erase() {
        if (has_back()) {
            this->back->next = this->next;
        }
        if (has_next()) {
            this->next->back = this->back;
        }
    }
	
	//次ノードが存在するか？
	bool has_next() {
		return (this->next) != nullptr;
	}

	//前ノードが存在するか？
	bool has_back() {
		return (this->back) != nullptr;
	}

	//ポインタが一致しないと一致とは認めない。
    bool operator==(const LinkedList<T>& other) const {
		LinkedList<T>* otherP = &(other);
        return this == otherP;
    }

	//値でソートする
    bool operator<(const LinkedList<T>& other) const {
        return data < other.data;
    }
};

//ABC344 E
int main() {
    LinkedList<ll> header(-1); // ダミーノード
    LinkedList<ll> *p = &(header); // ポインタを使う
    map<ll, set<LinkedList<ll>*>> mp; // ポインタ型のセットを使う


    ll N; cin >> N;
    rep(i, N) {
        ll a; cin >> a;
        p->insert_next(a); // ポインタを進める
		p = p->next;
		mp[a].insert(p);
    }

    ll Q; cin >> Q;
    rep(i, Q) {
        ll t; cin >> t;
        if (t == 1) {
            ll x, y; cin >> x >> y;
            for (auto p : mp[x]) {
				p->insert_next(y);
				mp[y].insert(p->next);
            }
        }
        else {
            ll x; cin >> x;
            for (auto p : mp[x]) {
                p->erase();
            }
            mp.erase(x);
        }
    }

    LinkedList<ll>* pp = header.next; // ダミーノードの次から開始
    while (true) {
        out0(pp->data); out0(" ");
		if(pp->has_next()) pp = pp->next; 
		else break;

    }

    return 0;
}