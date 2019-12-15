#include<bits/stdc++.h>
using namespace std;

int main(){
	string s="abcdxyz",x="xyzabcd";
	//cin>>s>>x;
	int n=s.size();
	int m=x.size();
	int dp[n][m]={0};
	for(int i=0; i<m; i++){
		if(s[0]==x[i]){
			dp[0][i]=1;
		}
	}
	for(int i=0; i<n; i++){
		if(s[i]==x[0]){
			dp[i][0]=1;
		}
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(s[i]==x[j]){
				dp[i][j]=1+dp[i-1][j-1];
			}
		}
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	///FIND MAX OF ARRAY
}