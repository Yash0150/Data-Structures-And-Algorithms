#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll best=0;

/*ll cost(string s,string o,ll m,ll n){
	if(m==0){
		return n;
	}
	if(n==0){
		return m;
	}
	if(s[m-1]==o[n-1]){
		return cost(s,o,m-1,n-1);
	}
	return 1+min(cost(s,o,m-1,n),min(cost(s,o,m-1,n-1),cost(s,o,m,n-1)));	
}*/
ll dp[101][101];
ll cost(string s,string o,ll m,ll n){
	
	if(m==0){
		return n;
	}
	if(n==0){
		return m;
	}
	if(dp[m][n]!=-1){
		return dp[m][n];
	}
	if(s[m-1]==o[n-1]){
		dp[m][n]=cost(s,o,m-1,n-1);
		return dp[m][n];
	}
	dp[m][n]= 1+min(cost(s,o,m-1,n),min(cost(s,o,m-1,n-1),cost(s,o,m,n-1)));
	return dp[m][n];
}

/*ll cost(string s,string o,ll m,ll n){
	for(int i=0; i<=n; i++){
		dp[0][i]=i;
	}
	for(int i=0; i<=m; i++){
		dp[i][0]=i;
	}
	for(int i=1; i<=m; i++){
		for(int j=1;j<=n; j++){
			if(s[i-1]==o[j-1]){
				dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
			}
			else{
				dp[i][j]= 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
			}
		}
	}

}*/

int main(){
	memset(dp,-1,sizeof(dp));
	string s="sunday",o="saturday";
	//cin>>s>>o;
	ll ans=cost(s,o,s.size(),o.size());
	cout<<ans;
	/*for(int i=0; i<=s.size(); i++){
		for(int j=0;j<=o.size(); j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
}