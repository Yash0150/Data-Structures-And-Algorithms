#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool money(ll A[10001],ll i,ll target,ll n){
	if(target==0){
		return true;
	}
	if(target<0 || i<0){
		return false;
	}
	bool x=money(A,i-1,target-A[i],n);
	bool y=money(A,i-1,target,n);

	return x || y;
}

int main(){
	ll n;
	cin>>n;
	ll target;
	cin>>target;
	ll A[10001];
	for(ll i=0; i<n; i++){
		cin>>A[i];
	}
	bool ans=money(A,n-1,target,n);
	if(ans==true){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
}