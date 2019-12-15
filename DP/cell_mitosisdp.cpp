#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll inf=INT_MAX;
ll dp[100001];
/*ll mitosis(ll n,ll x,ll y,ll z){
	if(n<0){
		return inf;
	}
	if(n==1){
		return 0;
	}
	if(dp[i]!=-1){
		return dp[i];
	}
	ll a=inf,c=inf;
	if(n&1==0) a=min(x+mitosis(n/2,x,y,z),y+mitosis(n-1,x,y,z));
	else c=min(y+mitosis(n-1,x,y,z),z+x+mitosis((n+1)/2,x,y,z));
	dp[i]=min(a,c);
	return dp[i];
}*/

ll mitosis(ll n,ll x,ll y,ll z){
	dp[0]=0;
	dp[1]=0;

	for(ll i=2; i<=n; i++){
		if(i%2==0) dp[i]=min(x+dp[i/2],y+dp[i-1]);
		else dp[i]=min(y+dp[i-1],z+x+dp[(i+1)/2]);
	}
	return dp[n];
}

int main(){
	ll n;
	cin>>n;
	ll x,y,z;
	cin>>x>>y>>z;
	ll ans=mitosis(n,x,y,z);
	cout<<ans;
}