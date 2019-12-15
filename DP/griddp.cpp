#include<bits/stdc++.h>
using namespace std;
#define ll long long
int B[101][101];

int grid(int A[101][101],int n){
	for(int i=1; i<n; i++){
		B[0][i]=B[0][i-1]+A[0][i];
	}
	for(int i=1; i<n; i++){
		B[i][0]=B[i-1][0]+A[i][0];
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<n;j++){
			B[i][j]=A[i][j]+ min(B[i-1][j],B[i][j-1]);
		}
	}
}
int main(){
	B[0][0]=0;
	int n;
	cin>>n;
	int A[101][101];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>A[i][j];
		}
	}
	grid(A,n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}	
	cout<<B[n-1][n-1];
}