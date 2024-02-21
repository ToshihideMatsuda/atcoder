//
//  segmentTree.cpp
//  90mon
//
//
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef long long ll;

//max: SegTree<ll> segTreeSum(N+1,    [](ll x, ll y) { return x + y }, 0 );
template<typename T>
struct SegTree {
        
    // 演算結果に影響しない0元
    // 最小値：inf, 最大値: -inf
    T ZERO;

    private :
    
    function<T(T,T)> compare; //比較用関数オブジェクト

    
    int n;          // 要素数
    vector<T> dat;  // セグメントtree配列
                    // dat[0] 　　　　　　: [0,n)の値
                    // i番目の数列（葉）   : dat[i + n - 1]
                    // dat[k]の子要素    : dat[ 2 * k + 1], dat[ 2 * k + 2]
                    //                    dat
                    // dat[k]の親要素    : dat[ (k - 1) / 2 ]

    vector<T> lazy; // 遅延評価配列

    vector<pair<ll,ll>> area; // 範囲定義 area[k] = [a,b);
    
public:
    
    SegTree(int n_, function<T(T,T)> compare_, T Z) {
        int x = 1;
        while(x < n_) {
            x *= 2;         //n以上の 2^m形式に変換
        }
        n = x;
        ZERO = Z;
        compare = compare_;

        dat = vector<T>(n * 2 - 1, ZERO); //セグメント木は、要素数 sz * 2 - 1の配列を準備
        lazy = vector<T>(n * 2 - 1, ZERO); //遅延評価配列も同じ数準備;

        area.push_back({0,n});
        int i = 0;
        while(area.size()< dat.size()) {
            auto [l,r] = area[i++];
            area.push_back({l,l+(r-l+1)/2});
            area.push_back({l+(r-l+1)/2,r});
        }
    }
    
    // dat[a]を値xで更新
    void update(int a, T x) {
        update(a,a+1,x);
    }

    // 区間[a,b)を値xで更新、最大最小-> 遅延評価。和, XOR, その他-> 通常
    void update(int a, int b, T x) {
        updateLazy(a, b, x, 0, 0, n);
    }
    
    //区間[a,b)の値を取得するクエリ
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); };
    
    //全区間の値を取得するクエリ
    T allquery() { return query_sub(0, n+1, 0, 0, n); };
    
    void debug() {

        cout <<  "---dat---" << endl;
        for(int i = 0; i < dat.size(); i++) {
            auto [l,r] = area[i];
            string text = "[" + to_string(l) + ", " + to_string(r) + ") = ";
            cout << text;
            if(dat[i] == ZERO) {
                cout << "-" << endl;
            }
            else {
                cout << dat[i] << endl;
            }
        }

        cout <<  "---lazy---" << endl;
        for(int i = 0; i < lazy.size(); i++) {
            auto [l,r] = area[i];
            string text = "[" + to_string(l) + ", " + to_string(r) + ") = ";
            cout << text;
            if(lazy[i] == ZERO) {
                cout << "-" << endl;
            }
            else {
                cout << lazy[i] << endl;
            }
        }
        cout <<  endl;
    }
    
    //lazy[k]に登録してあった値を、１階層下の子要素に伝播させて、自身の値も変更
    void eval(int k) {
        if(lazy[k] == ZERO) return ;

        if(k < n -1) //kは末端ノード（葉）ではない
        {
            auto [l, r] = area[k];
            ll x = lazy[k] / (r - l);

            auto [l1, r1] = area[2 * k + 1];
            auto [l2, r2] = area[2 * k + 2];
            //自分の子要素に伝搬　(子要素は必要であれば次世代に伝搬) 
            lazy[2 * k + 1] = x * (r1 - l1);
            lazy[2 * k + 2] = x * (r2 - l2);
        }
        dat[k] = lazy[k];
        lazy[k] = ZERO;
    }
    
private:
    void updateLazy(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if(a <= l && r <= b ) {      // 区間にすっぽり収まる際にはlazyを更新
            lazy[k] = x * (r-l);
            eval(k);
        }  else if( a < r && l < b) { // 一部の区間が収まる場合
            updateLazy(a, b, x, 2 * k + 1, l          , (r + l)/ 2 );
            updateLazy(a, b, x, 2 * k + 2, (r + l) / 2, r );
            dat[k] = compare(dat[k * 2 + 1], dat[k * 2 + 2] );
        }
    }
    
private:
    T query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if(b <= l || r <= a)
            return ZERO;    //区間外
        if(a <= l && r <= b )
            return dat[k]; // 区間にすっぽり収まる
        
        //一部重なる
        T lv = query_sub(a, b, 2 * k + 1, l          , (r + l)/ 2 );
        T rv = query_sub(a, b, 2 * k + 2, (r + l) / 2, r );
        
        return compare(lv,rv);
    }

};


// a以上b以下の整数をランダムに生成する関数
ll randomLL(ll a, ll b) {
    return a + rand() % (b-a+1);
}


int main(){
    
    {
    SegTree<ll> segTreeSum(100, [](ll x, ll y) { return x + y;  }, 0);
    vector<ll> data(100, 0);

    bool valid = true;
    for(int i = 0;i <= 10000; i ++) {
        {
            ll a = randomLL(1,99), b = randomLL(1,99), x = randomLL(1,99999);
            if(a == b) continue;
            ll tmp = max(a,b);
            a = min(a,b);
            b = tmp;
            segTreeSum.update(a,b,x);
            for(int j = a; j < b;j++) data[j] = x;
        }

        {
            ll a = randomLL(1,99), b = randomLL(1,99);

            if(a == b) continue;
            ll tmp = max(a,b);
            a = min(a,b);
            b = tmp;

            ll x = segTreeSum.query(a,b);
            if(x == segTreeSum.ZERO) x = 0;

            ll X = 0;
            for(int j = a; j < b;j++) X += data[j];
            if(x != X) {
                valid = false;
                break;
            }
        }
    }
    if(valid) {
        cout << "valid segTreeSum" << endl;
    } else {
        cout << "invalid segTreeSum" << endl;
    }
    }
    
    return 1;
}

