#include <iostream>
#include <vector>
using namespace std;

/* 区間 [left,right)に対する マージソート */
void mergeSort(vector<int>&a,int left,int right);
/* 区間 [left,right)に対する クイックソート */
void quickSort(vector<int>&a,int left,int right);
/* 挿入ソート */
void insertSort(vector<int>&a);
/* ヒープソート */
//i番目の頂点を根とする部分木について、ヒープ条件を満たすようにする
//aのうち0番目からN-1番目までの部分a[0:N]についてのみカンガル
void heapSort(vector<int>&a);

void printl(vector<int>&a){
	for(auto i :a)cout << i <<" ";
	cout << endl;
}

int main (){
	vector<int> a={9,7,84,65,32,1332,359,2,74,990,1,43,683};
	
	printl(a);
	
	/*
    cout << "merge sort!" << endl;
	mergeSort(a, 0, a.size());
	*/

    /*
    cout << "insert sort!" << endl;
	insertSort(a);
    */

    cout << "quick sort!" << endl;
	quickSort(a,0,a.size());

	printl(a);
}

void insertSort(vector<int>&a){
    for(int i = 0; i < a.size(); i ++) { //i-1番目までソート済み
        
        int v = a[i];
        int j = 0;
        for(; j < i ; j ++) {
            if(a[j] > v) break;
        }

        for(int k = i; k > j; k --) {
            a[k] = a[k-1];
        }
        a[j] = v;        
    }
}

// 区間 [left,right)に対する マージソート
void mergeSort(vector<int>&a,int left,int right){
	if(right-left==1) return;//leaf
	
	int mid=(left+right)/2;
	mergeSort(a,left,mid);
	mergeSort(a,mid,right);
	//each [left,mid),[mid,right) is sorted.
	//join them
	
	vector<int> bl,br;
	for(int i=left;i<mid;i++)bl.push_back(a[i]);
	for(int i=mid;i<right;i++)br.push_back(a[i]);
	
	int i=left,il=0,ir=0;
	
	while(i<right){
		
		if(il==bl.size()){
			a[i]=br[ir++];
		}
		else if(ir==br.size()){
			a[i]=bl[il++];
		}
		else{
			if(bl[il]<br[ir]){
				a[i]=bl[il++];
			}else{
				a[i]=br[ir++];
			}
		}
		i++;
	}
	
}

// 区間 [left,right)に対する クイックソート 
void quickSort(vector<int>&a,int left,int right){
	if(right-left <= 1) return;//leaf
	
    //簡単のため、pivotを最も後ろから取得
    int pivot = a[right-1];
    
    int less_idx = left;
    
    for(int i = left; i < right -1; i++ ) {
        if(a[i] < pivot) { //ピボット以下のものは左に詰める
            swap(a[less_idx],a[i]);
            less_idx++;
        }
    }

    swap(a[less_idx],a[right-1]);

    quickSort(a,left, less_idx);
    quickSort(a,less_idx, right);
}


//[left, right)のソート
void quick2(vector<int> a, int left, int right) {
    //終了条件
    if(right - left <= 1) return;

    //末尾をpivotとする
    int pivot = a[right -1];

    //左からpivor以下を詰める
    int lessIndx = left;
    for(int i = left; i < right -1; i ++) {
        if(a[i] < pivot) {
            swap(a[lessIndx],a[i]);
            lessIndx++;
        }
    }

    if(a[right -1] < a[lessIndx])
    {
        swap(a[lessIndx], a[right - 1]);
    }

    quick2(a,left, lessIndx);
    quick2(a,lessIndx, right);

}