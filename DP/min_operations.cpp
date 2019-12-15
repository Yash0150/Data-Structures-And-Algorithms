#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll inf=INT_MAX;

/*int func(int n){
	if(n==1){
		return 0;
	}
	ll x=inf,y=inf,z=inf;
	if(n%3==0) x=1+func(n/3);
	if(n%2==0) y=1+func(n/2);						//RECURSIVE APPROACH
	z=1+ func(n-1);
	return min(x,min(y,z));
}*/

int dp[1001];

/*int func(int n){
	if(n==1){
		return 0;
	}
	if(dp[n]!=-1){
		return dp[n];								//TOP DOWN APPROACH
	}
	else{
		ll x=inf,y=inf,z=inf;
		if(n%3==0) x=func(n/3);
		if(n%2==0) y=func(n/2);
		z=func(n-1);
		dp[n]=min(x,min(y,z))+1;
		return dp[n];
	}
}
*/
int func(int n){
	for(int i=4; i<=n; i++){
		ll x=inf,y=inf,z=inf;
		if(i%3==0) x=dp[i/3];
		if(i%2==0) y=dp[i/2];
		z=dp[i-1];
		dp[i]=1+min(x,min(y,z));
		//cout<<x<<" "<<y<<" "<<z<<endl;
	}
}

int main(){
	dp[0]=0;
	dp[1]=0;										//BOTTOM UP APPROACH
	dp[2]=1;
	dp[3]=1;
	//memset(dp,-1,sizeof(dp));
	ll n;
	cin>>n;
	func(n);
	cout<<dp[n];
}