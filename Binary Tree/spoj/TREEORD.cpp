#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll flag=0;
ll search(ll arr[], ll x, ll n) 
{ 
	for (int i = 0; i < n; i++) 
		if (arr[i] == x) 
			return i; 
	return -1; 
} 

void cal(ll pre[],ll post[],ll in[], ll n){
	ll root = search(in, pre[0], n); 
	if(pre[0]!=post[n-1]){
		flag=1;
		return;
	}
	if (root != 0){
		cal(pre+1,post,in, root); 
	}
	if (root != n - 1) {
		cal(pre + root + 1,post+root,in + root + 1, n - root - 1); 
	}
}

int main(){
	ll n;
	cin>>n;
	ll pre[n],in[n],post[n];
	for(ll i=0; i<n; i++){
		cin>>pre[i];
	}
	for(ll i=0; i<n; i++){
		cin>>post[i];
	}
	for(ll i=0; i<n; i++){
		cin>>in[i];
	}
	cal(pre,post,in,n);
	if(flag==0){
		cout<<"yes";
	}
	else{
		cout<<"no";
	}
}