//
//  segmentTree.cpp
//  90mon
//
//
#include <iostream>
#include <vector>
#include <limits>

using namespace std;


template<typename T>
struct SegTree {
    private :
#define MIN_MODE    0
#define MAX_MODE    1
#define SUM_MODE    2
#define XOR_MODE    3
    int mode =  MIN_MODE;  // 0:最小値, 1:最大値, 2:和, 3:XOR
    
    const T P_INF = numeric_limits<T>::max();
    const T M_INF = numeric_limits<T>::min();
    
    // 演算結果に影響しない0元
    // 最小値：inf, 最大値: -inf, sum:0, xor:0
    T ZERO;
    
    
    int n;          // 要素数
    vector<T> dat;  // セグメントtree配列
                    // dat[0] 　　　　　　: [0,n)の値
                    // i番目の数列（葉）   : dat[i + n - 1]
                    // dat[k]の子要素    : dat[ 2 * k + 1], dat[ 2 * k + 2]
                    //                    dat
                    // dat[k]の親要素    : dat[ (k - 1) / 2 ]

    vector<T> lazy; // 遅延評価配列
    
public:
    
    SegTree(int n_, int mode_) {
        int x = 1;
        while(x < n_) {
            x *= 2;         //n以上の 2^m形式に変換
        }
        n = x;
        setMode(mode_);
        
        vector<T>dattmp (n * 2 - 1, ZERO); //セグメント木は、要素数 sz * 2 - 1の配列を準備
        dat = dattmp;
        vector<T>lazytmp(n * 2 - 1, ZERO); //遅延評価配列も同じ数準備
        lazy = lazytmp;
        
    }
    
    
    // 区間[a,b)を値xで更新、最大最小-> 遅延評価。和, XOR, その他-> 通常
    void update(int a, int b, T x) {
        
        if(mode == MIN_MODE || mode == MAX_MODE)
        {
            updateLazy_forMinMax(a, b, x, 0, 0, n);
        }
        else if(mode == SUM_MODE || mode == XOR_MODE) {
            updateNolazy_forSum(a, b, x);
        }
        else {
            updateNolazy_forSum(a, b, x);
        }
    }
    // dat[a]を値xで更新
    void update(int a, T x) {
        update(a,a+1,x);
    }
    
    //区間[a,b)の値を取得するクエリ
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); };
    
    //全区間の値を取得するクエリ
    T allquery() { return query_sub(0, n+1, 0, 0, n); };
    
    void debug() {
        cout <<  "---dat---" << endl;
        for(int i = 0; i < dat.size(); i++) {
            if(dat[i] == ZERO) {
                cout << "- ";
            }
            else {
                cout << dat[i] << " ";
            }
        }
        
        cout <<  endl;
        
        cout <<  "---lazy---" << endl;
        for(int i = 0; i < lazy.size(); i++) {
            if(lazy[i] == ZERO) {
                cout << "- ";
            }
            else {
                cout << lazy[i] << " ";
            }
        }
        cout <<  endl;
    }
    
    //lazy[k]に登録してあった値を、１階層下の子要素に伝播させて、自身の値も変更
    void eval(int k) {
        if(lazy[k] == ZERO) return ;
        if(k < n -1) //kは末端ノード（葉）ではない
        {
            lazy[2 * k + 1] = lazy[k];
            lazy[2 * k + 2] = lazy[k];
        }
        dat[k] = lazy[k];
        lazy[k] = ZERO;
    }
    
private:
    void updateLazy_forMinMax(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if(a <= l && r <= b ) {      // 区間にすっぽり収まる際にはlazyを更新
            lazy[k] = x ;
            eval(k);
        }  else if( a < r && l < b) { // 一部の区間が収まる場合
            updateLazy_forMinMax(a, b, x, 2 * k + 1, l          , (r + l)/ 2 );
            updateLazy_forMinMax(a, b, x, 2 * k + 2, (r + l) / 2, r );
            dat[k] = choice(dat[k * 2 + 1], dat[k * 2 + 2] );
            
        }
    }
    
    //その時点で値を更新する
    void updateNolazy_forSum(int i, T x) { // i: 更新したい数列の位置（葉の位置）　x: 更新する値
        i += n - 1;                  // i番目の要素は i + n - 1の位置に格納
        dat[i] = x;
        while(i > 0) { //親をたどって値を更新していく
            i = (i - 1) / 2;
            dat[i] = choice(dat[i * 2 + 1], dat[i * 2 + 2] );
        }
    }
    
    //その時点で値を更新する
    void updateNolazy_forSum(int a, int b, T x) { //区間[a,b)を値xで更新
        for(int i = a; i < b; i++) {
            updateNolazy_forSum(i,x);
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
        
        return choice(lv,rv);
    }
    
    
    void setMode(int mode_) {
        mode = mode_;
        if(mode == MIN_MODE) {
            ZERO = P_INF;
        }
        else if (mode == MAX_MODE) {
            ZERO =  M_INF;
        }
        else if (mode == SUM_MODE) {
            ZERO =  0;
        }
        else if (mode == XOR_MODE) {
            ZERO =  0;
        }
    }
    
    T choice(T a, T b) {
        return
            mode == MIN_MODE ? min(a, b) :
            mode == MAX_MODE ? max(a, b) :
            mode == SUM_MODE ? a + b     :
            mode == XOR_MODE ? a ^ b     : ZERO;
    }
    

};


int main(){
    SegTree<int> segTreeMax(10, MAX_MODE);
    
    segTreeMax.update(2, 9, 1);    // 2,3,4,5,6,7,8 -> 1
    segTreeMax.update(1, 2, 4);    // 1 -> 4
    segTreeMax.update(6, 9, 2);    // 6,7,8 -> 2
    segTreeMax.update(9,10, 5);    // 9 ->5
    
    cout << "segTreeMax.query(6,7) : " << segTreeMax.query(6, 7) << endl;
    
    for(int i = 0;i <= 4; i ++) {
        cout << "segTreeMax.query(" << i << "," << 10 - i << ") : " << segTreeMax.query(i, 10-i) << endl;
    }
    
    
    SegTree<int> segTreeMin(10, MIN_MODE);
    
    segTreeMin.update(2, 9, 5);    // 2,3,4,5,6,7,8 -> 5
    segTreeMin.update(1, 2, 2);    // 1 -> 2
    segTreeMin.update(6, 9, 4);    // 6,7,8 -> 4
    segTreeMin.update(9,10, 1);    // 9 ->1
    
    cout << "segTreeMin.query(6,7) : " << segTreeMin.query(6, 7) << endl;
    
    for(int i = 0;i <= 4; i ++) {
        cout << "segTreeMin.query(" << i << "," << 10 - i << ") : " << segTreeMin.query(i, 10-i) << endl;
    }
    
    
    SegTree<int> segTreeSum(10, SUM_MODE);
    
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

