#include <iostream>
#include <limits>
#include <map>
#include <vector>
using namespace std;


struct UnionFindTree {
    int treemax;
    vector<int> tree;  // T -> TのUnionTreeの実態
    vector<int> dep; // unionfind木の深さ
    UnionFindTree(int _treemax) {
        treemax = _treemax;
        for (int i = 0; i < treemax + 1; i ++){
            tree.push_back(i);
            dep.push_back(1);
        }
    }

    // rootを辿って同じものかを判定
    bool same (int e1, int e2)  {
        int x = root(e1);
        int y = root(e2);

        if(x== y) return true;
        return false;
    }

    // rootを辿って、深さに応じてくっつける
    void unionTree(int e1, int e2) {
        int x = root(e1);
        int y = root(e2);

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
    int root(int e) {
        int r = tree[e];
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

    UnionFindTree utree( 2000 * 2000 + 1);

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


//
//  main.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/12.
//
/*
#include <iostream>
using namespace std;

bool c[2001][2001];
int g[2001][2001];
int r[2001][2001];

void debugout(int h, int w);
bool same (int ra, int ca, int rb, int cb);
void uniong(int ra, int ca, int rb, int cb);
int conv(int i, int j);
int getI(int g) ;
int getJ(int g) ;
int root(int i, int j) ;


int main(){
    int h,w,q;
    std::cin >> h >> w >>q;

    //初期化
    for (int i = 1; i < h+1; i ++){
        for (int j = 1; j < w+1; j ++){
            g[i][j] = conv(i,j);
            r[i][j] = 1;
        }
    }
    string s = "";
    for (int i = 0; i < q; i ++) {
        int t;
        cin >> t;
        if(t==1) {
            int ra, ca;
            cin >> ra >> ca;

            c[ra][ca] = true;

            if(c[ra - 1][ca] == true) {
                uniong(ra, ca, ra -1, ca);
            }
            if(c[ra + 1][ca] == true) {
                uniong(ra, ca, ra +1, ca);
            }
            if(c[ra][ca -1] == true) {
                uniong(ra, ca, ra, ca -1);
            }
            if(c[ra][ca +1] == true) {
                uniong(ra, ca, ra, ca +1);
            }
        }
        else if(t==2) {
            int ra, ca, rb, cb;
            cin >> ra >> ca  >> rb >> cb;
            bool value = same( ra,  ca,  rb,  cb) && c[ra][ca] && c[rb][cb];
            
            if(value) {
                s += "Yes\n";
            } else {
                s += "No\n";
            }
            //debugout(h,w);
        }
    }

    std::cout << s;

    return 0;
}

void debugout(int h, int w) {
    cout << "---start---\n";
    for (int i = 1; i < h + 1; i ++){
        for (int j = 1; j < w + 1; j ++){
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "---end---\n";
}

bool same (int ra, int ca, int rb, int cb)  {
    int x = root(ra, ca);
    int y = root(rb, cb);

    if(x== y) return true;
    return false;

}
void uniong(int ra, int ca, int rb, int cb) {
    int x = root(ra, ca);
    int y = root(rb, cb);

    if(x== y) return;

    if( r[getI(x)][getJ(x)] >= r[getI(y)][getJ(y)] ) {
        g[getI(y)][getJ(y)] = x;
        r[getI(y)][getJ(y)] ++;
    } else {
        g[getI(x)][getJ(x)] = y;
        r[getI(x)][getJ(x)] ++;
    }
}


int root(int i, int j) {
    int current = g[i][j];
    if(current == conv(i,j)) {
        return current;
    }
    else {
        g[i][j] = root(getI(current), getJ(current));
        return g[i][j];
    }
}

int conv(int i, int j) { return i + 10000 * j; }
int getI(int g)        { return g % 10000; }
int getJ(int g)        { return g / 10000; }
*/
