#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll tile(ll dp[100001],ll n,ll m){
	if(n<m){
		return 1;
	}
	if(n==m){
		return 2;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	dp[n]=tile(dp,n-m,m)+tile(dp,n-1,m);
	return dp[n];
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll dp[100001];
		memset(dp,-1,sizeof(dp));
		dp[0]=1;
		ll n,m;
		cin>>n>>m;
		ll ans=tile(dp,n,m);
		cout<<ans%1000000007;
		cout<<endl;
	}
}