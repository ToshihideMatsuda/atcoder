#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;


void clearMatrix(bool area[6][6]){
    for(int i =0 ;i < 6; i++) {
        for(int j=0 ;j< 6;j ++) {
            area[i][j] = false;
        }
    }
} 

int main(){
	
	vector<pair<int,int>> mura;
	for(int i=1;i<5;i++){
		for(int j=1;j<5;j++){
            int a;
			cin >> a;
			if(a == 1) {
                mura.push_back({i,j});
            }
		}
	}
	    
	int cnt=0;
	for(int hei=0x0000;hei <=0xffff; hei++){
    	bool area[6][6]; clearMatrix(area);
        int v = hei ;
        int c = 1;
        //初期化
        while(v > 0) {
            area[c][1] = (v & 1 ) > 0;
            area[c][2] = (v & 2 ) > 0;
            area[c][3] = (v & 4 ) > 0 ;
            area[c][4] = (v & 8 ) >0 ;
            c++;
            v >>= 4; 
        }

        //全ての村がarea内かを調べる
        bool ok = true;
		for(auto m :mura) 
        {
            if(!area[m.first][m.second]){
                ok = false;
                break;
            }
        }
		
        if(ok == false) continue;

        // 塀の中が連結か調べる
        bool check[6][6]; clearMatrix(check);
        {
		queue<pair<int,int>> Q;
		Q.push(mura[0]);
		while(Q.size() >0){
			auto v =Q.front();Q.pop();
			if(check[v.first][v.second]) continue;
			
			if(area[v.first][v.second]){ //areaの中ならば

                Q.push({v.first,v.second +1});
                Q.push({v.first,v.second -1});
                Q.push({v.first-1,v.second});
                Q.push({v.first+1,v.second});

				check[v.first][v.second] = true; //訪れた場所を||で記録
			}
		}
		
        //塀の中が連結かを調べる
	    for(int i=0;i<6;i++){
    		for(int j=0;j<6;j++){
                if(area[i][j] && !check[i][j]){
                    ok = false;
                    break;
                }
		    }
	    }
        if(ok == false) continue;
        }

        // 塀の外が連結か調べる
        clearMatrix(check);
        {
		queue<pair<int,int>> Q;
		Q.push({0,0});
		while(Q.size() >0){
			auto v =Q.front();Q.pop();
			if(check[v.first][v.second]) continue;
			
			if(area[v.first][v.second]==false){ //areaの中ならば

                if(v.second +1 <= 6) Q.push({v.first    ,v.second +1});
                if(v.second -1 >= 0) Q.push({v.first    ,v.second -1});
                if(v.first  +1 <= 6) Q.push({v.first+1  ,v.second});
                if(v.first  -1 >= 0) Q.push({v.first-1  ,v.second});

				check[v.first][v.second] = true; //訪れた場所を||で記録
			}
		}
		
        //塀の中が連結かを調べる
	    for(int i=0;i<6;i++){
    		for(int j=0;j<6;j++){
                if(!area[i][j] && !check[i][j]){
                    ok = false;
                    break;
                }
		    }
	    }
        if(ok == false) continue;
        }


		if(ok) {
            cnt++;
        }
	}
	
	cout << cnt << endl;
    
    
    return 0;
}
