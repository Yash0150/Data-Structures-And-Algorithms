#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans=0;

/*ll path(ll dp[1001][1001],ll i,ll j,ll m,ll n,ll p){
	if(i==m && j==n){
		ans+=1;
		return 0;
	}
	if(i>m || i<1 || j<1 || j>n){
		return 0;
	}
	if(j==n+1){
		path(dp,i+1,1,m,n,p);
	}
	if(dp[i][j]==-1){
		return 0;
	}
	path(dp,i+1,j,m,n,p);
	path(dp,i,j+1,m,n,p);
	return 0;
}*/

ll A[1001][1001]={0};

ll path(ll dp[1001][1001],ll m,ll n){
	if(dp[0][0]==-1){
        return 0; 
    }
    if(dp[m][n]==-1){
    	return 0;
    }
	//dp[1][1]=1;
	for(int i=1; i<=n; i++){
		if(dp[1][i]!=-1){
			A[1][i]=1;
		}
		else{
			break;
		}
	}
	for(int i=1; i<=m; i++){
		if(dp[i][1]!=-1){
			A[i][1]=1;
		}
		else{
			break;
		}
	}
	for(int i=2; i<=m; i++){
		for(int j=2; j<=n; j++){
			if(dp[i][j]!=-1){
				A[i][j]=A[i-1][j]+A[i][j-1];
			}
		}
	}
}

int main(){
	ll n,m,p;
	cin>>m>>n>>p;
	ll dp[1001][1001]={0};
	for(ll i=0; i<p; i++){
		ll a,b;
		cin>>a>>b;
		dp[a][b]=-1;
		for(ll i=b; i<=n; i++){
			dp[a][i]==-1;
		}
	}
	path(dp,m,n);
	for(ll i=1; i<=m;i++){
		for(ll j=1;j<=n; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<A[m][n]%1000000007;
}