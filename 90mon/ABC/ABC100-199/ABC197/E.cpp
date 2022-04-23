#include <bits/stdc++.h> 

using namespace std;

#define debug false

#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 


typedef long long ll;

#define INF 1 << 28
#define MINF -1*(1 << 28)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 100000 + 5
#endif

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}
void UNSOLVABLE() {
  cout << "UNSOLVABLE" << endl;
}


template<typename T>
struct SegTree {
    private :
#define MIN_MODE    0
#define MAX_MODE    1
#define SUM_MODE    2
    int mode =  MIN_MODE;  // 0:最小値, 1:最大値
    
    const T P_INF = numeric_limits<T>::max();
    const T M_INF = numeric_limits<T>::min();
    
    T INF;
    
    
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
        
        vector<T>dattmp (n * 2 - 1, INF); //セグメント木は、要素数 sz * 2 - 1の配列を準備
        dat = dattmp;
        vector<T>lazytmp(n * 2 - 1, INF); //遅延評価配列も同じ数準備
        lazy = lazytmp;
        
    }
    
    
    // 区間[a,b)を値xで更新、最大最小-> 遅延評価。和 -> 通常
    void update(int a, int b, T x) {
        
        if(mode == MIN_MODE || mode == MAX_MODE)
        {
            updateLazy_forMinMax(a, b, x, 0, 0, n);
        }
        else if(mode == SUM_MODE) {
            updateNolazy_forSum(a, b, x);
        }
    }
    
    //区間[a,b)の値を取得するクエリ
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); };
    
    void debug() {
        cout <<  "---dat---" << endl;
        for(int i = 0; i < dat.size(); i++) {
            if(dat[i] == INF) {
                cout << "- ";
            }
            else {
                cout << dat[i] << " ";
            }
        }
        
        cout <<  endl;
        
        cout <<  "---lazy---" << endl;
        for(int i = 0; i < lazy.size(); i++) {
            if(lazy[i] == INF) {
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
        if(lazy[k] == INF) return ;
        if(k < n -1) //kは末端ノード（葉）ではない
        {
            lazy[2 * k + 1] = lazy[k];
            lazy[2 * k + 2] = lazy[k];
        }
        dat[k] = lazy[k];
        lazy[k] = INF;
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
            return INF;    //区間外
        if(a <= l && r <= b )
            return dat[k]; // 区間にすっぽり収まる
        
        //一部重なる
        int lv = query_sub(a, b, 2 * k + 1, l          , (r + l)/ 2 );
        int rv = query_sub(a, b, 2 * k + 2, (r + l) / 2, r );
        
        return choice(lv,rv);
    }
    
    
    void setMode(int mode_) {
        mode = mode_;
        if(mode == MIN_MODE) {
            INF = P_INF;
        }
        else if (mode == MAX_MODE) {
            INF =  M_INF;
        }
        else if (mode == SUM_MODE) {
            INF =  0;
        }
    }
    
    T choice(T a, T b) {
        return
            mode == MIN_MODE ? min(a, b) :
            mode == MAX_MODE ? max(a, b) :
            mode == SUM_MODE ? a + b      : INF;
    }
    

};


void solve(){
    int N;
    cin >> N;

    SegTree<pair<int,int>> seg(N,MAX_MODE);

    map<int,int> mp;
    int mpmp[N];

    rep(i,N-1) {
        int x,c;
        cin >> x >> c;
        mp[x] = c;
    }

    int i = 0;
    for(auto kv: mp) {
        mpmp[i] = kv.first;
        seg.update(i,i+1,{kv.second, i});
    }

    int ans = 0;
    int l =0, r=N;
    while(l < r) {
        pair<int,int> value = seg.query(0,N);
        l = value.second + 1;
        ans += mpmp[value.second];
    }


}


int main(){

#if debug == true
    while(true){
        cout << "---debugMode---" << endl;
#endif
        solve();
        cout << endl;
#if debug == true
    }
#endif

    return 0;
}

