/*#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll drop(ll n,ll k){
	if(k==1 || k==0){
		return k;
	}
	if(n==1){
		return k; 
	}
	ll min=INT_MAX;
	for(int i=1; i<=k; i++){
		int ans=max(drop(n-1,i-1),drop(n,k-i));
		if(ans<min){
			min=ans;
		}
	}
	return min+1;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		cout<<drop(n,k)<<endl;
	}
}*/
int plateDrop(int n, int k) 
{ 
    /* A 2D table where entery eggFloor[i][j] will represent minimum 
       number of trials needed for i eggs and j floors. */
    int eggFloor[n+1][k+1]; 
    int res; 
    int i, j, x; 
  
    // We need one trial for one floor and0 trials for 0 floors 
    for (i = 1; i <= n; i++) 
    { 
        eggFloor[i][1] = 1; 
        eggFloor[i][0] = 0; 
    } 
  
    // We always need j trials for one egg and j floors. 
    for (j = 1; j <= k; j++) 
        eggFloor[1][j] = j; 
  
    // Fill rest of the entries in table using optimal substructure 
    // property 
    for (i = 2; i <= n; i++) 
    { 
        for (j = 2; j <= k; j++) 
        { 
            eggFloor[i][j] = INT_MAX; 
            for (x = 1; x <= j; x++) 
            { 
                res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]); 
                if (res < eggFloor[i][j]) 
                    eggFloor[i][j] = res; 
            } 
        } 
    } 
  
    // eggFloor[n][k] holds the result 
    return eggFloor[n][k]; 
} 
  
/* Driver program to test to pront printDups*/
int main() 
{ 	
	int t;
	cin>>t;
	while(t--){
	    int n,k;
    	cin>>n>>k;
    	cout<<platedrop(n,k)<<endl;
    }
}