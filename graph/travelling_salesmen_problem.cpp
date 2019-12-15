#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[16][4];
int n=4;
int dis[10][10]={
	{0,20,42,25},
	{20,0,30,24},
	{42,30,0,10},
	{25,34,10,0},
};
int visited_all=(1<<n)-1;

int tsp(int mask,int pos){
	if(mask==visited_all){
		return dis[pos][0];
	}

	if(dp[mask][pos]!=-1){
		return dp[mask][pos];
	}

	int ans=INT_MAX;

	for(int city=0; city<n; city++){
		if((mask&(1<<city))==0){
			int newAns= dis[pos][city] + tsp((mask|(1<<city)), city);
			ans=min(ans,newAns);
		}
	}

	return dp[mask][pos]=ans;
}

int main(){
	for(int i=0; i<16; i++){
		for(int j=0; j<4; j++){
			dp[i][j]=-1;
		}
	}
	cout<<tsp(1,0);
}