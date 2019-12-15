#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*/int dp[101];
ll fib(ll n){
	if(n==0){
		return 0;
	}
	else if(n==1){
		return 1;
	}												TOP DOWN APPROACH
	if(dp[n]!=-1){
		return dp[n];
	}
	else{
		dp[n]=fib(n-1)+fib(n-2);
		return dp[n];
	}
}*/
ll dp[101];

ll fib(int n){
	for(int i=2; i<=n; i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
}

int main(){
	//memset(dp, -1,sizeof(dp));
	dp[0]=0;
	dp[1]=1;
	ll n;
	cin>>n;
	fib(n);
	cout<<dp[n]<<endl;
}