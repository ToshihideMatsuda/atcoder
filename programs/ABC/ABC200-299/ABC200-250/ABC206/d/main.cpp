#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define fore(e,es) for(auto e:es)

struct UnionFindTreeWithSize {

    vector<int> tree;  // 実態
                       // 正数:子, 負数:親(値は子の数)、0:未初期化
    vector<int> dep;   // unionfind木の深さ

    UnionFindTreeWithSize(int n): tree(n,0), dep(n,0){}

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



int main(){
	int n;
	int sum =0;
	cin >> n;
	
	vector<int> A(n);
	UnionFindTreeWithSize utree(200005);
	
	rep(i,n) {
		cin >> A[i];
		utree.insert(A[i]);
	}
	
	rep(i,n/2) {
		if(utree.same(A[i],A[n-1-i])){	
			//ok
		}
		else{
			sum++;
			utree.unionTree(A[i],A[n-1-i]);
		}
	}
	
	cout<<sum<<endl;
	
	return 0;
}
