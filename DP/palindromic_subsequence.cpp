#include<bits/stdc++.h>
using namespace std;
int dp[100][100];


/*int print(string s,int i,int j){
	if(i>j){
		return 0;
	}
	if(i==j){
		return 1;
	}
	if(s[i]==s[j]){
		return 2+print(s,i+1,j-1);
	}
	else{
		return max(print(s,i+1,j),print(s,i,j-1));
	}
}*/

int print(string s,int n){
	for(int i=0; i<n; i++){
		dp[i][i]=1;
	}
	for(int j=1; j<n; j++){
		for(int i=j-1; i>=0; i--){
			if(s[i]==s[j]){
				dp[i][j]=2+dp[i+1][j-1];
			}
			else{
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	return dp[0][n-1];
}

int main(){
	string s="agdbda";
	//cin>>s;
	memset(dp,-1,sizeof(dp));
	print(s,s.size());
	for(int i=0; i<s.size(); i++){
		for(int j=0; j<s.size(); j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}