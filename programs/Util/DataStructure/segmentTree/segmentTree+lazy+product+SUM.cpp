//
//  segmentTree.cpp
//  90mon
//
//
#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;


// vector<ll> data = {1,2,3,4,5};
// SegTreeProductSum<ll> seg(data, [](ll x, ll y) { return x + y;  }, 0, 1);

template<typename T>
struct SegTreeProductSum {

    // 演算結果に影響しない0元
    // 最小値：-inf, 最大値: inf
    T ONE;
    T ZERO;

    private :
    function<T(T,T)> compare; //比較用関数オブジェクト
    
    
    int n;          // 要素数
    vector<T> dat;  // セグメントtree配列
                    // dat[0] 　　　　　　: [0,n)の値
                    // i番目の数列（葉）   : dat[i + n - 1]
                    // dat[k]の子要素    : dat[ 2 * k + 1], dat[ 2 * k + 2]
                    // dat[k]の親要素    : dat[ (k - 1) / 2 ]

    vector<T> lazy; // 遅延評価配列
    
    vector<pair<ll,ll>> area; // 範囲定義 area[k] = [a,b);

public:
    
    SegTreeProductSum(const vector<T>& data, function<T(T,T)> compare_, T Z, T O) {
        int x = 1;
        int n_ = data.size();
        while(x < n_) {
            x *= 2;         //n以上の 2^m形式に変換
        }
        n = x;
        ONE = O;
        ZERO = Z;
        compare = compare_;

        dat = vector<T>(n * 2 - 1, ZERO); //セグメント木は、要素数 sz * 2 - 1の配列を準備
        lazy = vector<T>(n * 2 - 1, ONE); //遅延評価配列も同じ数準備;

        area.push_back({0,n});
        int i = 0;
        while(area.size()< dat.size()) {
            auto [l,r] = area[i++];
            area.push_back({l,l+(r-l+1)/2});
            area.push_back({l+(r-l+1)/2,r});
        }

        build(data, 0, 0, n - 1);
    }
    
    /** dat[a]に値xをかける */
    void update(int a, T x) {
        update(a,a+1,x);
    }

    /** 区間[a,b)に値xをかける　*/
    void update(int a, int b, T x) {
        updateLazy(a, b, x, 0, 0, n);
    }
    
    /** 区間[a,b)の値を取得するクエリ */
    T query(int a, int b) { 
        return query_sub(a, b, 0, 0, n); };
    
    //全区間の値を取得するクエリ
    T allquery() { return query_sub(0, n+1, 0, 0, n); };
    
    void debug() {

        cout <<  "---dat---" << endl;
        for(int i = 0; i < dat.size(); i++) {
            auto [l,r] = area[i];
            string text = "[" + to_string(l) + ", " + to_string(r) + ") = ";
            cout << text;
            if(dat[i] == ONE) {
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
            if(lazy[i] == ONE) {
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
        if(lazy[k] == ONE) return ;

        if(k < n -1) //kは末端ノード（葉）ではない
        {

            auto [l, r] = area[k];
            ll x = lazy[k] / (r - l);

            auto [l1, r1] = area[2 * k + 1];
            auto [l2, r2] = area[2 * k + 2];

            //自分の子要素に伝搬　(子要素は必要であれば次世代に伝搬) 
            lazy[2 * k + 1] *= x * (r1 - l1);
            lazy[2 * k + 2] *= x * (r2 - l2);
            

        }
        dat[k] *= lazy[k];

        lazy[k] = ONE;
    }
    
private:
    void build(const vector<T>& data, int node, int start, int end) {
        if (start == end) {
            dat[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            dat[node] = compare(dat[2 * node + 1], dat[2 * node + 2]);
        }
    }

    void updateLazy(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if(a <= l && r <= b ) {      // 区間にすっぽり収まる際にはlazyを更新
            lazy[k] *= x * (r-l);
            eval(k);
        }  else if( a < r && l < b) { // 一部の区間が収まる場合
            updateLazy(a, b, x, 2 * k + 1, l          , (r + l)/ 2 );
            updateLazy(a, b, x, 2 * k + 2, (r + l) / 2, r );
            dat[k] = compare(dat[k * 2 + 1], dat[k * 2 + 2] );
        } else {
            int i = 0;
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
    
    vector<ll> data = {1,2,3,4,5};
    SegTreeProductSum<ll> seg(data, [](ll x, ll y) { return x + y;  }, 0, 1);

    cout << seg.query(0,5) << endl; // 1+2+3+4+5 = 15
    seg.update(1,3,3); // 1,6,9,4,5
    cout << seg.query(0,5) << endl; // 1+6+9+4+5 = 25
    cout << seg.query(1,2) << endl; // 6
    cout << seg.query(2,3) << endl; // 9

 
    return 1;
}

