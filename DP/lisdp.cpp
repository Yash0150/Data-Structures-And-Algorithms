#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lis(ll A[101],ll B[101],ll C[101],ll i,ll n){
	B[0]=1;
	for(int i=1; i<n; i++){
		ll best=0;
		for(int j=0; j<i; j++){
			if(A[i]>A[j]){                    //FOR INC DEC FIRST FIND MAX INC AND MAX DEC AND THEN ADD.
				best=max(best,1+B[j]);
			}
		}
		best=(best==0)?1:best;
		B[i]=best;
	}
	//best=0;
	C[n-1]=1;
	for(int i=n-2; i>=0; i--){
		ll best=0;
		for(int j=n-1; j>i; j--){
			if(A[i]>A[j]){                    //FOR INC DEC FIRST FIND MAX INC AND MAX DEC AND THEN ADD.
				best=max(best,1+C[j]);
			}
		}
		best=(best==0)?1:best;
		C[i]=best;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll A[101];
		ll B[101]={0};
		ll C[101]={0};
		for(ll i=0; i<n; i++){
			cin>>A[i];
		}
		//cout<<endl;
		lis(A,B,C,0,n);
		for(int i=0; i<n; i++){
			C[i]=C[i]+B[i]-1;
		}
		ll ans=INT_MIN;
		for(int i=0; i<n; i++){
			ans=max(ans,C[i]);
		}
		cout<<ans<<endl;
	}
}	