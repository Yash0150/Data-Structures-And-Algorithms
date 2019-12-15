#include<bits/stdc++.h>
using namespace std;
#define ll long long
//ll cnt=0;
/*ll money(ll A[501],ll i,ll target, ll n){
	if(target==0){
		return 1;
	}
	if(target<0 || i<0){
		//cout<<'a';
		return 0;
	}
	return money(A,i-1,target,n)+money(A,i,target-A[i],n);

}*/

/*ll money(ll A[501],ll dp[501][501],ll i,ll target, ll n){
	if(target==0){
		return 1;
	}
	if(target<0 || i<0){
		return 0;
	}
	if(dp[i][target]!=-1){
		return dp[i][target];
	}
	dp[i][target]=money(A,dp,i-1,target,n)+money(A,dp,i,target-A[i],n);
	return dp[i][target];
}*/

ll money(ll A[501],ll target, ll n){ 
    ll i, j, x, y;
    ll table[target+1][n]; 
      
    // Fill the enteries for 0 
    // value case (n = 0) 
    for (i = 0; i < n; i++) 
        table[0][i] = 1; 
  
    // Fill rest of the table entries  
    // in bottom up manner  
    for (i = 1; i < target + 1; i++) 
    { 
        for (j = 0; j < n; j++) 
        { 
            // Count of solutions including S[j] 
            x = (i-A[j] >= 0) ? table[i - A[j]][j] : 0; 
  
            // Count of solutions excluding S[j] 
            y = (j >= 1) ? table[i][j - 1] : 0; 
  
            // total count 
            table[i][j] = (x + y)%(1000000000 + 7); 
        } 
    } 
    return table[target][n - 1]; 
} 

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll A[501];
		for(int i=0; i<n; i++){
			cin>>A[i];
		}
		ll m;
		cin>>m;
		ll cnt=money(A,m,n);
		/*for(int i=0; i<n; i++){
			for(int j=1; j<=m; j++){
				cout<<dp[i][j]<<"	";
			}
			cout<<endl;
		}*/
		cout<<cnt<<endl;
	}
}	