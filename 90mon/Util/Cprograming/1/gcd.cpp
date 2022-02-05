#include <iostream>

using namespace std;

/* ユークリッドの互除法: aとbの最大公約数の計算 */
int gcd(int a, int b)          /* ユークリッドの互除法 */
{   
    if(b == 0) return a;     /* 計算結果を返す */
    else return gcd(b, a%b); /* 互除法の反復 */
                           
}

/* メインプログラム：最大公約数計算のためのデータの入出力 */
int main()
{
    int a0, a1;                    /* 変数の宣言 */
    cin >> a0 >> a1;
    cout << gcd(a0, a1) << endl;
    return 0;
}
