#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000]={0};

int sum(int A[], int s, int e){
	int ans=0;
	for(int i=s; i<=e; i++){
		ans+=A[i];
	}
	return ans;
}

int print(int freq[], int num[], int n){
	for(int i=0; i<n; i++){
		dp[i][i]=freq[i];
	}

	for(int j=1; j<n; j++){
		for(int i=j+1; i>=0; i--){
			int l= i-j+1;
			int bst=0;
			for(int k=0; k<l; k++){
				int b=sum(freq,i,k-1)+sum(freq,k+1,j);
				bst=min(b,bst);
			}
			dp[i][j]=sum(freq, i, j)+ bst;
		}
	}
	return dp[0][n-1];
}

int main(){
	int n;
	cin>>n;
	int num[n];
	int freq[n];
	for(int i=0; i<n; i++){
		cin>>num[i];
	}
	for(int i=0; i<n; i++){
		cin>>freq[i];
	}
	int ans= print(freq,num,n);
	/*for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<ans;
}