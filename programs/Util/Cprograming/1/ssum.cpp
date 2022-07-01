#include <iostream>
using namespace std;

#define N 100           /* 配列a[ ]の最大サイズの定義 */
enum yn {yes, no};      /* 列挙データ型の定義 */
/* 関数の宣言 */
enum yn ssum(int *a, int b, int *x, int n);
void next(int *x, int n);

main()  
/* メインプログラム：問題SUBSET-SUMの入出力 */
{
 int a[N], x[N], b;              /* 変数の宣言 */
 int n, j;
 FILE *file;

 file=fopen("ssumdata", "r");    /* 入力ファイルを開く */
 fscanf(file, "%d", &n);         /* ファイルから入力データnを読込む */
 if(n>N)                         /* nの大きさチェック */
   {printf("Illegal array size n = %d for N = %d\n", n, N); exit(1);}
 printf("n = %d\na = ", n);
 for(j=0; j<n; j++) fscanf(file, "%d", &a[j]); /* 入力データa[j]の読込み */
 for(j=0; j<n; j++) printf("%d ", a[j]);
 printf("\n");
 fscanf(file, "%d", &b);         /* 入力データbの読込み */
 printf("b = %d\n", b);
 if(ssum(a, b, x, n)==yes)       /* 関数ssumで問題を解き、結果を出力 */
   {
    printf("Yes\nx = ");         /* Yesの出力 */
    for(j=0; j<n; j++) printf("%d", x[j]);   /* 解の出力 */
    printf("\n");
   }
 else printf("No\n");            /* Noの出力 */
 return(0);
}

enum yn ssum(int *a, int b, int *x, int n) 
/* 列挙法によるSUBSET-SUMのアルゴリズム */
/* 入力データは配列a[ ]とb. 変数はn個. 解はx[ ]に置かれる. */
{
 int j, full, temp;              /* 変数の宣言 */

 for(j=0; j<n; j++) x[j]=0;      /* x[ ]の初期化 */
 while(1)                        /* 0-1ベクトルの列挙と条件のチェック */
   {
    temp=0;
    for(j=0; j<n; j++) temp=temp+x[j]*a[j];
    if(temp==b) return(yes);     /* 解を発見 */
    full=1; j=0;
    do {full=full*x[j]; j=j+1;} while(full==1 && j<=n-1);
    if(full==1) return(no);      /* 解なしを結論 */
    next(x, n);                  /* 次の2進数ベクトル */
   }
}

void next(int *x, int n) 
/* 0-1ベクトル（配列）x[0,...,n-1]を次の2進数に更新 */
{
 int j;

 j=n-1;
 do {x[j]=1-x[j]; j=j-1;} while(x[j+1]==0); 
 return;  
}