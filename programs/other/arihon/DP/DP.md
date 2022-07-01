
# 2-3.DP <a id = "top">
+ [ナップサック問題系](#napsac)
    + [ナップザック問題(重さに関するDP)](#napsac1)
    + [ナップサック問題(価値に関するDP)](#napsac2)
    + [個数制限なしナップザック問題](#nolimit_napsac)
+ [最大共通部分文字列](#lcs)
+ [個数制限付き部分和](#sum)
+ [分割法](#devide)
+ [重複組合せ分割法](#devidemulti)

## ナップサック問題系 <a id="napsac">
### ナップサック問題(重さに関するDP) <a id="napsac1">

**問題定義**

    N: 品物の数                         1 <= N <= 100
    W: ナップサックに詰められる最大の重さ   1 <= W <= 10^5
    v[i]: i番目の品物の価値              1 <= v[i] <= 100
    w[i]: i番目の品物の重さ              1 <= w[i] <= 100

**DPの意味**

    dp[i][j]: i番目以降の品物に関して、重さの総和がj以下の場合の最大の価値
>注意:このdpだとO(NW)の計算量とdpの大きさが必要。したがって、Wが10^9と大きい場合には使用できない。その場合は[ナップサック問題（価値に関するDP）](#napsac2)の手法を使用する

**DPの計算方法**

    j < w[i]の場合 
        dp[i][j] = dp[i+1][j]
    それ以外
        dp[i][j] = max(dp[i+1][j], dp[i+1][j - w[i]] +v[i] )
    
**初期値**

    dp[N][0]=0

**ロジック**

    for(int i = N-1; i=>0; i--) {
        for(int j =0; j <= W; j++) {
            if(j < w[i])
                dp[i][j] = dp[i+1][j];
            else
                dp[i][j] = max(dp[i+1][j], dp[i+1][j - w[i]] +v[i] )
        }
    }

**答え**

    dp[1][W]

[top](#top)

### ナップサック問題(価値に関するDP) <a id="napsac2">

**問題定義**

    N: 品物の数                         1 <= N <= 100
    W: ナップサックに詰められる最大の重さ   1 <= W <= 10^9
    v[i]: i番目の品物の価値              1 <= v[i] <= 100
    w[i]: i番目の品物の重さ              1 <= w[i] <= 10^7

**DPの意味**

    dp[i][j]: i番目までの品物に関して、価値の総和がjとなる場合の最小の重さの総和
>注意:このdpだとO(N *sum(v[i]) )の計算量。したがって、各々のvが大きい場合には使用できない。その場合は[ナップサック問題(重さに関するDP) ](#napsac1)の手法を使用する

**DPの計算方法**

    j < v[i]  の場合
        dp[i+1][j] = dp[i][j]
    それ以外 
        dp[i+1][j] = min(dp[i][j],dp[i][j-v[i]] + w[i])

    
**初期値**

    dp[0][0]=0
    dp[1][j]=INF（選べないものはINFで埋めてしまう）

**ロジック**

    for(int i = 0; i<=N; i++) {
        for(int j =0; j <= v.size() * N; j++) {
            if ( j < v[i])
                dp[i+1][j] = dp[i][j];
            else
                dp[i+1][j] = min(dp[i][j],dp[i][j-v[i]] + w[i])
        }
    }

**答え**

    dp[n][i]について、i=0...100*100のうち、d[n][i] <= W となる最大値

[top](#top)


### 個数制限なしナップサック問題 <a id="nolimit_napsac">

**問題定義**

    N: 品物の数
    W: ナップサックに詰められる最大の重さ
    v[i]: i番目の品物の価値
    w[i]: i番目の品物の重さ

**DPの意味**

    dp[i][j]: i番目までの品物に関して、重さの総和がj以下の場合の最大の価値

**DPの計算方法（素朴）**

    if(j < w[i]) dp[i+1][j] = dp[i][j];
    else
    for k >= 0 
        dp[i+1][j] = max(dp[i][j - k * w[i]] + k * v[i])
    
**DPの計算方法（洗練）**

素朴法で、k >= 1のケースの場合にdp[i+1][j-w[i]]にで表せる式にする

    for k >= 0 
    dp[i+1][j] 
      = max(dp[i][j - k * w[i]] + k * v[i])
      = max(dp[i][j], max(dp[i][j-(k+1)*w[i]]+(k+1)*v[i]))
      = max(dp[i][j], max(dp[i][(j-w[i])-k*w[i]]+k*v[i]+v[i])
      = max(dp[i][j], dp[i][j-w[i]]+v[i])
    
**初期値**

    dp[0][0]=0

**ロジック**

    for(int i = 0; i<=N; i++) {
        for(int j =0; j <= W; j++) {        
            if(j < w[i])
                dp[i][j] = dp[i+1][j];
            else
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i])  
        }
    }

**答え**

    dp[1][W]

[top](#top)

## 最大共通部分文字列 <a id="lcs">

**問題定義**

    S = s_1...s_n: 文字列S（長さn)
    T = t_1...t_m: 文字列T（長さm)

**DPの意味**

    dp[i][j]: Sの先頭i文字目s_1...s_iとTの先頭j文字目t_1...t_jのlcs

**DPの計算方法**

    s_i+1 == t_j+1 の場合
        dp[i+1][j+1] = dp[i][j] + 1
    それ以外
        dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1] )
    
**初期値**

    dp[0][0]=0

**ロジック**

    for(int i = 0; i<= n; i++) {
        for(int j =0; j <= m; j++) {
            if(s[i+1] == t[j+1])
                dp[i+1][j+1] = dp[i][j] + 1;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1] )
        }
    }

**答え**

    dp[n][m]

[top](#top)

## 個数制限付き部分和 <a id="sum">

**問題定義**

    a_1...a_n が各々m_1...m_nある
    いくつか選び、その総和をKにできるか判定

**DPの意味（素朴）**

    bool dp[i][j]: i番目の値までで総和jを作れるか否か

**DPの計算方法（素朴）**

    dp[i+1][j] = dp[i][j] || dp[i][j - a_i] ||..|| dp[i][j - m_i*a_i]
> この方法では、O(K*sum(m[i]))の計算量が必要なため不十分。一般にboolのDPを計算する際にはもっと多くの情報が得られることが多い。


**DPの計算方法（改善）**

    dp[i+1][j] = dp[i][j] || dp[i][j - a_i] ||..|| dp[i][j - m_i*a_i]
> この方法では、O(K*sum(m[i]))の計算量が必要なため不十分

**DPの意味（改善）**

    int dp[i][j]: i番目の値までで総和jを作った時のa_iの残数の最大値
                　ただし、総和jが作成できない場合には-1）

**DPの計算方法（改善）**

    d[i][j] >= 0（i番目までで総和を作れる場合）
        d[i+1][j] = m_i
    j < a_j または d[i+1][j- a_j] < 0 の場合（）
        d[i+1][j] = -1
    上記以外（残数を一個づつ減らして伝播させる）
        d[i+1][j] = d[i+1][j - a_i] -1
        

> この方法では、O(nK)の計算量で行える。また、0以上の場合と素朴法のtrueが同値になる

**初期値**

    dp[0][0]= 0
    ほか dp[i][j]=-1

**ロジック**

配列を再利用して

    for(int i = 1; i<= n; i++) {
        for(int j =0; j <= K; j++) {
            if(d[j] >= 0){
                d[j] = a[i]
            } 
            else if(j < a[i] || d[i+1][j- a[j]] < 0)
            {
                d[j] = -1
            }
            else
            {
                d[j] = d[j - a[i]] -1
            }
        }
    }

**答え**

    dp[n][K]>= 0か否か

[top](#top)






## 最長増加部分列 <a id="lis">


**問題定義**

   a_0,...,a_n-1という数列において、最長の増加部分列（i<jに対してa[i] <a[j]）の長さを求めよ

**DPの意味**

    dp[i]: 最後がa_iであるにて最長の増加要素数 

**DPの計算方法**

    dp[i] = 1 + max(d[j] where 0<= j <= i-1 and a[j] < a[i]) 
    
**初期値**

    dp[i]=1とする（少なくともa_iのみからなる列が各々のmax候補なので）

**ロジック**

    int ans = 0;
    for(int i = 0; i< n; i++) {
        dp[i] = 1;
        for(int j =0; j <= i - 1; j++) {
            if(a[j] < a[i])
                dp[i] = max(dp[i], d[j] + 1);
        }
        max(ans, dp[i])
    }

**答え**

    ans

#### 別解（より高速な方法）
以下のロジックは$O(nlogn)$の計算量（前述の方法は$O(n^2)$)

**DPの意味**

    dp[i]: i個の要素からなる増加部分列の末尾の値の最小値

**DPの計算方法**

    dp[i] = 初期処理で+∞を全要素に設定
            a_iについて、k <= a_i となる最小のkを二分探索で探す(lowerbound)
            dp[&k] = a_iとする

**ロジック**

``` cpp
int ans = 0;
fill(dp,dp+n,INF)
for(int i = 0; i< n; i++) {
    *lowerbound(dp.begin(),dp.end(),a[i]) = a[i];
}
```

[top](#top)


## 分割法 <a id="devide">

**問題定義**

   n個の異なる要素について、m個以下に分割する総数をMで割った値

**DPの意味**

    dp[i][j]: 数値jのi分割の総数
>数値jのi分割とは、$\Sigma_{k=1}^i a_k$となる数列$(a_1,...,a_j)$のこと

**DPの計算方法**

数値jのi分割$(a_1,...,a_j)$は以下の２通りに分けられる
+ $a_k=0$となるものが存在      -> これは数値jのi-1分割 d[i-1][j]通り
+ $a_k=0$となるものが存在しない -> 全ての要素から1を引くことで、数値j-iのi分割 d[j-i][i]

つまり、計算方法は以下の通り
 

    dp[i][j] = d[i][j-i] + d[i-1][j] 

    
**初期値**

    dp[0][0]=1　//これが難しい

**ロジック**

``` cpp
for(int i = 1; i< m+1; i++) {
    for(int j = 0; j< n+1; j++) {
        if(j-i > 0)
        {
            dp[i][j] = dp[i-1][j] + d[j-i][i]
        }
        else {
            dp[i][j] = dp[i-1][j]
        }
    }
}
```

## 重複組合せ分割法 <a id="devidemulti">

**問題定義**
    
    n種類の品物がa_i個づつある、同じ品物は区別不可能、この中からm個選ぶ組合せの総数をMで割った値を求めよ

**DPの意味**

    dp[i][j]: i番目までの品物をj個選ぶ場合の総数
    
**DPの計算方法**

$dp[i][j]$ <br>
　$= \Sigma_{k=0}^{min(j,a_{i-1})}dp[i-1][j-k]$ <br>

if $j < a_{i-1}$ then <br>
$dp[i][j]$ <br>
　$=d[i-1][j] + \Sigma_{k=1}^{j}dp[i-1][j-k]$<br>
　$=d[i-1][j] + \Sigma_{k=0}^{j-1}dp[i-1][(j-1)-k]$<br>
　$=d[i-1][j] + \Sigma_{k=0}^{min(j-1,a_{i-1}}dp[i-1][(j-1)-k]$<br>
　$=d[i-1][j] + d[i][j-1]$<br><br>
if $j >= a_{i-1}$ then <br>
$dp[i][j]$ <br>
　$=d[i-1][j] + \Sigma_{k=1}^{a_{i-1}}dp[i-1][j-k]$<br>
　$=d[i-1][j] + \Sigma_{k=0}^{a_{i-1}-1}dp[i-1][(j-1)-k]$<br>
　$=d[i-1][j] + \Sigma_{k=0}^{a_{i-1}}dp[i-1][(j-1)-k] - dp[i-1][(j-1) - a_{i-1}]$<br>
　$=d[i-1][j] + \Sigma_{k=0}^{min(j-1,a_{i-1})}dp[i-1][(j-1)-k] - dp[i-1][(j-1) - a_{i-1}]$<br>
　$=d[i-1][j] + d[i][j-1] - dp[i-1][(j-1) - a_{i-1}]$<br>

>これは累積和の考え方

    
**初期値**

    dp[i][0]=1 //一つも選ばない

**ロジック**

``` cpp
for(int i = 1; i< n; i++) {
    for(int j = 1; j< m+1; j++) {
        if(j - 1 -a[i-1] >= 0)
        {
            dp[i][j] = (dp[i-1][j] + d[i][j-1] + dp[i−1][(j−1)−a[i-1]] + M )% M
        }
        else {
            dp[i][j] = dp[i-1][j] + d[i][j-1]
        }
    }
}
```

[top](#top)



