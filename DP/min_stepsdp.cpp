#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*ll steps(int n){
	if((n)>=1 && (n)<=3 ){
		return 1;
	}
	else{												RECURSION APPROACH
		int x=1+steps(n-1);
		int y=1+steps(n-2);
		int z=1+steps(n-3);
		return min(x,min(z,y));
	}

}*/

ll dp[1001];

/*int steps(int n){
	if((n)>=1 && (n)<=3 ){
		return 1;
	}
	else if(dp[n]!=-1){
		return dp[n];                                 TOP DOWN APPROACH
	}
	else{							
		int x=1+steps(n-1);
		int y=1+steps(n-2);
		int z=1+steps(n-3);
		dp[n]= min(x,min(z,y));
		return dp[n];
	}
}*/

ll steps(ll n){
	for(ll i=4;i<=n; i++){
		dp[i]=1+min(dp[n-1],min(dp[n-2],dp[n-3]));				//BOTTOM UP APPROACH
	}
}

int main(){
	//memset(dp,-1,sizeof(dp));
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	ll n;
	cin>>n;
	steps(n);
	cout<<dp[n];
}