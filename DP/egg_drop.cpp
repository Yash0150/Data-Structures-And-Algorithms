#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int print(int n,int k){
	if(k==0 || k==1){
		return k;
	}
	if(n==1){
		return k;
	}
	if(dp[n][k]!=-1){
		return dp[n][k];
	}
	int ans=INT_MAX,res;

	for(int x=1; x<=k; x++){
		res = max(1+print(n-1, x-1),1+ print(n, k-x)); 
        if (res < ans) 
            ans = res; 
	}
	dp[n][k]=ans;
	return ans;

}

int main(){
	int n=2,k=36;
	memset(dp,-1,sizeof(dp));
	//n=num of egg and k=floor
	//cin>>n>>k;
	cout<<print(n,k);
}