#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll best=0;
/*ll maxProfit(ll A[1001],ll s,ll e,ll yr, ll n){
	if(s>e){
		return 0;
	}                                                       //RECURSION
	ll x=yr*A[s] + maxProfit(A,s+1,e,yr+1,n);
	ll y=yr*A[e] + maxProfit(A,s,e-1,yr+1,n);
	best=max(x,y);
	return best;
}*/
ll dp[101][101];
/*int maxProfit(ll A[1001],ll s,ll e,ll yr, ll n){
	if(s>e){
		return 0;
	}
	if(dp[s][e]!=-1){
		return dp[s][e];
	}                                                       //TOP DOWN
	ll x=yr*A[s] + maxProfit(A,s+1,e,yr+1,n);
	ll y=yr*A[e] + maxProfit(A,s,e-1,yr+1,n);
	best=max(x,y);
	dp[s][e]=best;
	return best;
}*/

int maxProfit(ll A[1001],ll n){
	int yr=n;
	for(int i=0; i<n; i++){
		dp[i][i]=A[i]*yr;
	}
	yr--;
	for(int i=1; i<n; i++){
		int s=0;
		int e=n-i-1;
		while(s<=e){
			int endwindow=s+i;
			dp[s][endwindow]=max(A[s]*yr+dp[s+1][endwindow],A[endwindow]*yr+dp[s][endwindow-1]);
			s++;
		}
		yr--;
	}
}

int main(){
	ll n;
	//memset(dp,-1,sizeof(dp));
	cin>>n;
	ll A[101];
	for(ll i=0; i<n; i++){
		cin>>A[i];
	}
	maxProfit(A,n);
	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){
			cout<<dp[i][j]<<"	";
		}
		cout<<endl;
	}
	cout<<dp[0][n-1];
}