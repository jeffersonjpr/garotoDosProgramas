int det(int n,int ord,int m[][ord]){
	if (ord == 1) return n*m[1][1];
	for(int i = 0;i<ord;i++){
		for(int j =0;j<ord;j++){
			m[i][j] *=n;
		}
	}
	for(int i = 0;i< ord;i++){
		
	}

}
