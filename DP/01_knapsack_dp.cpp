#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int print(int val[],int wht[],int n,int W){
	if(wht==0){
		return 0;
	}
	if(wht<0 || (wht>0 && n==0)){
		return 0;
	}
	if(dp[n][W]!=-1){
		return dp[n][W];
	}
	if(wht[n-1]<=W){
		return dp[n][W]=max(val[n-1] + print(val,wht,n-1,W-wht[n-1]),print(val,wht,n-1,W));
	}
	if(wht[n-1]>W){
		return dp[n][W]=print(val,wht,n-1,W);
	}
}

/* A Naive recursive implementation of 0-1 Knapsack problem */
/*#include <bits/stdc++.h> 
using namespace std; 

// A utility function that returns maximum of two integers 
int max(int a, int b) { return (a > b)? a : b; } 

// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
	
// Base Case 
if (n == 0 || W == 0) 
	return 0; 

// If weight of the nth item is more 
// than Knapsack capacity W, then 
// this item cannot be included 
// in the optimal solution 
if (wt[n-1] > W) 
	return knapSack(W, wt, val, n-1); 

// Return the maximum of two cases: 
// (1) nth item included 
// (2) not included 
else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), 
					knapSack(W, wt, val, n-1) ); 
} 
*/
// Driver code 
/*int main() 
{ 
	int val[] = {60, 100, 120}; 
	int wt[] = {10, 20, 30}; 
	int W = 50; 
	int n = sizeof(val)/sizeof(val[0]); 
	cout<<knapSack(W, wt, val, n); 
	return 0; 
} 

// This code is contributed by rathbhupendra 

*/
int main(){
	int n,W;
	cin>>n>>W;

	int val[n];
	for(int i=0; i<n; i++){
		cin>>val[i];
	}
	int wht[n];
	for(int i=0; i<n; i++){
		cin>>wht[i];
	}
	memset(dp,-1,sizeof(dp));
	//int profit=0;
	int ans=print(val,wht,n,W);
	cout<<dp[n][W];
}