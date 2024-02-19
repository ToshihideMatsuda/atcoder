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

//max: SegTree<ll> segTreeMax(N+1,    [](ll x, ll y) { return x < y ? y : x; }, -(1LL<<61));
//min: SegTree<ll> segTreeMin(N+1,    [](ll x, ll y) { return x < y ? x : y; }, (1LL<<61));
//sum: SegTree<ll> segTreeSum(N+1,    [](ll x, ll y) { return x + y; }, 0);
//sum: SegTree<ll> segTreeSumMod(N+1, [](ll x, ll y) { return (x + y) % MOD ; }, 0);
//xor: SegTree<ll> segTreeXor(N+1,    [](ll x, ll y) { return x ^ y; }, 0);
template<typename T>
struct SegTree {
    //最大値: compare = [](ll x, lly)
    function<T(T,T)> compare; //比較用関数オブジェクト
    
    // 演算結果に影響しない0元
    // 最小値：inf, 最大値: -inf, sum:0, xor:0
    T ZERO;

    int n;          // 要素数
    vector<T> dat;  // セグメントtree配列
                    // dat[0] 　　　　 :　[0,n)の値
                    // i番目の数列（葉）: dat[i + n - 1]
                    // dat[k]の子要素  : dat[ 2 * k + 1], dat[ 2 * k + 2]
                    // dat[k]の親要素  : dat[ (k - 1) / 2 ]
    
public:
    
    SegTree(int n_, function<T(T,T)> compare_, T Z) {
        int x = 1;
        while(x < n_) {
            x *= 2;         //n以上の 2^m形式に変換
        }
        n = x;
        compare = compare_;
        ZERO = Z;
        
        vector<T>dattmp (n * 2 - 1, ZERO); //セグメント木は、要素数 sz * 2 - 1の配列を準備
        dat = dattmp;
        
    }
    
    
    // 区間[a,b)を値xで更新、遅延評価なし
    void update(int a, int b, T x) { //区間[a,b)を値xで更新
        for(int i = a; i < b; i++) {
            update(i,x);
        }
    }

    // dat[i]を値xで更新、遅延評価なし
    void update(int i, T x) { // i: 更新したい数列の位置（葉の位置）　x: 更新する値
        i += n - 1;                  // i番目の要素は i + n - 1の位置に格納
        dat[i] = x;
        while(i > 0) { //親をたどって値を更新していく
            i = (i - 1) / 2;
            dat[i] = compare(dat[i * 2 + 1], dat[i * 2 + 2] );
        }
    }  
    
    //区間[a,b)の値を取得するクエリ
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); };
    
    //全区間の値を取得するクエリ
    T allquery() { return query_sub(0, n+1, 0, 0, n); };
    
    void debug() {
        cout <<  "---dat---" << endl;
        vector<pair<ll,ll>> list;
        list.push_back({0,n});
        int i = 0;
        while(list.size()< dat.size()) {
            auto [l,r] = list[i++];
            list.push_back({l,l+(r-l+1)/2});
            list.push_back({l+(r-l+1)/2,r});
        }
        for(int i = 0; i < dat.size(); i++) {
            auto [l,r] = list[i];
            string text = "[" + to_string(l) + ", " + to_string(r) + ") = ";
            cout << text;
            if(dat[i] == ZERO) {
                cout << "-" << endl;
            }
            else {
                cout << dat[i] << endl;
            }
        }
        
        cout <<  endl;
    }
    
private:
    T query_sub(int a, int b, int k, int l, int r) {
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


int main(){
    
    SegTree<ll> segTreeMax(10, [](ll x, ll y) { return x < y ? y : x; }, -(1<<61));
    
    segTreeMax.update(1, 2, 4);    // 1 -> 4
    segTreeMax.update(2, 9, 1);    // 2,3,4,5,6,7,8 -> 1
    segTreeMax.update(6, 9, 2);    // 6,7,8 -> 2
    segTreeMax.update(9,10, 5);    // 9 ->5
    
    cout << "segTreeMax.query(6,7) : " << segTreeMax.query(6, 7) << endl;
    
    for(int i = 0;i <= 4; i ++) {
        cout << "segTreeMax.query(" << i << "," << 10 - i << ") : " << segTreeMax.query(i, 10-i) << endl;
    }
    segTreeMax.debug();
    

    SegTree<ll> segTreeMin(10, [](ll x, ll y) { return x < y ? x : y; }, (1LL<<61));
    
    segTreeMin.update(2, 9, 5);    // 2,3,4,5,6,7,8 -> 5
    segTreeMin.update(1, 2, 2);    // 1 -> 2
    segTreeMin.update(6, 9, 4);    // 6,7,8 -> 4
    segTreeMin.update(9,10, 1);    // 9 -> 1
    
    cout << "segTreeMin.query(6,7) : " << segTreeMin.query(6, 7) << endl;
    
    for(int i = 0;i <= 4; i ++) {
        cout << "segTreeMin.query(" << i << "," << 10 - i << ") : " << segTreeMin.query(i, 10-i) << endl;
    }
    segTreeMin.debug();
    
    
    SegTree<ll> segTreeSum(10, [](ll x, ll y) { return x + y; }, 0);
    
    segTreeSum.update(2,9,5);  // 2,3,4,5,6,7,8 -> 5
    segTreeSum.update(1,2,2);  // 1 -> 2
    segTreeSum.update(6,9,4);  // 6,7,8 -> 4
    segTreeSum.update(9,10,1); // 9 ->1
    // 0 2 5 5 5 5 4 4 4 1
    
    cout << "segTreeSum.query(6,7) : " << segTreeSum.query(6, 7) << endl;
    cout << "segTreeSum.query(5,6) : " << segTreeSum.query(5, 6) << endl;
    cout << "segTreeSum.query(4,5) : " << segTreeSum.query(4, 5) << endl;
    cout << "segTreeSum.query(3,4) : " << segTreeSum.query(3, 4) << endl;
    
    for(int i = 0;i <= 4; i ++) {
        cout << "segTreeSum.query(" << i << "," << 10 - i << ") : " << segTreeSum.query(i, 10-i) << endl;
    }
    segTreeSum.debug();
    
    /*
     warning: failed to set breakpoint site at 0x1003a5b59 for breakpoint 1.1: error: 9 sending the breakpoint request
     segTreeMax.query(6,7) : 2
     segTreeMax.query(0,10) : 5
     segTreeMax.query(1,9) : 4
     segTreeMax.query(2,8) : 2
     segTreeMax.query(3,7) : 2
     segTreeMax.query(4,6) : 1
     segTreeMin.query(6,7) : 4
     segTreeMin.query(0,10) : 1
     segTreeMin.query(1,9) : 2
     segTreeMin.query(2,8) : 4
     segTreeMin.query(3,7) : 4
     segTreeMin.query(4,6) : 5
     segTreeSum.query(6,7) : 4
     segTreeSum.query(5,6) : 5
     segTreeSum.query(4,5) : 5
     segTreeSum.query(3,4) : 5
     segTreeSum.query(0,10) : 35
     segTreeSum.query(1,9) : 34
     segTreeSum.query(2,8) : 28
     segTreeSum.query(3,7) : 19
     segTreeSum.query(4,6) : 10
     ---dat---
     35 30 5 12 18 5 - 2 10 10 8 5 - - - - 2 5 5 5 5 4 4 4 1 - - - - - -
     ---lazy---
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
     Program ended with exit code: 0
     */

    return 1;
}

