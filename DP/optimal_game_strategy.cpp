#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[31][31];
int game(int A[31],int s,int e,int n){
	if(s>=e){
		return 0;
	}
	if(dp[s][e]!=-1){
		return dp[s][e];
	}
	int x=A[s]+min(game(A,s+2,e,n),game(A,s+1,e-1,n));
	int y=A[e]+min(game(A,s+1,e-1,n),game(A,s,e-2,n));
	dp[s][e]=max(x,y);
	return dp[s][e];
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	int A[31];
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	int ans=game(A,0,n-1,n);
	/*for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<ans;
}