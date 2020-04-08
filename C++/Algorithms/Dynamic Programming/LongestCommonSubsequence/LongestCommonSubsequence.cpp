#include <iostream>
#include <string.h>
using namespace std;

int longestCommonSubsequence(char X[],char Y[],int m, int n){
	
	int i,j;
	int L[m + 1][n + 1];
	char C[m + 1][n + 1];
	
	for(i = 0; i <= m; i++){ 
        for(j = 0; j <= n; j++){ 
            if(i == 0 || j == 0){
            	L[i][j] = 0;
			}
			else if(X[i-1]  == Y[j-1]){
				L[i][j] = L[i-1][j-1] + 1;
				C[i][j] = 'D'; //Representing Diagonally 45Degree to towards the left.
			}
			else if(L[i-1][j] >= L[i][j-1]){
				L[i][j] = L[i-1][j];
				C[i][j] = 'U';	
			}
			else{
				L[i][j] = L[i][j-1];
				C[i][j] = 'L';	
			}
		}
	}
	
	i = m;
	j = n;
	int q = L[m][n]-1;
	char sub[L[m][n]];
	
	
	while( i!=0 && j!=0){
		if(C[i][j] == 'U'){
			i = i-1;
		}
		else if(C[i][j] == 'L'){
			j = j-1;
		}
		else{
			sub[q--] = X[i]; //Or Y[i]
			i = i-1;
			j = j-1;
		}
	}
	cout<<"The Subsequence is : "<<sub<<endl;
	//Display table value for understanding along with the direction
	for(int i=0 ; i<=m ; i++){
		for(int j=0 ;j<=n ;j++){
			if(i==0 || j==0){
				cout<<L[i][j]<<" \t";
			}
			else{
				cout<<L[i][j]<<C[i][j]<<"\t";
			}
		}
		cout<<endl;
	}
		
}

int main(){
	int m, n;
	char X[10],Y[10];
	cout<<"Enter the String X : ";
	cin>>X;
	cout<<"Enter the String Y : ";
	cin>>Y;
	m = strlen(X);
	n = strlen(Y);
	longestCommonSubsequence(X, Y, m, n);
}
