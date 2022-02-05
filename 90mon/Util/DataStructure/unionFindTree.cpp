#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

template<typename T>
struct UnionFindTree {

    unordered_map <T,T> tree;  // T -> TのUnionTreeの実態
    unordered_map <T,int>dep; // unionfind木の深さ

    UnionFindTree() {}

    void insert(T edge){
        tree[edge] = edge;
        dep[edge] = 1;
    }

    // rootを辿って同じものかを判定
    bool same (T e1, T e2)  {
        T x = root(e1);
        T y = root(e2);

        if(x== y) return true;
        return false;
    }

    // rootを辿って、深さに応じてくっつける
    void unionTree(T e1, T e2) {
        T x = root(e1);
        T y = root(e2);

        if(x== y) return;

        if(dep[x] >= dep[y] ) {
            tree[y] = x;
            dep[y] ++;
        } else {
            tree[x] = y;
            dep[x] ++;
        }
    }

    // treeの先を辿ってtreeにする
    T root(T e) {
        T r = tree[e];
        if(r == e) { return r;}
        else {
            tree[e] = root(r);
            return tree[e];
        }
    }

};


struct UnionFindTreeWithSize {

    vector<int> tree;  // 実態
                       // 正数:子, 負数:親(値は子の数)、0:未初期化
    vector<int> dep;   // unionfind木の深さ

    UnionFindTreeWithSize(int n): tree(n,0), dep(n,0){
	    for (int i = 0; i < n; i ++) {
	        insert(i);
	    }

    }

    void insert(int edge){
        tree[edge] = -1;
        dep[edge] = 1;
    }

    // rootを辿って同じものかを判定
    bool same (int e1, int e2)  {
        int x = root(e1);
        int y = root(e2);

        if(x == y) return true;
        return false;
    }

    // rootを辿って、深さに応じてくっつける
    void unionTree(int e1, int e2) {
        int x = root(e1);
        int y = root(e2);

        if(x == y) return;

        if(dep[x] >= dep[y] ) {
            tree[x] += tree[y]; //負数の要素をくっつける
            tree[y] = x;
            dep[y] ++;
        } else {
            tree[y] += tree[x]; //負数の要素をくっつける
            tree[x] = y;
            dep[x] ++;
        }
    }

    // treeの先を辿ってtreeにする
    int root(int e) {
        int r = tree[e];
        if(r < 0 ) { return e;} //負数が親
        else {
            tree[e] = root(r);
            return tree[e];
        }
    }

    int getSize(int e) {
        int r = root(e);
        return tree[r] * -1;
    }

};


int conv(int i, int j) { return i + 2000 * j; }
 
bool red[2001][2001];
 
int main(){
    UnionFindTreeWithSize utree(100);
	for (int i = 0; i < 100; i ++) {
	    utree.insert(i);
	}

    int zero = utree.getSize(0);
    utree.unionTree(0,1);
    utree.unionTree(1,2);
    utree.unionTree(2,3);
    int two = utree.getSize(2);
    utree.unionTree(4,1);
    utree.unionTree(8,9);
    utree.unionTree(10,9);
    two = utree.getSize(2);
    int ten = utree.getSize(10);
	
	
 
    return 0;
}