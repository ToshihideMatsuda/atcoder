
//N以下の数について、素因数の数をcに登録
int c[10000000+9];
void elatsWithFactor(int N){
	for(int i= 2; i<N+1;i++){
		c[i]=0;
	}
	
	for(int i= 2; i<N+1;i++){
		if(c[i]==0){
			for(int j=i;j<N+1;j +=i){
				c[j] +=1;
			}
		}
	}
}