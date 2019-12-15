#include<bits/stdc++.h>
using namespace std;
#define ll long long
string o1="";
int lcs(string s,string o,int i,int j, int n,int m){
	if(i==n || j==m){
		return 0;
	}
	if(s[i]==o[j]){
		o1=o1+"a";
		int x=1+lcs(s,o,i+1,j+1,n,m);
		//int y=lcs(s,o,i+1,j,n,m);
		return x;
	}
	else{
		int x=lcs(s,o,i,j+1,n,m);
		int y=lcs(s,o,i+1,j,n,m);
		return max(x,y);
	}
}
/*int dp[101][101];
int lcs(string s,string o,int i,int j, int n,int m){
	if(i==n || j==m){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	if(s[i]==o[j]){
		int x=1+lcs(s,o,i+1,j+1,n,m);
		//int y=lcs(s,o,i+1,j,n,m);
		dp[i][j]=x;
		return x;
	}
	else{
		int x=lcs(s,o,i,j+1,n,m);
		int y=lcs(s,o,i+1,j,n,m);
		dp[i][j]=max(x,y);
		return max(x,y);
	}
}
*/
/*int lcs(string s,string o,string o1,int i,int j, int n,int m){
	dp[0][0]=0;
	for(int i=0; i<n; i++){
		dp[i][0]=0;
	}
	for(int i=0; i<m; i++){
		dp[0][i]=0;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m;j++){
			if(s[i]==o[j]){
				int x=1+dp[i-1][j-1];
				o1=o1+s[i];
				dp[i][j]=x;
			}
			else{
				int x=dp[i][j-1];
				int y=dp[i-1][j];
				dp[i][j]=max(x,y);
			}
		}
	}
	return o1;
}*/

int main(){
	//memset(dp,-1,sizeof(dp));
	string s,o,o1;
	cin>>s>>o;
	int n=s.size();
	int m=o.size();
	int ans=lcs(s,o,0,0,n,m);
	cout<<o1;
}