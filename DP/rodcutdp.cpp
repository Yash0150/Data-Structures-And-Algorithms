#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*ll maxProfit(ll A[101],int l){
	if(l==0){
		return 0;
	}
	ll sum=A[l];								//RECURSION...
	for(ll i=1; i<=l; i++){
		ll cost=A[i]+maxProfit(A,l-i);
		sum=max(sum,cost);
	}
	return sum;
}*/
ll dp[101];
/*ll maxProfit(ll A[101],int l){
	if(l==0){
		return 0;
	}
	if(dp[l]!=-1){
		return dp[l];
	}
	else{
		ll sum=A[l];								//TOP DOWN
		for(ll i=1; i<=l; i++){
			ll cost=A[i]+maxProfit(A,l-i);
			sum=max(sum,cost);
		}
		dp[l]=sum;
		return sum;
	}
}*/

ll maxProfit(ll A[101],ll l){
	dp[0]=0;
	for(ll i=1; i<=l; i++){
		ll cost=INT_MIN;
		for(ll j=1; j<=i; j++){            //BOTTOM UP
			cost=max(cost,A[j]+dp[i-j]);	 
		}
		dp[i]=cost;
	}
}

int main(){
	//memset(dp,-1,sizeof(dp));
	ll n,m;
	cin>>n>>m;
	ll A[101];
	A[0]=0;
	for(int i=1;i<n+1;i++){
		cin>>A[i];
	}
	//sum=A[n];
	maxProfit(A,n);
	/*for(int i=1;i<n+1;i++){
		cout<<dp[i]<<" ";
	}*/
	cout<<dp[n];
	//cout<<a;
}