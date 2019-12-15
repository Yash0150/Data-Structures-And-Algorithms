#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int result(int A[],int B[], int n, int m, int k){
	if(n==0 || m==0){
		return 0;
	}
	if(dp[n][m]!=-1){
		return dp[n][m];
	}
	if(A[n-1]==B[m-1]){
		dp[n][m]=1 + result(A,B,n-1,m-1,k);
		return dp[n][m];
	}
	if(k!=0){
		dp[n][m]=max(result(A,B,n-1,m,k), max(result(A,B,n,m-1,k),1+result(A,B,n-1,m-1,k-1)));
		return dp[n][m];
	}
	else{
		dp[n][m]=max(result(A,B,n-1,m,k),result(A,B,n,m-1,k));
		return dp[n][m];
	}
}

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int A[n],B[m];
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	for(int i=0; i<m; i++){
		cin>>B[i];
	}
	memset(dp,-1,sizeof(dp));
	int ans= result(A,B,n,m,k);
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}