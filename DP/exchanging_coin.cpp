#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll money(ll n){
	if(n==1){
		return 1;
	}
	if(n<1){
		return 0;
	}
	ll x=money(n/2);
	ll y=money(n/3);
	ll z=money(n/4);
	return max(x+y+z,n);
}

int main(){
	ll n;
	cin>>n;
	ll ans=money(n);
	cout<<ans;
}