#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=15;
	//cin>>n;
	int dp[n+1]={0};
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	for(int i=3; i<=n; i++){
		for(int j=1; j<=i; j++){
			dp[i]+=(dp[j-1]*dp[i-j]);
		}
	}
	for(int i=0; i<=n; i++){
		cout<<dp[i]<<" ";
	}
}

//USING CATALAN NUMBER   |||||

/*Total number of possible Binary Search Trees with n different keys (countBST(n)) = Catalan number Cn = (2n)! / ((n + 1)! * n!)

For n = 0, 1, 2, 3, … values of Catalan numbers are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …. So are numbers of Binary Search Trees.

Total number of possible Binary Trees with n different keys (countBT(n)) = countBST(n) * n! 
*/