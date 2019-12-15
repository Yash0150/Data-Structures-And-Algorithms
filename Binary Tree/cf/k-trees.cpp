#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007;
ll dp[102][102];
ll q=1;
ll cnt=0;

ll cal(ll n,ll k, ll d){
	if(n==0 & d==1){
		return 1;
	}
	if(n<=0){
		return 0;
	}
	if(n<d){
		return 0;
	}
	if(dp[n][d]!=-1){
		return dp[n][d];
	}
	dp[n][d]=0;
	for(ll i=1; i<=k; i++){
		ll x=n-i;
		if(i>=d){
			if(x>=0){
				dp[x][1]=cal(x,k,1)%MOD;
				dp[n][d]+=dp[x][1];
			}
		}
		else{
			if(x>=0){
				dp[x][d]=cal(x,k,d)%MOD;
				dp[n][d]+=dp[x][d];
			}
		}
		dp[n][d]%=MOD;
	}
	return dp[n][d];
}

int main(){
	ll n,k,d;
	memset(dp,-1,sizeof(dp));
	cin>>n>>k>>d;
	if(n==d){
		cout<<1;
		return 0;
	}
	if(n<d){
		cout<<0;
		return 0;
	}
	cout<<cal(n,k,d);
}