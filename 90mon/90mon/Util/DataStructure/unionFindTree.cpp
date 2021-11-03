#include <iostream>
#include <unordered_map>
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


int conv(int i, int j) { return i + 2000 * j; }
 
bool red[2001][2001];
 
int main(){
    int h,w,q;
    std::cin >> h >> w >> q;
 
    UnionFindTree<int> utree;
	for (int i = 1; i < 2000*2000+1; i ++) {
	utree.insert(i);
	}
	
	
    string s = "";
    for (int i = 0; i < q; i ++) {
        int t;
        cin >> t;
        if(t==1) {
            int ra, ca;
            cin >> ra >> ca;
 
            red[ra][ca] = true;
 
            if(red[ra - 1][ca] == true) utree.unionTree(conv(ra, ca), conv(ra-1, ca));
            if(red[ra + 1][ca] == true) utree.unionTree(conv(ra, ca), conv(ra+1, ca));
            if(red[ra][ca - 1] == true) utree.unionTree(conv(ra, ca), conv(ra, ca-1));
            if(red[ra][ca + 1] == true) utree.unionTree(conv(ra, ca), conv(ra, ca+1));
        }
        else if(t==2) {
            int ra, ca, rb, cb;
            cin >> ra >> ca  >> rb >> cb;
            bool value = utree.same( conv(ra, ca), conv(rb,  cb)) && red[ra][ca] && red[rb][cb];
            
            if(value) {
                s += "Yes\n";
            } else {
                s += "No\n";
            }
        }
    }
 
    std::cout << s;
 
    return 0;
}